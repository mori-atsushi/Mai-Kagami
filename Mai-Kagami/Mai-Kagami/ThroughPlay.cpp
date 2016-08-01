#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Font *font, Song *song) {
	ThroughPlay::song = song;
	songTitle = new MyDrawTextLine(font, song->GetSongTitle(), WIDTH * 0.2, HEIGHT * 0.03, 1, 30, WIDTH * 0.35, 2); //テキスト初期化
	songArtist = new MyDrawText(font, song->GetSongArtist(), WIDTH * 0.37, HEIGHT * 0.055, 2, 20); //テキスト初期化
	barAll = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, WIDTH * 0.56, 10);
	barNow = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, 0, 10, "Blue");
	circle[0] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 12);
	circle[1] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 5, "White");
	part[0] = new MyDrawTextV(font, "イントロ", WIDTH * 0.41, HEIGHT * 0.054, 0, 20, "Blue");
	part[1] = new MyDrawTextV(font, "Aパート", WIDTH * 0.45, HEIGHT * 0.054, 0, 16);
	part[2] = new MyDrawTextV(font, "Bパート", WIDTH * 0.5, HEIGHT * 0.054, 0, 16);
	part[3] = new MyDrawTextV(font, "サビ", WIDTH * 0.55, HEIGHT * 0.054, 0, 16);
	part[4] = new MyDrawTextV(font, "間奏", WIDTH * 0.60, HEIGHT * 0.054, 0, 16);
	part[5] = new MyDrawTextV(font, "Aパート", WIDTH * 0.65, HEIGHT * 0.054, 0, 16);
}

void ThroughPlay::Update() {
	float now = WIDTH * 0.56 * song->danceMovie->GetNow();
	barNow->ChangeSize(now, 10);
	for (int i = 0; i < 2; i++)
		circle[i]->ChangePos(WIDTH * 0.41 + now, HEIGHT * 0.055);
}

void ThroughPlay::View() {
	song->danceMovie->ChangeEx(1);
	song->danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.5);
	song->danceMovie->View();
	songTitle->View();
	songArtist->View();
	barAll->View();
	barNow->View();
	for(int i = 0; i < 2; i++)
		circle[i]->View();
	for(int i = 0; i < 6; i++)
		part[i]->View();
}

ThroughPlay::~ThroughPlay() {
	delete songTitle;
	delete songArtist;
	delete barAll;
	delete barNow;
	for(int i = 0; i < 2; i++)
		delete circle[i];
}