#include "SongSelect.h"
/*
//曲選択画面タイトルロード
void SongSelectTitle::Init() {
	char *str = "Song Select"; //表示文字列
	myDrawText.Init(str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //テキスト初期化
	myDrawLine.Init(WIDTH * 0.65, HEIGHT * 0.236, 1, myDrawText.GetWidth() + 10, 20); //線初期化
}

//曲選択画面タイトル表示
void SongSelectTitle::View() {
	myDrawText.Draw(); //テキスト表示
	myDrawLine.Draw(); //線表示
}

//曲選択画面カバー画像初期化
void SongSelectCover::Init() {
	char *title = "ゴーストルール"; //表示文字列
	char *artist = "初音ミク / DECO*27";
	float x = HEIGHT * 0.35;
	myDrawGraph.Init(WIDTH * 0.52, x, "song/Ghost_Rule/cover.jpg");
	songTitle.Init(title, WIDTH * 0.8, HEIGHT * 0.29, 1, 36); //テキスト初期化
	songArtist.Init(artist, WIDTH * 0.96, HEIGHT * 0.32, 2, 20); //テキスト初期化
	songLast[0].Init("前回　： --点", WIDTH * 0.75, HEIGHT * 0.355, 0, 24); //テキスト初期化
	songLast[1].Init("前々回： --点", WIDTH * 0.75, HEIGHT * 0.38, 0, 24); //テキスト初期化
	myDrawLine.Init(WIDTH * 0.8, HEIGHT * 0.315, 1, WIDTH * 0.33, 6); //線初期化
	myDrawBox.Init(WIDTH * 0.52, HEIGHT * 0.5, 170, 1000);
	songCover[0].Init(WIDTH * 0.52, x - 180, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[1].Init(WIDTH * 0.52, x + 180, "song/Happy_Synthesizer/cover.jpg", 0.7);
	songCover[2].Init(WIDTH * 0.52, x + 330, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[3].Init(WIDTH * 0.52, x + 480, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[4].Init(WIDTH * 0.52, x + 630, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[5].Init(WIDTH * 0.52, x + 780, "song/Ghost_Rule/cover.jpg", 0.7);
	grad[0].Init(WIDTH * 0.52, HEIGHT * 0.22, "img/grad1.png");
	grad[1].Init(WIDTH * 0.52, HEIGHT * 0.8, "img/grad2.png");
	box.Init(WIDTH * 0.52, x, "img/box.png");
	//	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

//曲選択画面カバー画像表示
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox.Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	songCover[0].Draw();
	songCover[1].Draw();
	songCover[2].Draw();
	songCover[3].Draw();
	songCover[4].Draw();
	songCover[5].Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box.Draw();
	myDrawGraph.Draw();
	songTitle.Draw();
	songArtist.Draw();
	songLast[0].Draw();
	songLast[1].Draw();
	myDrawLine.Draw();
	grad[0].Draw();
	grad[1].Draw();
}

//曲選択画面ボタン初期化
void SongSelectButton::Init() {
	button[0].Init("前の曲へ", 1, 0);
	button[1].Init("決定", 0, 1);
	button[2].Init("次の曲へ", 2, 2);
	button[3].Init("終了", 3, 4);
}

//曲選択画面ボタン表示
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i].Draw();
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
int SongSelect::Update() {
	touch.Check();
	if (touch.Get(4) != 0)
		return TOP;
	return SONG_SELECT;
}

//曲選択画面表示
void SongSelect::View() {
	songSelectCover.View(); //カバー表示
	songSelectButton.View(); //ボタン表示
	songSelectTitle.View(); //タイトル表示
}

//曲選択画面画像ロード
void SongSelect::LoadThread() {
	songSelectTitle.Init(); //曲選択画面タイトル初期化
	songSelectCover.Init(); //選択中の曲初期化
	songSelectButton.Init();
//	Sleep(5000);
	loadFlag = 2;
}*/