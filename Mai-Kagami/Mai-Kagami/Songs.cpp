#include "Songs.h"

Songs::Songs(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	int id = 0;
	while (FileRead_scanf(file, "%d,%[^,\n\r],%[^,\n\r],%[^\n\r]", &id, buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, id, buf[1], buf[2], buf[0]);
		n++;
	}
	FileRead_close(file);
}

//曲数取得
int Songs::GetSongNum() {
	return n;
}

//曲取得
Song *Songs::GetSong(int x) {
	return song[x];
}

//現在選択されている曲取得
int Songs::GetNowSong() {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetNow() == 0)
			return i;
	}
	return 0;
}

//履歴ロード
void Songs::LoadHistory(const char *userId) {
	//ここでサーバに接続して前回と前々回の点数を受信
	//以下の式を実行することによってデータを保存
	//song[Search(<曲ID>)]->songHistory->Set(＜前回と前々回の点数（配列ポインタ）＞);

	int history[3][2] = { { 22, -1 },{ 44, 55 },{ 66, 77 } };
	for (int i = 0; i < 3; i++)
		song[Search(i + 1)]->songHistory->Set(history[i]);
}

int Songs::Search(const int songId) {
	for (int i = 0; i < n; i++) {
		if (song[i]->GetSongId() == songId)
			return i;
	}
	return -1;
}