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
		part[i] = new MyDrawTextV(font, songPart->GetName(), x, HEIGHT * 0.056, 0, 16);
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

ThroughPlay::ThroughPlay(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
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
	viewFlag = TRUE;
}

ThroughScene ThroughPlay::Switch(const ThroughScene scene) {
	KinectDistance kinectDistance;

	if (kinectDistance.CheckDistance() == FALSE) //ユーザが2mより近かったら
		return THROUGH_START;

	switch (scene)
	{
	case THROUGH_START:
		return THROUGH_COUNTDOWN;
	case THROUGH_COUNTDOWN:
		return throughCountDown->Switch(scene);
	case THROUGH_PLAY:
		if (song->danceMovie->GetNowFlame() == 100)
			return THROUGH_NEXT;
	}
	return scene;
}

void ThroughPlay::ContentUpdate() {
	throughPlayBar->Update();
	throughCountDown->Update(nowScene);

	if(nowScene == THROUGH_PLAY)
		song->danceMovie->Start();
	else
		song->danceMovie->Stop();
}

void ThroughPlay::ContentView() {
	song->danceMovie->View();
	song->drawSongTitle->View();
	throughPlayBar->View();
	throughCountDown->View();
}

ThroughPlay::~ThroughPlay() {
	delete throughPlayBar;
	delete throughCountDown;
}