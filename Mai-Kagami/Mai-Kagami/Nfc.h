#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <WinSock2.h>
#include <Ws2tcpip.h>
#include "DxLib.h"
#pragma comment(lib, "ws2_32.lib")

#ifndef _RECVSTATUS_
#define _RECVSTATUS_

//受信状態
enum RECVSTATUS
{
	RECV_STILL,		//データが来ていない
	RECV_SUCCESSED,	//成功
	RECV_FAILED		//切断orエラー
};

#endif

class Nfc 
{
public:
	//初期化
	void Init();
	//ユーザーIDの取得
	char* GetId();
	//ソケットとの接続
	bool Connect(const char* Ip, u_short Port);	
	//受信
	RECVSTATUS Recv(char* pData, int DataSize, int *pRecvSize);
private:
	SOCKET m_DstSocket;
};

#endif