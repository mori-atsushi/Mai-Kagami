#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <WS2tcpip.h>
#include <thread>
#include"DxLib.h"
#pragma comment(lib, "ws2_32.lib")

#ifndef _RECVSTATUS_
#define _RECVSTATUS_

//受信状態
enum RECVSTATUS
{
	RECV_STILL,		//データが来ていない
	RECV_SUCCESSED,	//成功
	RECV_FAILED,	//切断orエラー
};
#endif

class Nfc 
{
public:
	void Init();	//初期化
	int GetId();	//ユーザーIDの取得
private:
	IPDATA Ip;			//接続用IPアドレスデータ
	int id;
	int NetHandle;		//ネットワークハンドル
	int DataLength;		//受信データ量保存用変数
	char StrBuf[256];	//データバッファ
};

#endif