#ifndef _CLIENT_H_
#define _CLIENT_H_

//WSAStartup	開始
//socket		ソケット作成
//connect		サーバに接続
//ioctlsocket	ソケット非同期化
//recv,send		データ送受信
//closesocket	ソケット閉じる
//WSACleanup	終了

#include <WinSock2.h>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#ifndef _RECVSTATUS_
#define _RECVSTATUS_

enum RECVSTATUS
{
	RECV_STILL,		//データが来ていない
	RECV_SUCCESSED,	//成功
	RECV_FAILED		//切断orエラー
};

#endif

class CClient
{
public:
	//コンストラクタ
	CClient();
	//デストラクタ
	virtual ~CClient();

	//接続
	bool Connect(const char* IP, u_short PORT);

	//受信
	RECVSTATUS Recv(char* pData, int DataSize, int* pRecvSize);
	//送信
	bool Send(char* pData, int DataSize);

private:
	SOCKET m_DstSocket;
};

#endif