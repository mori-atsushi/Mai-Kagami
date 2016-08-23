#include "Songs.h"

//曲数
#define NUMSONGS 3

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

//曲数取得
int Songs::GetSongNum() {
	return n;
}

//曲取得
Song *Songs::GetSong(int x) {
	return song[x];
}

//現在選択されている曲取得
int Songs::GetNowSong() {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetNow() == 0)
			return i;
	}
	return 0;
}

//履歴ロード
//成功したら0,エラーならば-1を返す
int Songs::LoadHistory(const char *userId) {
	//ここでサーバに接続して前回と前々回の点数を受信
	HINTERNET      hSession, hConnect, hRequest;
	URL_COMPONENTS urlComponents;
	WCHAR          szHostName[256], szUrlPath[2048];
	//URL
	WCHAR          szUrl[] = L"http://globalstudios.jp/mai-archive/api_history.php?user=daichi";
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

	//接続
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

	//ボディ取得
	lpData = ReadData(hRequest, &dwSize);
	char* temp[NUMSONGS + 1] = {};
	temp[0] = strtok((char*)lpData, "\n");
	int i = 0;
	do {
		i++;
		temp[i] = strtok(NULL, "\n");  /* 2回目以降 */
	} while (temp[i] != NULL);

	int history[NUMSONGS][2] = {};
	int hoge = 0;
	for (int i = 0; i < NUMSONGS; i++) {
		sscanf(temp[i], "%d||%d||%d", &hoge, &history[i][0], &history[i][1]);
	}
	HeapFree(GetProcessHeap(), 0, lpData);

	WinHttpCloseHandle(hRequest);
	WinHttpCloseHandle(hConnect);
	WinHttpCloseHandle(hSession);

	//以下の式を実行することによってデータを保存
	//song[Search(<曲ID>)]->songHistory->Set(＜前回と前々回の点数（配列ポインタ）＞);

	//for (int i = 0; i < NUMSONGS; i++)
		//song[Search(i + 1)]->songHistory->Set(history[i]);

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

int Songs::Search(const int songId) {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetSongId() == songId)
			return i;
	}
	return -1;
}