#include "Login.h"

//履歴セット
void SongHistory::Set(const int history[2]) {
	for (int i = 0; i < 2; i++)
		this->history[i] = history[i];
}

//履歴取得
void SongHistory::Get(int *history[2]) {
	for (int i = 0; i < 2; i++)
		*history[i] = this->history[i];
}

Login::Login() {
	for (int i = 0; i < 256; i++)
		songHistory[i] = new SongHistory();
}

//履歴ロード
void Login::LoadHistory(const char *userId) {
	//ここでサーバに接続して前回と前々回の点数を受信
	//以下の式を実行することによってデータを保存
	//songHistory[＜曲ID＞]->Set(＜前回と前々回の点数（配列ポインタ）＞);

	int history[3][2] = { {22, -1}, {44, 55}, {66, 77} };
	for(int i = 0; i < 3; i++)
		songHistory[i + 1]->Set(history[i]);
}

//履歴取得
void Login::GetHistory(const int songId, int *history[2]) {
	songHistory[songId]->Get(history);
}

Login::~Login() {
	for (int i = 0; i < 256; i++)
		delete songHistory[i];
}