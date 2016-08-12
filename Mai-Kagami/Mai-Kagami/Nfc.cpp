#include "Nfc.h"

#define PORT 9999	//ポート番号


//NFC管理用クラスコンストラクタ
void Nfc::Init() {
	id = 0;
	//自身を指すIPアドレス(127.0．0.1)を設定
	Ip.d1 = 127;
	Ip.d2 = 0;
	Ip.d3 = 0;
	Ip.d4 = 1;

	//通信を確立
	NetHandle = ConnectNetWork(Ip, PORT);

	if (NetHandle == -1)
		exit(-1);
}

//ユーザーIDの取得
int Nfc::GetId() {
//取得していない受信データ量を得る
	DataLength = GetNetWorkDataLength(NetHandle);
	//取得していない受信データ量が0じゃない場合はループを抜ける
	if (DataLength != 0) {
		//データ受信
		NetWorkRecv(NetHandle, StrBuf, DataLength);	//データをバッファに取得

		//受信したデータをidを返す
		printfDx("%s", StrBuf);
		//接続を断つ
		CloseNetWork(NetHandle);
	}

	int temp = id;
	return temp;
}

//接続
bool Nfc::Connect(const char* IP, u_short port)
{
	//sockaddr_in 構造体のセット
	struct sockaddr_in dstAddr;
	memset(&dstAddr, 0, sizeof(dstAddr));
	dstAddr.sin_port = htons(PORT);
	dstAddr.sin_family = AF_INET;
	dstAddr.sin_addr.s_addr = inet_addr(IP);

	//ソケットの生成
	m_DstSocket = socket(AF_INET, SOCK_STREAM, 0);

	// 接続
	if (connect(m_DstSocket, (struct sockaddr *) &dstAddr, sizeof(dstAddr))
		== SOCKET_ERROR) {
		return false;
	}
	// ソケットを非同期モードにする
	u_long val = 1;
	ioctlsocket(m_DstSocket, FIONBIO, &val);
	return true;
}

//受信
RECVSTATUS Nfc::Recv(char* pData, int DataSize, int *pRecvSize)
{
	int n = recv(m_DstSocket, pData, DataSize, 0);
	if (n < 1) {
		// データが来ていない
		if (WSAGetLastError() == WSAEWOULDBLOCK) {
			return RECV_STILL;
			// 切断orエラー
		} else {
			return RECV_FAILED;
		}
	}
	*pRecvSize = n;	// 受信データ長取得
	return RECV_SUCCESSED;
}