#include "Http.h";

Http::Http() {
	this->hSession = WinHttpOpen(
		L"Sample Application/1.0", 
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS,0);
}


bool Http::Send(WCHAR szUrl[]) {
	if (this->hSession == NULL) return false;

	HINTERNET		hConnect, hRequest;
	URL_COMPONENTS	urlComponents;
	WCHAR			szHostName[256], szUrlPath[2048];
	LPBYTE			lpHeader, lpData;
	DWORD			dwSize;

	ZeroMemory(&urlComponents, sizeof(URL_COMPONENTS));
	urlComponents.dwStructSize = sizeof(URL_COMPONENTS);
	urlComponents.lpszHostName = szHostName;
	urlComponents.dwHostNameLength = sizeof(szHostName) / sizeof(WCHAR);
	urlComponents.lpszUrlPath = szUrlPath;
	urlComponents.dwUrlPathLength = sizeof(szUrlPath) / sizeof(WCHAR);

	if (!WinHttpCrackUrl(szUrl, lstrlenW(szUrl), 0, &urlComponents)) {
		WinHttpCloseHandle(hSession);
		return false;
	}

	hConnect = WinHttpConnect(hSession, szHostName, INTERNET_DEFAULT_PORT, 0);
	if (hConnect == NULL) {
		WinHttpCloseHandle(hSession);
		return false;
	}
	
	hRequest = WinHttpOpenRequest(hConnect, L"GET", szUrlPath, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
	if (hRequest == NULL) {
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return false;
	}


	if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH, 0)) {
		WinHttpCloseHandle(hRequest);
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return false;
	}
	WinHttpReceiveResponse(hRequest, NULL);

	dwSize = 0;
	lpData = ReadData(hRequest, &dwSize);
	HeapFree(GetProcessHeap(), 0, lpData);

	WinHttpCloseHandle(hRequest);
	WinHttpCloseHandle(hConnect);
	WinHttpCloseHandle(hSession);

	return true;
}

bool Http::Send(char url[]) {
	WCHAR szUrl[512] = { 0 };
	mbstowcs(szUrl, url, 512);
	return Http::Send(szUrl);
}

LPBYTE Http::ReadData(HINTERNET hRequest, LPDWORD lpdwSize)
{
	LPBYTE lpData = NULL;
	LPBYTE lpPrev = NULL;
	DWORD  dwSize;
	DWORD  dwTotalSize = 0;
	DWORD  dwTotalSizePrev = 0;

	for (;;) {
		WinHttpQueryDataAvailable(hRequest, &dwSize);
		if (dwSize > 0) {
			dwTotalSizePrev = dwTotalSize;
			dwTotalSize += dwSize;
			lpData = (LPBYTE)HeapAlloc(GetProcessHeap(), 0, dwTotalSize);
			if (lpPrev != NULL) {
				CopyMemory(lpData, lpPrev, dwTotalSizePrev);
				HeapFree(GetProcessHeap(), 0, lpPrev);
			}
			WinHttpReadData(hRequest, lpData + dwTotalSizePrev, dwSize, NULL);
			lpPrev = lpData;
		} else
			break;
	}

	*lpdwSize = dwTotalSize;

	return lpData;
}