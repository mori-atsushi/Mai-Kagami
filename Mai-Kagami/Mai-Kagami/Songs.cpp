#include "Songs.h"

// �Ȑ�
#define NUMSONGS 256

LPBYTE ReadData(HINTERNET hRequest, LPDWORD lpdwSize);

Songs::Songs(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	int id = 0;
	while (FileRead_scanf(file, "%d,%[^,\n\r],%[^,\n\r],%[^\n\r]", &id, buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, id, buf[1], buf[2], buf[0]);
		n++;
	}
	FileRead_close(file);
}

// �Ȑ��擾
int Songs::GetSongNum() {
	return n;
}

// �Ȏ擾
Song *Songs::GetSong(int x) {
	return song[x];
}

// ���ݑI������Ă���Ȏ擾
int Songs::GetNowSong() {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetNow() == 0)
			return i;
	}
	return 0;
}

LPBYTE ReadData(HINTERNET hRequest, LPDWORD lpdwSize)
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
// 			if (lpPrev != NULL) {
// 				CopyMemory(lpData, lpPrev, dwTotalSizePrev);
// 				HeapFree(GetProcessHeap(), 0, lpPrev);
// 			}
			WinHttpReadData(hRequest, lpData + dwTotalSizePrev, dwSize, NULL);
			lpPrev = lpData;
		} else
			break;
	}

	*lpdwSize = dwTotalSize;

	return lpData;
}

int Songs::LoadHistory(const char *userId) {
	// �����ŃT�[�o�ɐڑ����đO��ƑO�X��̓_������M
	HINTERNET      hSession, hConnect, hRequest;
	URL_COMPONENTS urlComponents;
	WCHAR          szHostName[256], szUrlPath[2048];
	// URL
	WCHAR          szUrl[256] = L"http:// globalstudios.jp/mai-archive/api_history.php?user=";
	WCHAR		   szUserId[18];
// 	printfDx("%d, %d, %d, %d, %d, %d, %d, %d\n", userId[0], userId[1],userId[2],userId[3],userId[4],userId[5], userId[6], userId[7]);
// 	printfDx("%d, %d, %d, %d, %d, %d\n", 'd', 'a', 'i', 'c', 'h', 'i');
	mbstowcs(szUserId, userId, 256);
	wcscat(szUrl, szUserId);
	LPBYTE         lpData;
	DWORD          dwSize;

	hSession = WinHttpOpen(L"Sample Application/1.0",
		WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
		WINHTTP_NO_PROXY_NAME,
		WINHTTP_NO_PROXY_BYPASS,
		0);
	if (hSession == NULL)
		return -1;

	ZeroMemory(&urlComponents, sizeof(URL_COMPONENTS));
	urlComponents.dwStructSize = sizeof(URL_COMPONENTS);
	urlComponents.lpszHostName = szHostName;
	urlComponents.dwHostNameLength = sizeof(szHostName) / sizeof(WCHAR);
	urlComponents.lpszUrlPath = szUrlPath;
	urlComponents.dwUrlPathLength = sizeof(szUrlPath) / sizeof(WCHAR);


	if (!WinHttpCrackUrl(szUrl, lstrlenW(szUrl), 0, &urlComponents)) {
		WinHttpCloseHandle(hSession);
		return -1;
	}

	// �ڑ�
	hConnect = WinHttpConnect(hSession, szHostName, INTERNET_DEFAULT_PORT, 0);
	if (hConnect == NULL) {
		WinHttpCloseHandle(hSession);
		return -1;
	}

	hRequest = WinHttpOpenRequest(hConnect,
		L"GET",
		szUrlPath,
		NULL,
		WINHTTP_NO_REFERER,
		WINHTTP_DEFAULT_ACCEPT_TYPES,
		0);
	if (hRequest == NULL) {
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return -1;
	}

	if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, WINHTTP_IGNORE_REQUEST_TOTAL_LENGTH, 0)) {
		WinHttpCloseHandle(hRequest);
		WinHttpCloseHandle(hConnect);
		WinHttpCloseHandle(hSession);
		return 0;
	}

	WinHttpReceiveResponse(hRequest, NULL);

	// �{�f�B�擾
	lpData = ReadData(hRequest, &dwSize);
// 	printfDx((char*)lpData);
	for (int i = 0; i < NUMSONGS; i++) {
		char* temp = NULL;
		char* ctx;// �����I�Ɏg�p����̂Ő[���l���Ȃ�

		if (i == 0) {
			temp = strtok_s((char*)lpData, "\n", &ctx);

		} else {
			temp = strtok_s(0, "\n", &ctx);
		}
		if (temp == NULL)break;
		int history[2];
		int hoge;
		sscanf_s(temp, "%d||%d||%d", &hoge, &history[0], &history[1]);
		// �ȉ��̎������s���邱�Ƃɂ���ăf�[�^��ۑ�
		// song[Search(<��ID>)]->songHistory->Set(���O��ƑO�X��̓_���i�z��|�C���^�j��);
		song[Search(hoge)]->songHistory->Set(history);
	}
	HeapFree(GetProcessHeap(), 0, lpData);

	WinHttpCloseHandle(hRequest);
	WinHttpCloseHandle(hConnect);
	WinHttpCloseHandle(hSession);

	return 0;
}

int Songs::Search(const int songId) {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetSongId() == songId)
			return i;
	}
	return -1;
}