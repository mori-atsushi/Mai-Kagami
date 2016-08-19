#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <WinSock2.h>
#include <Ws2tcpip.h>
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
	int GetId();
	//ソケットとの接続
	bool Connect(const char* IP, u_short PORT);	
private:
	SOCKET m_DstSocket;
};

#endif