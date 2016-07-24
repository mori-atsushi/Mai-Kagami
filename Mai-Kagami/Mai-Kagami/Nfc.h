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
};

#endif