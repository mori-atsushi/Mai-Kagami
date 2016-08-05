#include "SongSelectCommon.h"

//曲選択画面タイトルロード
SongSelectTitle::SongSelectTitle(Font *font, const float x, const float y) 
	: Draw(x, y) {
	title = new MyDrawTextLine(font, "", GetX() * SIZE_RATE, GetY() * SIZE_RATE - HEIGHT * 0.02, 1, 50, WIDTH * 0.4, 3);
	subTitle = new MyDrawText(font, "", GetX() * SIZE_RATE, GetY() * SIZE_RATE + HEIGHT * 0.02, 1, 30, "Yellow");
	scene = -100;
}

//曲選択画面タイトル計算
void SongSelectTitle::Update(int scene) {
	if (SongSelectTitle::scene != scene) {
		SongSelectTitle::scene = scene;
		switch (scene)
		{
		case MODE:
			title->ChangeText("Mode Select");
			break;
		case OPTION1:
			title->ChangeText("Option");
			subTitle->ChangeText("通し練習モード");
			break;
		default:
			title->ChangeText("Song Select");
			break;
		}
	}
}

//曲選択画面タイトル表示
void SongSelectTitle::View() {
	title->View(); //テキスト表示
	if(scene == OPTION1)
		subTitle->View(); //テキスト表示
}

SongSelectTitle::~SongSelectTitle() {
	delete title;
	delete subTitle;
}

//曲選択画面カバー画像初期化
SongInformation::SongInformation(Font *font, Songs *songs) {
	SongInformation::songs = songs;
	n = songs->GetSongNum();
	for (int i = 0; i < n; i++) {
		songCover[i] = new SongSelectCover(font, songs->GetSong(i), i);
		songCover[i]->Change(0, n);
	}

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
	songTitle = new MyDrawTextLine(font, "", WIDTH * 0.79, HEIGHT * 0.3, 1, 30, WIDTH * 0.35, 2); //テキスト初期化
	songArtist = new MyDrawText(font, "", WIDTH * 0.96, HEIGHT * 0.325, 2, 20); //テキスト初期化
	songLast[0] = new MyDrawText(font, "前回　： --点", WIDTH * 0.75, HEIGHT * 0.36, 0, 24); //テキスト初期化
	songLast[1] = new MyDrawText(font, "前々回： --点", WIDTH * 0.75, HEIGHT * 0.385, 0, 24); //テキスト初期化
}


void SongInformation::Load() {
	for (int i = 0; i < 2; i++)
		grad[i]->Load();
	for (int i = 0; i < n; i++)
		songCover[i]->Load();
}

void SongInformation::Update(Touch *touch, int scene) {
	switch (scene)
	{
	case MAIN:
		//ボタン0が押されたら
		if (touch->Get(0) == 1) {
			for (int i = 0; i < n; i++)
				songCover[i]->Change(1, n); //すべての曲の位置IDをインクリメント
		}

		//ボタン1が押されたら
		if (touch->Get(1) == 1) {
			nowSong->danceMovie->Load();
			nowSong->danceMovie->ChangeSpeed(nowSong->danceMovie->GetSpeed());
		}
		else {
			nowSong = songCover[songs->GetNowSong()];
			for (int i = 0; i < n; i++) {
				if (songCover[i]->GetNow() == 0) {
					now = i;
					songTitle->ChangeText(nowSong->GetSongTitle());
					songArtist->ChangeText(nowSong->GetSongArtist());
					break;
				}
			}
		}

		//ボタン2が押されたら
		if (touch->Get(2) == 1) {
			for (int i = 0; i < n; i++)
				songCover[i]->Change(-1, n); //すべての曲の位置IDをデクリメント
		}
		for (int i = 0; i < n; i++)
			songCover[i]->Update();
		break;
	case MODE:
		if (touch->Get(4) == 1)
			nowSong->danceMovie->Release();
		break;
	case OPTION1:
		if (touch->Get(0) == 1)
			nowSong->ChangeSpeed(1);
		if (touch->Get(1) == 1)
			nowSong->ChangeSpeed(-1);
		if (touch->Get(2) == 1)
			nowSong->danceMovie->Stop();
		if (touch->Get(4) == 1)
			nowSong->danceMovie->Stop();
	}
}

//曲選択画面カバー画像表示
void SongInformation::View(int scene) {
	songTitle->View();
	songArtist->View();
	for (int i = 0; i < 2; i++) {
		songLast[i]->View();
	}
	switch (scene)
	{
	case BACK:
	case MAIN:
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 90);
		myDrawBox->View();
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
		box->View();
		for (int i = 0; i < n; i++)
			songCover[i]->Draw(scene);
		for (int i = 0; i < 2; i++)
			grad[i]->View();
		break;
	case MODE:
	case OPTION1:
		nowSong->Draw(scene);
		break;
	}
}

void SongInformation::Release() {
	for (int i = 0; i < 2; i++)
		grad[i]->Release();
	for (int i = 0; i < n; i++)
		songCover[i]->Release();
}

SongInformation::~SongInformation() {
	delete box;
	delete myDrawBox;
	for (int i = 0; i < n; i++)
		delete songCover[i];
	for (int i = 0; i < 2; i++) {
		delete grad[i];
	}
}