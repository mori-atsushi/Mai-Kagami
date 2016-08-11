#ifndef __NFC_H_INCLUDED__
#define __NFC_H_INCLUDED__

#include <thread>
#include"DxLib.h"

class Nfc {
public:
	void Init();
	int GetId(); //ユーザーIDの取得
private:
	void CheckThread(); //NFCをチェックするためのスレッド
	int id;
	IPDATA Ip;	//接続用IPアドレスデータ
	int NetHandle;	//ネットワークハンドル
	int DataLength;	//受信データ量保存用変数
	char StrBuf[256];	//データバッファ
};

#endif