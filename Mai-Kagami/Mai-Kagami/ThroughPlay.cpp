#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Font *font, Song *song) {
	ThroughPlay::song = song;
	songTitle = new MyDrawTextLine(font, song->GetSongTitle(), WIDTH * 0.2, HEIGHT * 0.03, 1, 30, WIDTH * 0.35, 2); //テキスト初期化
	songArtist = new MyDrawText(font, song->GetSongArtist(), WIDTH * 0.37, HEIGHT * 0.055, 2, 20); //テキスト初期化
	barAll = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, WIDTH * 0.56, 10);
	barNow = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, 0, 10, "Blue");
	circle[0] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 12);
	circle[1] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 5, "White");
}

void ThroughPlay::Update() {
	float now = WIDTH * 0.56 * song->danceMovie->GetNow();
	barNow->ChangeSize(now, 10);
	for (int i = 0; i < 2; i++)
		circle[i]->ChangePos(WIDTH * 0.41 + now, HEIGHT * 0.055);
}

void ThroughPlay::View() {
	song->danceMovie->ChangeEx(2.4);
	song->danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.5);
	song->danceMovie->View();
	songTitle->View();
	songArtist->View();
	barAll->View();
	barNow->View();
	for(int i = 0; i < 2; i++)
		circle[i]->View();
}

ThroughPlay::~ThroughPlay() {
	delete songTitle;
	delete songArtist;
	delete barAll;
	delete barNow;
	for(int i = 0; i < 2; i++)
		delete circle[i];
}