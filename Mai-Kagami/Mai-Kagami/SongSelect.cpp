#include "SongSelect.h"

//曲選択画面タイトルロード
void SongSelectTitle::Init() {
	char *str = "Song Select"; //表示文字列
	myDrawText.Init(str, WIDTH / 2, HEIGHT * 0.2, 1, 70); //テキスト初期化
	myDrawLine.Init(WIDTH / 2, HEIGHT * 0.3, 1, 1000, 20); //線初期化
}

//曲選択画面タイトル表示
void SongSelectTitle::View() {
	myDrawText.Draw(); //テキスト表示
	myDrawLine.Draw(); //線表示
}

//曲選択画面ロード
int SongSelect::Load() {
	if (loadFlag == 0) {
		auto thd = std::thread(&SongSelect::LoadThread, this);
		thd.detach();
		loadFlag = 1;
	}
	if (loadFlag == 2)
		return SONG_SELECT;
	return LOGIN;
}

//曲選択画面計算
void SongSelect::Update() {
}

//曲選択画面表示
void SongSelect::View() {
	songSelectTitle.View(); //タイトル表示
}

//曲選択画面画像ロード
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //曲選択画面タイトル初期化
	Sleep(500);
	loadFlag = 2;
}