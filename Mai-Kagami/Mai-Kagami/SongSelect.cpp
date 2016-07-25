#include "SongSelect.h"

//曲選択画面タイトルロード
SongSelectTitle::SongSelectTitle(Font *font) {
	char *str = "Song Select"; //表示文字列
	myDrawText = new MyDrawText(font, str, WIDTH * 0.65, HEIGHT * 0.2, 1, 50); //テキスト初期化
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
SongSelectCover::SongSelectCover(Font *font) {
	n = 0;
	SetUseASyncLoadFlag(FALSE);
	int file = FileRead_open("song/song.csv", FALSE);
	SetUseASyncLoadFlag(TRUE);
	char buf[3][256];
	while (FileRead_scanf(file, "%[^,\n\r],%[^,\n\r],%[^\n\r]", buf[0], buf[1], buf[2]) != EOF) {
		song[n] = new Song(font, buf[1], buf[2], buf[0], n);
		n++;
	}
	FileRead_close(file);

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.52, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.52, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.52, x, "img/box.png");

	//	PlayMusic("song/Ghost_Rule/music.mp3", DX_PLAYTYPE_LOOP);
}

void SongSelectCover::Update(int num) {
	if (num == 0 && song[n - 1]->GetNow() > 0) {
		for (int i = 0; i < n; i++)
			song[i]->Change(-1);
	}
	else if (num == 2 && song[0]->GetNow() < 0) {
		for (int i = 0; i < n; i++)
			song[i]->Change(1);
	}
	for (int i = 0; i < n; i++)
		song[i]->Update();
}

//曲選択画面カバー画像表示
void SongSelectCover::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	box->Draw();
	for (int i = 0; i < n; i++)
		song[i]->Draw();
	for (int i = 0; i < 2; i++) {
		grad[i]->Draw();
	}
}

SongSelectCover::~SongSelectCover() {
	delete box;
	delete myDrawBox;
	for (int i = 0; i < n; i++)
		delete song[i];
	for (int i = 0; i < 2; i++) {
		delete grad[i];
	}
}

//曲選択画面ボタン初期化
SongSelectButton::SongSelectButton(Font *font) {
	button[0] = new Button(font, "前の曲へ", 1, 0);
	button[1] = new Button(font, "決定", 0, 1);
	button[2] = new Button(font, "次の曲へ", 2, 2);
	button[3] = new Button(font, "終了", 3, 4);
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

SongSelectPop::SongSelectPop(Font *font) {
	myDrawBox = new MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black");
	title = new MyDrawText(font, "- 終了 -", WIDTH * 0.75, HEIGHT * 0.4, 1, 40, "Blue");
	message = new MyDrawText(font, "本当に終了\nしますか？", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	buttonMessage[0] = new MyDrawText(font, "はい", WIDTH * 0.75, BUTTON_POS + BUTTON_INTERVAL * 1 - HEIGHT * 0.0085, 1, 30);
	buttonMessage[1] = new MyDrawText(font, "いいえ", WIDTH * 0.75, BUTTON_POS + BUTTON_INTERVAL * 2 - HEIGHT * 0.0085, 1, 30);
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


SongSelect::SongSelect(Font *font) {
	f = font;
	loadFlag = 0;
}

//曲選択画面ロード
boolean SongSelect::Load() {
	if (loadFlag == 0) {
		songSelectTitle = new SongSelectTitle(f); //曲選択画面タイトル初期化
		songSelectButton = new SongSelectButton(f);
		songSelectCover = new SongSelectCover(f); //選択中の曲初期化
		songSelectPop = new SongSelectPop(f);
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
			else {
				songSelectCover->Update(-1);
			}
		}

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