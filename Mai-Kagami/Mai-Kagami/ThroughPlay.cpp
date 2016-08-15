#include "ThroughPlay.h"

//進捗バー
ThroughPlayBar::ThroughPlayBar(Font *font) {
	barAll = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, WIDTH * 0.56, 10);
	barNow = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, 0, 10, "Blue");
	circle[0] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 12);
	circle[1] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 5, "White");
	ThroughPlayBar::font = font;
}

void ThroughPlayBar::Load(Song *song) {
	ThroughPlayBar::song = song;
	song->LoadPart();
	for (int i = 0; i < song->GetPartNum(); i++) {
		SongPart *songPart = song->GetPart(i);
		float x = WIDTH * 0.41 + WIDTH * 0.56 * (float)songPart->GetFlame() / song->danceMovie->GetAllFlame();
		part[i] = new MyDrawTextV(font, songPart->GetName(), x, HEIGHT * 0.054, 0, 16);
	}
}

void ThroughPlayBar::Update() {
	int nowFlame = song->danceMovie->GetNowFlame();
	int lastFlame = song->danceMovie->GetAllFlame();
	float now = WIDTH * 0.56 * nowFlame / lastFlame;
	barNow->ChangeSize(now, 10);
	for (int i = 0; i < 2; i++)
		circle[i]->ChangePos(WIDTH * 0.41 + now, HEIGHT * 0.055);
	for (int i = song->GetPartNum() - 1; i >= 0; i--) {
		SongPart *songPart = song->GetPart(i);
		if (nowFlame < lastFlame && nowFlame >= songPart->GetFlame()) {
			part[i]->ChangeColor("Blue");
			part[i]->ChangeFont(font, 20);
		}
		else {
			part[i]->ChangeColor("White");
			part[i]->ChangeFont(font, 16);
		}
		lastFlame = songPart->GetFlame();
	}
}

void ThroughPlayBar::View() {
	barAll->View();
	barNow->View();
	for (int i = 0; i < 2; i++)
		circle[i]->View();
	for (int i = 0; i < song->GetPartNum(); i++)
		part[i]->View();
}

ThroughPlayBar::~ThroughPlayBar() {
	delete barAll;
	delete barNow;
	for (int i = 0; i < 2; i++)
		delete circle[i];
}

//カウントダウン画面再生三角形
PlayTriangle::PlayTriangle(const float x, const float y) 
	: MyDrawTriangle("Yellow") {
	const float w = 100, ex = 12;
	float x1 = x - w + ex, x2 = x - w + ex, x3 = x + w + ex;
	float y1 = y + w, y2 = y - w, y3 = y;
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//カウントダウン画面
ThroughCountDown::ThroughCountDown(Font *font) {
	const float x = WIDTH * 0.5; //円の中心（x座標）
	const float y = HEIGHT * 0.5; //円の中心（y座標）
	const float r = WIDTH * 0.2; //円の半径
	blackBox = new BlackBox();
	text = new MyDrawText(font, "準備をしてください", x, y + r + 80, 1, 40);
	circle = new MyDrawCircle(x, y, r, "White");
	countCircle1 = new MyDrawCircleGauge(x, y, r, 0, 4, "Yellow");
	countCircle2 = new MyDrawCircle(0, 0, 12, "Yellow");
	playTriangle = new PlayTriangle(x, y);
}

void ThroughCountDown::Update() {
	countCircle1->ChangeDegree((double)count / max * 100);
	countCircle2->ChangePos(countCircle1->GetEndX() * SIZE_RATE, countCircle1->GetEndY() * SIZE_RATE);
	if (++count == max)
		flag = FALSE;
}

void ThroughCountDown::View() {
	blackBox->View();
	text->View();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //透明度設定
	circle->View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
	countCircle1->View();
	countCircle2->View();
	playTriangle->View();
}

boolean ThroughCountDown::GetFlag() {
	return flag;
}

void ThroughCountDown::SetFlag(const boolean flag) {
	ThroughCountDown::flag = flag;
	if (flag == TRUE)
		count = 0;
}

ThroughCountDown::~ThroughCountDown() {
	delete blackBox;
	delete text;
	delete circle;
	delete countCircle1;
	delete countCircle2;
	delete playTriangle;
}

ThroughPlay::ThroughPlay(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	this->touch = touch;
	throughPlayBar = new ThroughPlayBar(font);
	throughCountDown = new ThroughCountDown(font);
}

void ThroughPlay::Load() {
	song = songs->GetSong(songs->GetNowSong());
	song->danceMovie->ChangeEx(1.2);
	song->danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.5);
	song->danceMovie->Seek();
	song->drawSongTitle->ChangePos(WIDTH * 0.2, HEIGHT * 0.03);

	throughPlayBar->Load(song);
	throughCountDown->SetFlag(TRUE);
}

int ThroughPlay::Switch(const int scene) {
	switch (scene)
	{
	case THROUGH_PAUSE:
		if (touch->Get(0) == 1)
			return THROUGH_START;
		if (touch->Get(1) == 1) {
			song->danceMovie->Seek();
			return THROUGH_START;
		}
		if (touch->Get(2) == 1)
			return BACK_SONG_SELECT;
		if (touch->Get(3) == 1)
			return THROUGH_SETTING;
		break;
	case THROUGH_SETTING:
		if (touch->Get(4) == 1)
			return THROUGH_PAUSE;
		break;
	case THROUGH_PLAY:
	case THROUGH_START:
		KinectDistance kinectDistance;
		if (touch->Get(0) == 1)
			return THROUGH_PAUSE;
		if (song->danceMovie->GetNowFlame() == 100)
			return THROUGH_RESULT;
		if (kinectDistance.CheckDistance() == TRUE)
			return THROUGH_PLAY;
		else
			return THROUGH_START;
	}
	return scene;
}

void ThroughPlay::ContentUpdate() {
	throughPlayBar->Update();
	if (nowScene == THROUGH_PLAY) {
		if (throughCountDown->GetFlag())
			throughCountDown->Update();
		else
			song->danceMovie->Start();
		viewFlag = TRUE;
	}
	else {
		throughCountDown->SetFlag(TRUE);
		song->danceMovie->Stop();
		switch (nowScene)
		{
		case THROUGH_SETTING:
		case THROUGH_START:
		case THROUGH_PAUSE:
			viewFlag = TRUE;
			break;
		case THROUGH_RESULT:
		case THROUGH_DETAIL:
		case THROUGH_FINISH:
			viewFlag = FALSE;
			break;
		}
	}
}

void ThroughPlay::ContentView() {
	song->danceMovie->View();
	song->drawSongTitle->View();
	throughPlayBar->View();
	if (nowScene == THROUGH_PLAY && throughCountDown->GetFlag())
		throughCountDown->View();
}

ThroughPlay::~ThroughPlay() {
	delete throughPlayBar;
	delete throughCountDown;
}