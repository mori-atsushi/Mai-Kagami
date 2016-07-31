#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Font *font, Song *song) {
	ThroughPlay::song = song;
	songTitle = new MyDrawTextLine(font, song->GetSongTitle(), WIDTH * 0.2, HEIGHT * 0.03, 1, 30, WIDTH * 0.35, 2); //テキスト初期化
	songArtist = new MyDrawText(font, song->GetSongArtist(), WIDTH * 0.37, HEIGHT * 0.055, 2, 20); //テキスト初期化
}

void ThroughPlay::View() {
	song->danceMovie->ChangeEx(2.4);
	song->danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.5);
	song->danceMovie->View();
	songTitle->View();
	songArtist->View();
}

ThroughPlay::~ThroughPlay() {
	delete songTitle;
	delete songArtist;
}