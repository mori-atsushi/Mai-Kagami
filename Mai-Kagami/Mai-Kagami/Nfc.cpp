#include "Nfc.h"

#define PORT 9999		//ポート番号
#define IP "127.0.0.1"	//IP番号(ローカルホスト) 

void Nfc::Init() 
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
}

int Nfc::GetId()
{
	int recvsize;				//受信データ長
	char recvMessage[5] = {};	//受信ストリーム
	char data[256] = {};		//受信したIDを格納する変数

	//接続に失敗したときのエラー処理
	if (!Connect(IP, PORT)) {
		return -1;
	}

	//受信
	while (true) {
		RECVSTATUS status = Recv(
			recvMessage,		//受信データ格納用の配列 
			sizeof(recvsize),	//受信データ長
			&recvsize);			//受信データ長のポインタ
		switch (status) {
		case RECV_STILL:
			printfDx("0");
			continue;
		case RECV_SUCCESSED:
			printfDx("受け取りました:%s\n", data);
			strcat(data, recvMessage);
			continue;
		case RECV_FAILED:
			printfDx("受け取りに失敗しました\n");
			break;
		}
		break;
	}
	printfDx("受信データ:%s", data);

	return 1;
}

//接続
bool Nfc::Connect(const char* Ip, u_short Port)
{
	//sockaddr_in 構造体のセット
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(Port);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(Ip);

	//ソケットの生成
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	//接続
	if (connect(m_DstSocket, (struct sockaddr *) & dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {
		return false;
	}
	//ソケットを非同期モードにする
	u_long val = 1;
	ioctlsocket(m_DstSocket, FIONBIO, &val);
	return true;
}

//受信
RECVSTATUS Nfc::Recv(char* pData, int DataSize, int *pRecvSize) 
{
	int n = recv(m_DstSocket, pData, DataSize, 0);
	if (n < 1) {
		//データが来ていない
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			return RECV_STILL;
		//切断orエラー
		} else {
			return RECV_FAILED;
		}
	}
	*pRecvSize = n;	//受信データ長取得
	return RECV_SUCCESSED;
}