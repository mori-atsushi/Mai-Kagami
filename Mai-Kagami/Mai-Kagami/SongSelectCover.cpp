#include "SongSelectCover.h"

SongSelectCover::SongSelectCover(Font *font, Song *song, const int now) 
	: Song(*song) {
	char *folder = "";
	SetNow(now);
}

void SongSelectCover::Load() {
	danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.57);
	danceMovie->ChangeEx(0.5);
	coverGraph->Load();
	playFlag = FALSE;
}

void SongSelectCover::Release() {
	coverGraph->Release();
}

//表示位置の計算
void SongSelectCover::Update(int num, int max) {
	//static int t = 0;	// 邪魔 Jaity
	Change(num, max);
	int n = GetNow();
	int duration = 10;

	if (n == 0) {
		coverGraph->ChangeEx(1.0);
		if (coverGraph->GetTime() == 0) { // 最初だけ
			coverGraph->SetPosAnimation(WIDTH * 0.5, HEIGHT * 0.35, duration);
			//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
		}
		//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35);
		//coverGraph->Update();
	}
	else {
		coverGraph->ChangeEx(0.7);
		if (coverGraph->GetTime() == 0) { // 最初だけ
			if (n == -1) {
				//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 - 180);
				coverGraph->SetPosAnimation(WIDTH * 0.5, HEIGHT * 0.35 - 180, duration);
			}
			else if (n <= 5) {
				//coverGraph->ChangePos(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n);
				coverGraph->SetPosAnimation(WIDTH * 0.5, HEIGHT * 0.35 + 30 + 150 * n, duration);
			}
		}
	}
	coverGraph->Update();
	//if (t < 1000)	// 邪魔 Jaity
	//	t++;		// 邪魔 Jaity
}

void SongSelectCover::Draw(int scene) {
	int n = GetNow();
	if (n != 0)
		coverGraph->SetAlpha(180); //透明度指定
	else
		coverGraph->SetAlpha(); //透明度解除
	if (n >= -1 && n <= 5)
		coverGraph->View();

	switch (scene) {
	case OPTION1:
		if(playFlag)
			StopMusic();
		playFlag = FALSE;
		danceMovie->Start();
		danceMovie->View();
		break;
	case OPTION2:
		if (playFlag)
			StopMusic();
		playFlag = FALSE;
		break;
	default:
		if (n == 0 && !playFlag) {
			PlayMusic(music, DX_PLAYTYPE_LOOP); // 重いので一時的に消去 Jaity
			//PlayMusic(music, DX_PLAYTYPE_LOOP);
			playFlag = TRUE;
		}
		else if (n != 0) {
			playFlag = FALSE;
		}
		break;
	}
}

//曲の位置IDを変更
void SongSelectCover::Change(int num, int max) {
	int n = GetNow();
	n += num;
	if (n == -2)
		n = max - 2;
	if (n == max - 1)
		n = -1;
	SetNow(n);
}