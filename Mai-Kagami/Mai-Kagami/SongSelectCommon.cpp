#include "SongSelectCommon.h"

//曲選択画面タイトルロード
SongSelectTitle::SongSelectTitle(Font *font, const float x, const float y) 
	: MyDrawTextLine(font, "", x, y - HEIGHT * 0.02, 1, 50, WIDTH * 0.4, 3)
	, MyDrawText(font, "", x, y + HEIGHT * 0.02, 1, 30, "Yellow"){
}

//曲選択画面タイトル計算
void SongSelectTitle::Update(int scene) {
	switch (scene)
	{
	case MODE:
		MyDrawTextLine::ChangeText("Mode Select");
		break;
	case OPTION1:
		MyDrawTextLine::ChangeText("Option");
		MyDrawText::ChangeText("通し練習モード");
		break;
	default:
		MyDrawTextLine::ChangeText("Song Select");
		break;
	}
}

//曲選択画面タイトル表示
void SongSelectTitle::View(int scene) {
	MyDrawTextLine::View(); //テキスト表示
	if(scene == OPTION1)
		MyDrawText::View(); //テキスト表示
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
	for (int i = 0; i < n; i++)
		song[i]->Change(0, n);
	FileRead_close(file);

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
}


void SongSelectCover::Load() {
	for (int i = 0; i < 2; i++)
		grad[i]->Load();
	for (int i = 0; i < n; i++)
		song[i]->Load();
}

void SongSelectCover::Update(Touch *touch, int scene) {
	switch (scene)
	{
	case MAIN:
		if (touch->Get(0) == 1) {
			for (int i = 0; i < n; i++)
				song[i]->Change(1, n);
		}

		if (touch->Get(1) == 1)
			song[now]->LoadMovie();
		else {
			for (int i = 0; i < n; i++) {
				if (song[i]->GetNow() == 0) {
					now = i;
					break;
				}
			}
		}

		if (touch->Get(2) == 1) {
			for (int i = 0; i < n; i++)
				song[i]->Change(-1, n);
		}
		for (int i = 0; i < n; i++)
			song[i]->Update();
		break;
	case MODE:
		if (touch->Get(4) == 1)
			song[now]->ReleaseMovie();
		break;
	case OPTION1:
		if (touch->Get(0) == 1)
			song[now]->ChangeSpeed(1);
		if (touch->Get(1) == 1)
			song[now]->ChangeSpeed(-1);
		if (touch->Get(4) == 1)
			song[now]->StopMovie();
	}
}

//曲選択画面カバー画像表示
void SongSelectCover::View(int scene) {
	switch (scene)
	{
	case BACK:
	case MAIN:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
		myDrawBox->View();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		box->View();
		for (int i = 0; i < n; i++)
			song[i]->Draw(scene);
		for (int i = 0; i < 2; i++)
			grad[i]->View();
		break;
	case MODE:
	case OPTION1:
		song[now]->Draw(scene);
		break;
	}
}

void SongSelectCover::Release() {
	for (int i = 0; i < 2; i++)
		grad[i]->Release();
	for (int i = 0; i < n; i++)
		song[i]->Release();
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