#include "Nfc.h"

#define PORT 9999;	//ポート番号


//NFC管理用クラスコンストラクタ
void Nfc::Init() {
	id = 0;
	auto thd = std::thread(&Nfc::CheckThread, this);
	thd.detach();
}

//ユーザーIDの取得
int Nfc::GetId() {
	int temp = id;
	return temp;
}

//NFCをチェックするためのスレッド
void Nfc::CheckThread() {
	WaitKey();
	id = 1;	//取得したidを返す
}