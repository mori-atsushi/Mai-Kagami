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

	//	auto thd = std::thread(&Nfc::CheckThread, this);
//	thd.detach();
}

//ユーザーIDの取得
int Nfc::GetId() {
	//printfDx("%d\n", NetHandle);
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

//NFCをチェックするためのスレッド
void Nfc::CheckThread() {


	//確立が成功した場合のみ中の処理をする
	if (NetHandle != -1)
	{
		//データが来るのを待つ
		while (!ProcessMessage())
		{
			printfDx("ok");
			//取得していない受信データ量を得る
			DataLength = GetNetWorkDataLength(NetHandle);

			//取得していない受信データ量が0じゃない場合はループを抜ける
			if (DataLength != 0) break;
		}



	}

	//WaitKey();
	//id = 1;	//取得したidを返す
}