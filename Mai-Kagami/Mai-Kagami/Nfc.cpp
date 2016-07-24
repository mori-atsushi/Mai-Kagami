#include "Nfc.h"


//NFC管理用クラスコンストラクタ
Nfc::Nfc() {
	id = 0;
	auto thd = std::thread(&Nfc::CheckThread, this);
	thd.detach();
}

//ユーザーIDの取得
int Nfc::GetId() {
	int temp = id;
	id = 0;
	return temp;
}

//NFCをチェックするためのスレッド
void Nfc::CheckThread() {
	WaitKey();
	id = 1;
}