#include "SongSelectCover.h"
#include "Animation.h"

SongSelectCover::SongSelectCover(Font *font, Song *song, const int now) 
	: Song(*song) {
	char *folder = "";
	SetNow(now);
}

void SongSelectCover::Load(int max) {
	danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.57);
	danceMovie->ChangeEx(0.5);
	coverGraph->Load();
	//Update(0, max);
	Change(0, max);
	int n = GetNow();
	//int h = 0;
	//if (n == 0)
	//	h = HEIGHT * 0.35;
	//else if (n == -1)
	//	h = HEIGHT * 0.35 - 180;
	//else
	//	h = HEIGHT * 0.35 + 30 + 150 * n;
	coverGraph->ChangePos(WIDTH * 0.5, CalcY());
	coverGraph->SetAlpha(CalcAlpha());
	coverGraph->ChangeEx(CalcEx());
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
	int duration = 20;
	float y = CalcY();

	if (n == -2 && num > 0 || n == max - 3 && num < 0) {
		coverGraph->SetDuration(0);
		coverGraph->SetPosAnimation(WIDTH * 0.5, y);
	}
	else if (coverGraph->GetTime() == 0) { // 最初だけ
		coverGraph->SetDuration(duration);
		coverGraph->SetPosAnimation(WIDTH * 0.5, y, Animation::EaseOut_SINE);
	}

	coverGraph->SetExAnimation( CalcEx(), Animation::EaseOut_SINE );
	coverGraph->SetAlphaAnimation( CalcAlpha(), Animation::EaseOut_SINE );

	coverGraph->Update(); // (あらゆる)アニメーション更新
}

void SongSelectCover::Draw(int scene) {
	int n = GetNow();
	if (n <= 6)	// 移動中を考えて 5 も描画
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
//			PlayMusic(music, DX_PLAYTYPE_LOOP); // 重いので一時的に消去 Jaity
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
	n = (n + num + max + 2) % max - 2;
	SetNow(n);
}

// y座標を算出して取得
float SongSelectCover::CalcY() {
	int n = GetNow();
	float y;

	n = n < 6 ? n : 6;

	if (n <= -1)
		y =  HEIGHT * 0.35 - 30 + 150 * n;
	else if (n == 0)
		y = HEIGHT * 0.35;
	else
		y = HEIGHT * 0.35 + 30 + 150 * n;

	return y;
}

int SongSelectCover::CalcAlpha() {
	return GetNow() ? 180 : 255;
}

double SongSelectCover::CalcEx() {
	return GetNow() ? 0.7 : 1.0;
}