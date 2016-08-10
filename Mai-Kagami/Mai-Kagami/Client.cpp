#include "Client.h"

//コンストラクタ
CClient::CClient() :m_DstSocket(INVALID_SOCKET)
{
}

//デストラクタ
CClient::~CClient() {
}

//接続
bool CClient::Connect(const char* IP, u_short PORT)
{
	return true;
}

//受信
RECVSTATUS CClient::Recv(char* pData, int DataSize, int *pRecvSize)
{
	return RECV_SUCCESSED;
}

//送信
bool CClient::Send(char*pData, int DataSize)
{
	return true;
}