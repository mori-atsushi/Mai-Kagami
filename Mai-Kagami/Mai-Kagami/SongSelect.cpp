#include "SongSelect.h"

//曲選択画面タイトルロード
SongSelectTitle::SongSelectTitle() {
	char *str = "Song Select"; //表示文字列
	myDrawText = new MyDrawText(str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //テキスト初期化
	myDrawLine = new MyDrawLine(WIDTH * 0.65, HEIGHT * 0.236, 1, WIDTH * 0.4, 20); //線初期化
}

//曲選択画面タイトル表示
void SongSelectTitle::View() {
	myDrawText->Draw(); //テキスト表示
	myDrawLine->Draw(); //線表示
}

SongSelectTitle::~SongSelectTitle() {
	delete myDrawText;
	delete myDrawLine;
}

//曲選択画面カバー画像初期化
SongSelectCover::SongSelectCover() {
	char *title = "ゴーストルール"; //表示文字列
	char *artist = "初音ミク / DECO*27";
	float x = HEIGHT * 0.35;
	myDrawGraph = new MyDrawGraph(WIDTH * 0.52, x, "song/Ghost_Rule/cover.jpg");
	songTitle = new MyDrawText(title, WIDTH * 0.8, HEIGHT * 0.29, 1, 36); //テキスト初期化
	songArtist = new MyDrawText(artist, WIDTH * 0.96, HEIGHT * 0.32, 2, 20); //テキスト初期化
	songLast[0] = new MyDrawText("前回　： --点", WIDTH * 0.75, HEIGHT * 0.355, 0, 24); //テキスト初期化
	songLast[1] = new MyDrawText("前々回： --点", WIDTH * 0.75, HEIGHT * 0.38, 0, 24); //テキスト初期化
	myDrawLine = new MyDrawLine(WIDTH * 0.8, HEIGHT * 0.315, 1, WIDTH * 0.33, 6); //線初期化
	myDrawBox = new MyDrawBox(WIDTH * 0.52, HEIGHT * 0.5, 170, 1000);
	songCover[0] = new MyDrawGraph(WIDTH * 0.52, x - 180, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[1] = new MyDrawGraph(WIDTH * 0.52, x + 180, "song/Happy_Synthesizer/cover.jpg", 0.7);
	songCover[2] = new MyDrawGraph(WIDTH * 0.52, x + 330, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[3] = new MyDrawGraph(WIDTH * 0.52, x + 480, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[4] = new MyDrawGraph(WIDTH * 0.52, x + 630, "song/Ghost_Rule/cover.jpg", 0.7);
	songCover[5] = new MyDrawGraph(WIDTH * 0.52, x + 780, "song/Ghost_Rule/cover.jpg", 0.7);
	grad[0] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.52, x, "img/box.png");
	//	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

//曲選択画面カバー画像表示
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	for(int i = 0; i < 6; i++)
		songCover[i]->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box->Draw();
	myDrawGraph->Draw();
	songTitle->Draw();
	songArtist->Draw();
	for (int i = 0; i < 2; i++) {
		songLast[i]->Draw();
		grad[i]->Draw();
	}
	myDrawLine->Draw();
}

SongSelectCover::~SongSelectCover() {
	delete songTitle;
	delete songArtist;
	for (int i = 0; i < 2; i++) {
		delete songLast[i];
		delete grad[i];
	}
	delete myDrawLine;
	delete myDrawGraph;
	for (int i = 0; i < 6; i++)
		delete songCover[i];
	delete box;
	delete myDrawBox;
}

//曲選択画面ボタン初期化
SongSelectButton::SongSelectButton() {
	button[0] = new Button("前の曲へ", 1, 0);
	button[1] = new Button("決定", 0, 1);
	button[2] = new Button("次の曲へ", 2, 2);
	button[3] = new Button("終了", 3, 4);
}

//曲選択画面ボタン表示
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->Draw();
}

SongSelectButton::~SongSelectButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}

//曲選択画面ロード
boolean SongSelect::Load() {
	if (loadFlag == 0) {
		songSelectTitle = new SongSelectTitle(); //曲選択画面タイトル初期化
		songSelectCover = new SongSelectCover(); //選択中の曲初期化
		songSelectButton = new SongSelectButton();
		loadFlag = 2;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;

	if (loadFlag == 2)
		return TRUE;
	return FALSE;
}

SongSelect::SongSelect() {
	loadFlag = 0;
}


//曲選択画面計算
int SongSelect::Update() {
	if (Load()) {
		touch.Check();
		if (touch.Get(4) != 0) {
			Delete();
			return TOP;
		}
	}
	return SONG_SELECT;
}

//曲選択画面表示
void SongSelect::View(Loading *loading) {
	if (loadFlag == 2) {
		songSelectCover->View(); //カバー表示
		songSelectButton->View(); //ボタン表示
		songSelectTitle->View(); //タイトル表示
	}
	else {
		loading->View();
	}
}

void SongSelect::Delete() {
	loadFlag = 0;
	delete songSelectCover;
	delete songSelectButton;
	delete songSelectTitle;
}