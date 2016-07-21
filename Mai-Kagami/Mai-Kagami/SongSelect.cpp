#include "SongSelect.h"

//曲選択画面タイトルロード
void SongSelectTitle::Init() {
	int strLen; //文字列の長さ

	str = "Song Select"; //表示文字列
	font.Set(50); //フォントサイズセット
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	x = WIDTH / 2 - strLen / 2;
	y = HEIGHT * 0.2;
}

//曲選択画面タイトル表示
void SongSelectTitle::View() {
	Color color;

	DrawStringToHandle(x, y, str, color.White(), font.Get()); //文字表示
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
	songSelectTitle.View();
}

//曲選択画面画像ロード
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //曲選択画面タイトル初期化
	Sleep(10000);
	loadFlag = 2;
}