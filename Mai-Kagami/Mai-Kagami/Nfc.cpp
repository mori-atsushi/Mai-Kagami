#include "Nfc.h"
#include <stdio.h>
#include<iostream>
#include<fstream>

#define PORT 9999		//ポート番号
#define IP "127.0.0.1"	//IP番号(ローカルホスト) 

void Nfc::Init() 
{
	WSADATA data;
	WSAStartup(MAKEWORD(2, 0), &data);
}

char* Nfc::GetId()
{
	int recvsize;				//受信データ長
	char recvMessage[5] = {};	//受信バッファ
	char data[256] = "\0";		//受信したIDを格納する変数
	int result = 0;				//IDをint型にキャストしたもの
	int cont = 0;

	//呼び出された回数をカウント
	calledCont++;

	//接続に失敗したときのエラー処理
	//またnfc監視を初めてから1秒間の間は0を返す
	if (!Connect(IP, PORT) || calledCont < 10) {
		printfDx("%d ", calledCont);
		return data;
	}

	//受信
	//tcp/ip通信では4バイトごと送信される
	//つまり一回受信しただけでは完全に受信されていない可能性がある
	//なので何度か受信されたか確認することによって完全に受信させる
	while (true) {
		RECVSTATUS status = Recv(
			recvMessage,		//受信データ格納用の配列 
			sizeof(recvsize),	//受信データ長
			&recvsize);			//受信データ長のポインタ

		switch (status) {
		//データが来ていないとき
		case RECV_STILL:
			printfDx("0 ");
			continue;
		//成功
		case RECV_SUCCESSED:
			printfDx("1 ");
			strcat(data, recvMessage);
			printfDx(data);
			continue;
		//切断orエラー
		case RECV_FAILED:
			printfDx("2 ");
			break;
		}
		break;
	}

	return data;
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

void Nfc::reset_calledCont() { calledCont = 0; }