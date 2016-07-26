#include "Song.h"

Song::Song(Font *font, char *title, char *artist, char *folder, int now) {
	playFlag = FALSE;
	n = now;
	char cover[256];
	sprintf_s(cover, sizeof(cover), "song/%s/cover.jpg", folder);
	sprintf_s(music, sizeof(music), "song/%s/music.mp3", folder);
	float x = HEIGHT * 0.35;
	myDrawGraph = new MyDrawGraph(WIDTH * 0.5, x, cover);
	songTitle = new MyDrawText(font, title, WIDTH * 0.79, HEIGHT * 0.29, 1, 30); //テキスト初期化
	songArtist = new MyDrawText(font, artist, WIDTH * 0.96, HEIGHT * 0.32, 2, 20); //テキスト初期化
	songLast[0] = new MyDrawText(font, "前回　： --点", WIDTH * 0.75, HEIGHT * 0.355, 0, 24); //テキスト初期化
	songLast[1] = new MyDrawText(font, "前々回： --点", WIDTH * 0.75, HEIGHT * 0.38, 0, 24); //テキスト初期化
	myDrawLine = new MyDrawLine(WIDTH * 0.79, HEIGHT * 0.315, 1, WIDTH * 0.35, 6); //線初期化
}

void Song::Update() {
	if (n == 0) {
		myDrawGraph->ChangeEx(1.0);
		myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
		if (!playFlag)
			PlayMusic(music, DX_PLAYTYPE_LOOP);
		playFlag = TRUE;
	}
	else {
		playFlag = FALSE;
		myDrawGraph->ChangeEx(0.7);
		if (n == -1) {
			myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 - 180);
		}
		else if (n <= 5) {
			myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n);
		}
	}
}

void Song::Draw() {
	if (n == 0) {
		songTitle->Draw();
		songArtist->Draw();
		for (int i = 0; i < 2; i++) {
			songLast[i]->Draw();
		}
		myDrawLine->Draw();
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	}
	if (n >= -1 && n <= 5) {
		myDrawGraph->Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Song::Change(int num) {
	n += num;

}

int Song::GetNow() {
	return n;
}

Song::~Song() {
	delete songTitle;
	delete songArtist;
	for (int i = 0; i < 2; i++) {
		delete songLast[i];
	}
	delete myDrawLine;
	delete myDrawGraph;
	for (int i = 0; i < 6; i++)
		delete songCover[i];
}