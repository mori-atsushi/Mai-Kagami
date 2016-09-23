#ifndef _HTTP_H_INCLUDE_
#define _HTTP_H_INCLUDE_

#include <Windows.h>
#include <winhttp.h>
#include <wchar.h>
#include <string>
#include "DxLib.h"

#pragma comment(lib, "winhttp.lib")

#define URLBUFFER_SIZE		(4096)
#define	READBUFFER_SIZE		(4096)

using namespace std;
class Http {
public:
	Http();
	bool Send(WCHAR szUrl[]);

private:
	HINTERNET hSession;
	LPBYTE ReadData(HINTERNET hRequest, LPDWORD lpdwSize);
};
#endif