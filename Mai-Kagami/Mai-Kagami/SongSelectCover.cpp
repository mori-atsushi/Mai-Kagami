#include "SongSelectCover.h"

SongSelectCover::SongSelectCover(Font *font, Song *song, const int now) 
	: Song(*song) {
	char *folder = "";
	n = now;
	danceMovie->ChangePos(WIDTH * 0.44, HEIGHT * 0.57);
	danceMovie->ChangeEx(0.9);

	float x = HEIGHT * 0.35;
}

void SongSelectCover::Load() {
	coverGraph->Load();
	playFlag = FALSE;
}

void SongSelectCover::Release() {
	coverGraph->Release();
}

void SongSelectCover::Update() {
	if (n == 0) {
		coverGraph->ChangeEx(1.0);
		coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
	}
	else {
		coverGraph->ChangeEx(0.7);
		if (n == -1) {
			coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 - 180);
		}
		else if (n <= 5) {
			coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n);
		}
	}
}

void SongSelectCover::Draw(int scene) {
	if (n != 0) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, 180);
	}
	if (n >= -1 && n <= 5) {
		coverGraph->View();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);


	switch (scene) {
	case OPTION1:
		if(playFlag)
			StopMusic();
		playFlag = FALSE;
		danceMovie->View();
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

void SongSelectCover::Change(int num, int max) {
	n += num;
	if (n == -2)
		n = max - 2;
	if (n == max - 1)
		n = -1;
}

void SongSelectCover::ChangeSpeed(int num) {
	const double s[6] = { 1.0, 0.9, 0.8, 0.7, 0.6, 0.5 };
	if (num == 1 && speed > 0) {
		speed -= 1;
		danceMovie->ChangeSpeed(s[speed]);
	}
	if (num == -1 && speed < 5) {
		speed += 1;
		danceMovie->ChangeSpeed(s[speed]);
	}
}

void SongSelectCover::LoadMovie() {
	danceMovie->Load();
}

void SongSelectCover::StopMovie() {
	danceMovie->Stop();
}

void SongSelectCover::ReleaseMovie() {
	danceMovie->Release();
}

int SongSelectCover::GetNow() {
	return n;
}