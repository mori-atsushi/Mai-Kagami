#include "Serial.h"

Serial::Serial() {
	//シリアル通信用ポートの確立 ("COM8")
	serialPort = CreateFile("COM3", GENERIC_WRITE | GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (serialPort == INVALID_HANDLE_VALUE)
	{
		printfDx("PORT COULD NOT OPEN\n");
	}
	Ret = SetupComm(serialPort, 1024, 1024);
	if (!Ret) {
		printfDx("SET UP FAILED\n");
		CloseHandle(serialPort);
	}
	Ret = PurgeComm(serialPort, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR);
	if (!Ret) {
		printfDx("CLEAR FAILED\n");
		CloseHandle(serialPort);
	}
	//基本通信条件の設定
	DCB dcb;
	GetCommState(serialPort, &dcb);
	dcb.DCBlength = sizeof(DCB);
	dcb.BaudRate = 9600;
	dcb.fBinary = FALSE;
	dcb.ByteSize = 8;
	dcb.fParity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;

	Ret = SetCommState(serialPort, &dcb);

	if (!Ret) {
		printfDx("SetCommState FAILED");
		CloseHandle(serialPort);
	}
}

char *Serial::GetData() {
	char data[1024] = "0";
	DWORD dwRead;
	DWORD dwSendSize;
	BYTE sendflag = 1;
	DWORD dwErrorMask;
	COMSTAT comStat;
	DWORD dwCount;
	TCHAR tdata[255];

	ClearCommError(serialPort, &dwErrorMask, &comStat);
	dwCount = comStat.cbInQue;
	WriteFile(serialPort, &sendflag, sizeof(sendflag), &dwSendSize, NULL);
	Ret = ReadFile(serialPort, &data, dwCount, &dwRead, NULL);
	if (!Ret) {
		printfDx("thread READ FAILED\n");
		CloseHandle(serialPort);
	}
	return data;
}

Serial::~Serial() {
	CloseHandle(serialPort);
}