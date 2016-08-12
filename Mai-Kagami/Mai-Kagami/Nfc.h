#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <thread>
#include"DxLib.h"

class Nfc 
{
public:
	void Init();	//初期化
	int GetId();	//ユーザーIDの取得

private:
	IPDATA Ip;			//接続用IPアドレスデータ
	int id;				//取得したID
	int NetHandle;		//ネットワークハンドル
	int DataLength;		//受信データ量保存用変数
	char StrBuf[256];	//データバッファ
};

#endif