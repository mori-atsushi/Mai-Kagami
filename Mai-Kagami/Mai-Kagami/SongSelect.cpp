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
	float x = HEIGHT * 0.35;
	for(int i = 0; i < 20; i++)
		song[i] = new Song("ゴーストルール", "初音ミク / DECO*27", "Ghost_Rule", i);
	myDrawBox = new MyDrawBox(WIDTH * 0.52, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.52, x, "img/box.png");

	//	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

void SongSelectCover::Update(int num) {
	for (int i = 0; i < 20; i++) {
		switch (num)
		{
		case 0:
			song[i]->Change(-1);
			break;
		case 2:
			song[i]->Change(1);
			break;
		default:
			song[i]->Update();
			break;
		}
	}
}

//曲選択画面カバー画像表示
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box->Draw();
	for (int i = 0; i < 20; i++)
		song[i]->Draw();
	for (int i = 0; i < 2; i++) {
		grad[i]->Draw();
	}
}

SongSelectCover::~SongSelectCover() {
	delete box;
	delete myDrawBox;
	delete song;
	for (int i = 0; i < 2; i++) {
		delete grad[i];
	}
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

SongSelectPop::SongSelectPop() {
	myDrawBox = new MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black");
	title = new MyDrawText("- 終了 -", WIDTH * 0.75, HEIGHT * 0.4, 1, 40, "Blue");
	message = new MyDrawText("本当に終了\nしますか？", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	buttonMessage[0] = new MyDrawText("はい", WIDTH * 0.75, BUTTON_POS + BUTTON_INTERVAL * 1 - HEIGHT * 0.0085, 1, 30);
	buttonMessage[1] = new MyDrawText("いいえ", WIDTH * 0.75, BUTTON_POS + BUTTON_INTERVAL * 2 - HEIGHT * 0.0085, 1, 30);
	buttonRing[0] = new MyDrawRing(WIDTH * 0.97, BUTTON_POS + BUTTON_INTERVAL * 1, WIDTH * 0.015, 7, "White");
	buttonRing[1] = new MyDrawRing(WIDTH * 0.97, BUTTON_POS + BUTTON_INTERVAL * 2, WIDTH * 0.015, 7, "White");
	flag = false;
}

void SongSelectPop::Update(int num) {
	if (num == 4 && !flag)
		flag = true;
	else if (num == 2 && flag)
		flag = false;
}

void SongSelectPop::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //透明度設定
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
	title->Draw();
	message->Draw();
	for (int i = 0; i < 2; i++) {
		buttonMessage[i]->Draw();
		buttonRing[i]->Draw();
	}
}

boolean SongSelectPop::Flag() {
	return flag;
}

SongSelectPop::~SongSelectPop() {
	delete myDrawBox;
	delete title;
	delete message;
	for (int i = 0; i < 2; i++) {
		delete buttonMessage[i];
		delete buttonRing[i];
	}
}


SongSelect::SongSelect() {
	loadFlag = 0;
}

//曲選択画面ロード
boolean SongSelect::Load() {
	if (loadFlag == 0) {
		songSelectTitle = new SongSelectTitle(); //曲選択画面タイトル初期化
		songSelectButton = new SongSelectButton();
		songSelectCover = new SongSelectCover(); //選択中の曲初期化
		songSelectPop = new SongSelectPop();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;

	if (loadFlag == 2)
		return TRUE;
	return FALSE;
}

//曲選択画面計算
int SongSelect::Update() {
	if (Load()) {
		touch.Check();
		if (songSelectPop->Flag()) {
			if (touch.Get(1) == 1) {
				Delete();
				return TOP;
			}
			if (touch.Get(2) == 1) {
				songSelectPop->Update(2);
			}
		}
		else {
			if (touch.Get(0) == 1) {
				songSelectCover->Update(0);
			}
			if (touch.Get(2) == 1) {
				songSelectCover->Update(2);
			}
			if (touch.Get(4) == 1) {
				songSelectPop->Update(4);
			}
		}
		songSelectCover->Update();

	}
	return SONG_SELECT;
}

//曲選択画面表示
void SongSelect::View(Loading *loading) {
	if (loadFlag == 2) {
		songSelectCover->View(); //カバー表示
		songSelectTitle->View(); //タイトル表示
		if(songSelectPop->Flag())
			songSelectPop->View();
		else
			songSelectButton->View(); //ボタン表示
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
	delete songSelectPop;
}