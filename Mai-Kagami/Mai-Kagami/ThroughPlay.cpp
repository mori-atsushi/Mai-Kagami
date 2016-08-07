#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Font *font) {
	ThroughPlay::font = font;
}

void ThroughPlay::Load(Song *song) {
	ThroughPlay::song = song;
	songTitle = new MyDrawTextLine(font, song->GetSongTitle(), WIDTH * 0.2, HEIGHT * 0.03, 1, 30, WIDTH * 0.35, 2); //テキスト初期化
	songArtist = new MyDrawText(font, song->GetSongArtist(), WIDTH * 0.37, HEIGHT * 0.055, 2, 20); //テキスト初期化
	barAll = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, WIDTH * 0.56, 10);
	barNow = new MyDrawBar(WIDTH * 0.41, HEIGHT * 0.055, 0, 10, "Blue");
	circle[0] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 12);
	circle[1] = new MyDrawCircle(WIDTH * 0.41, HEIGHT * 0.055, 5, "White");

	song->LoadPart();
	for (int i = 0; i < song->GetPartNum(); i++) {
		SongPart *songPart = song->GetPart(i);
		float x = WIDTH * 0.41 + WIDTH * 0.56 * (float)songPart->GetFlame() / song->danceMovie->GetAllFlame();
		part[i] = new MyDrawTextV(font, songPart->GetName(), x, HEIGHT * 0.054, 0, 16);
	}
	pauseButton = new CircleGraphButton(0, "img/pause.png");
	pauseButton->Load();
}

void ThroughPlay::Update() {
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
	for(int i = 0; i < song->GetPartNum(); i++)
		part[i]->View();
	pauseButton->View();
}

ThroughPlay::~ThroughPlay() {
	delete songTitle;
	delete songArtist;
	delete barAll;
	delete barNow;
	for(int i = 0; i < 2; i++)
		delete circle[i];
}