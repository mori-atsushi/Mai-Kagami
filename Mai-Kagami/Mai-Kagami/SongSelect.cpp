#include "SongSelect.h"

//曲選択画面タイトルロード
void SongSelectTitle::Init() {
	char *str = "Song Select"; //表示文字列
	myDrawText.Init(str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //テキスト初期化
	myDrawLine.Init(WIDTH * 0.65, HEIGHT * 0.24, 1, myDrawText.GetWidth() + 10, 20); //線初期化
}

//曲選択画面タイトル表示
void SongSelectTitle::View() {
	myDrawText.Draw(); //テキスト表示
	myDrawLine.Draw(); //線表示
}

//曲選択画面カバー画像初期化
void SongSelectCover::Init() {
	myDrawGraph.Init(WIDTH * 0.52, HEIGHT * 0.35, "song/Ghost_Rule/cover.jpg");
	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

//曲選択画面カバー画像表示
void SongSelectCover::View() {
	myDrawGraph.Draw();
}

//曲選択画面ボタン初期化
void SongSelectButton::Init() {
	char *str[4] = { "前の曲へ", "決定", "次の曲へ" }; //表示文字列
	myDrawText[0].Init(str[0], WIDTH * 0.94, BUTTON1_POS - HEIGHT * 0.0085, 2, 30);
	myDrawTriangle[0].Init(WIDTH * 0.97, BUTTON1_POS, WIDTH * 0.03, 0);
	myDrawText[1].Init(str[1], WIDTH * 0.94, BUTTON2_POS - HEIGHT * 0.0085, 2, 30);
	myDrawRing.Init(WIDTH * 0.97, BUTTON2_POS, WIDTH * 0.015, 7);
	myDrawText[2].Init(str[2], WIDTH * 0.94, BUTTON3_POS - HEIGHT * 0.0085, 2, 30);
	myDrawTriangle[1].Init(WIDTH * 0.97, BUTTON3_POS, WIDTH * 0.03, 1);
	finish.Init("終了", WIDTH * 0.955, BUTTON5_POS - HEIGHT * 0.0085, 1, 30);
	finishCircle.Init(WIDTH * 0.955, BUTTON5_POS, WIDTH * 0.042);
}

//曲選択画面ボタン表示
void SongSelectButton::View() {
	myDrawText[0].Draw();
	myDrawText[1].Draw();
	myDrawText[2].Draw();
	myDrawTriangle[0].Draw();
	myDrawTriangle[1].Draw();
	finishCircle.Draw();
	finish.Draw();
	myDrawRing.Draw();
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
	songSelectCover.View(); //カバー表示
	songSelectButton.View(); //ボタン表示
}

//曲選択画面画像ロード
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //曲選択画面タイトル初期化
	songSelectCover.Init(); //選択中の曲初期化
	songSelectButton.Init();
//	Sleep(5000);
	loadFlag = 2;
}