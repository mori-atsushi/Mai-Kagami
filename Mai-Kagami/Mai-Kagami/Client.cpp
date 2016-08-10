#include "Client.h"

//コンストラクタ
CClient::CClient() :m_DstSocket(INVALID_SOCKET)
{
	//Windowsの場合
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
}

//デストラクタ
CClient::~CClient() {
	if (m_DstSocket != INVALID_SOCKET)
		closesocket(m_DstSocket);
	//Windows でのソケットの終了
	WSACleanup();
}

//接続
bool CClient::Connect(const char* IP, u_short PORT)
{
	//sockaddr_in 構造体のセット
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(PORT);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(IP);

	//ソケットの生成
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	//接続
	if (connect(m_DstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {

	}
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