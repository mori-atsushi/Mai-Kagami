#include "SongSelectCommon.h"

//曲選択画面タイトルロード
SongSelectTitle::SongSelectTitle(Font *font) {
	title = new DrawTitle(font, "");
	subTitle = new DrawSubtitle(font, "");
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
		//songCover[i]->Change(0, n);  // Updateに統合したから要らなくなった Jaity
	}

	float x = HEIGHT * 0.35;
	myDrawBox = new MyDrawBox(WIDTH * 0.5, HEIGHT * 0.5, 170, 1000);
	myDrawBox->SetAlpha(90); //透明度指定
	grad[0] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.22, "img/grad1.png");
	grad[1] = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.8, "img/grad2.png");
	box = new MyDrawGraph(WIDTH * 0.5, x, "img/box.png");
	songLast[0] = new MyDrawText(font, "前回　： --点", WIDTH * 0.75, HEIGHT * 0.36, 0, 24); //テキスト初期化
	songLast[1] = new MyDrawText(font, "前々回： --点", WIDTH * 0.75, HEIGHT * 0.385, 0, 24); //テキスト初期化
}


void SongInformation::Load() {
	for (int i = 0; i < 2; i++)
		grad[i]->Load();
	for (int i = 0; i < n; i++)
		songCover[i]->Load();
	box->Load();
}

void SongInformation::Update(Touch *touch, int scene) {
	int direct = 0;  // increase or decrease of IDs  Jaity
	switch (scene)
	{
	case MAIN:
		//ボタン0が押されたら
		if (touch->Get(0) == 1) {
			//for (int i = 0; i < n; i++)  // 不要 Jaity
			//	songCover[i]->Change(1, n); //すべての曲の位置IDをインクリメント // 不要 Jaity
			direct = 1;  // Jaity
			for (int i = 0; i < n; i++)
				songCover[i]->coverGraph->Reset();
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
					nowSong->drawSongTitle->ChangePos(WIDTH * 0.79, HEIGHT * 0.3);
					break;
				}
			}
		}

		//ボタン2が押されたら
		if (touch->Get(2) == 1) {
			//for (int i = 0; i < n; i++) // 不要 Jaity
			//	songCover[i]->Change(-1, n); //すべての曲の位置IDをデクリメント // 不要 Jaity
			direct = -1;  // Jaity
			for (int i = 0; i < n; i++)
				songCover[i]->coverGraph->Reset();
		}
		for (int i = 0; i < n; i++)
			songCover[i]->Update(direct, n);  // Updateに引数追加 Jaity
		break;
	case MODE:
		if (touch->Get(4) == 1)
			nowSong->danceMovie->Release();
		break;
	case OPTION1:
		if (touch->Get(2) == 1)
			nowSong->danceMovie->Stop();
		if (touch->Get(4) == 1)
			nowSong->danceMovie->Stop();
	}
}

//曲選択画面カバー画像表示
void SongInformation::View(int scene) {
	nowSong->drawSongTitle->View();
	for (int i = 0; i < 2; i++) {
		songLast[i]->View();
	}
	switch (scene)
	{
	case BACK:
	case MAIN:
		myDrawBox->View();
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