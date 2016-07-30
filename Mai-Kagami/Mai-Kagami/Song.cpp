#include "Song.h"

Song2::Song2(Font *font, Song *song, const int now) {
	char *folder = "";
	n = now;
	sprintf_s(music, sizeof(music), "song/%s/music.mp3", folder);
	myDrawGraph = song->GetSongCover(); //カバー画像
	myDrawMovie = song->GetSongMovie(); //動画
	myDrawMovie->ChangePos(WIDTH * 0.44, HEIGHT * 0.57);
	myDrawMovie->ChangeEx(0.9);

	float x = HEIGHT * 0.35;
	songTitle = new MyDrawTextLine(font, song->GetSongTitle(), WIDTH * 0.79, HEIGHT * 0.3, 1, 30, WIDTH * 0.35, 2); //テキスト初期化
	songArtist = new MyDrawText(font, song->GetSongArtist(), WIDTH * 0.96, HEIGHT * 0.325, 2, 20); //テキスト初期化
	songLast[0] = new MyDrawText(font, "前回　： --点", WIDTH * 0.75, HEIGHT * 0.36, 0, 24); //テキスト初期化
	songLast[1] = new MyDrawText(font, "前々回： --点", WIDTH * 0.75, HEIGHT * 0.385, 0, 24); //テキスト初期化
}

void Song2::Load() {
	myDrawGraph->Load();
	playFlag = FALSE;
}

void Song2::Release() {
	myDrawGraph->Release();
}

void Song2::Update() {
	if (n == 0) {
		myDrawGraph->ChangeEx(1.0);
		myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
	}
	else {
		myDrawGraph->ChangeEx(0.7);
		if (n == -1) {
			myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 - 180);
		}
		else if (n <= 5) {
			myDrawGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n);
		}
	}
}

void Song2::Draw(int scene) {
	if (n == 0) {
		songTitle->View();
		songArtist->View();
		for (int i = 0; i < 2; i++) {
			songLast[i]->View();
		}
	}
	else {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	}
	if (n >= -1 && n <= 5) {
		myDrawGraph->View();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	switch (scene) {
	case OPTION1:
		if(playFlag)
			StopMusic();
		playFlag = FALSE;
		myDrawMovie->View();
		break;
	default:
		if (n == 0 && !playFlag) {
				PlayMusic(music, DX_PLAYTYPE_LOOP);
			playFlag = TRUE;
		}
		else if (n != 0) {
			playFlag = FALSE;
		}
		speed = 0;
		break;
	}
}

void Song2::Change(int num, int max) {
	n += num;
	if (n == -2)
		n = max - 2;
	if (n == max - 1)
		n = -1;
}

void Song2::ChangeSpeed(int num) {
	const double s[6] = { 1.0, 0.9, 0.8, 0.7, 0.6, 0.5 };
	if (num == 1 && speed > 0) {
		speed -= 1;
		myDrawMovie->ChangeSpeed(s[speed]);
	}
	if (num == -1 && speed < 5) {
		speed += 1;
		myDrawMovie->ChangeSpeed(s[speed]);
	}
}

void Song2::LoadMovie() {
	myDrawMovie->Load();
}

void Song2::StopMovie() {
	myDrawMovie->Stop();
}

void Song2::ReleaseMovie() {
	myDrawMovie->Release();
}

int Song2::GetNow() {
	return n;
}

Song2::~Song2() {
	delete songTitle;
	delete songArtist;
	for (int i = 0; i < 2; i++) {
		delete songLast[i];
	}
	delete myDrawGraph;
}