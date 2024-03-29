#include "SongSelectCover.h"
#include "Animation.h"

SongSelectCover::SongSelectCover(DecorationItem *decorationItem, Song *song, const int now) 
	: Song(*song) {
	char *folder = "";
	SetNow(now);
}

void SongSelectCover::Load(int max) {
	danceMovie->ChangePos(WIDTH * 0.5, HEIGHT * 0.57);
	danceMovie->ChangeEx(0.5);
	coverGraph->Load();
	coverWhite->Load();
	Change(0, max);

	coverGraph->ChangePos(WIDTH * 0.5, CalcY());
	coverGraph->SetAlpha(CalcAlpha());
	coverGraph->ChangeEx(CalcEx());
	coverWhite->ChangePos(WIDTH * 0.5, CalcY());
	coverWhite->SetAlpha(CalcAlphaWhite());
	coverWhite->ChangeEx(CalcEx());
}

void SongSelectCover::Release() {
	StopSoundMem(musicHandle);
	DeleteSoundMem(musicHandle);
	loadFlag = FALSE;
	coverGraph->Release();
	coverWhite->Release();
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
		coverWhite->SetDuration(0);
		coverWhite->SetPosAnimation(WIDTH * 0.5, y);
	}
	else if (coverGraph->GetTime() == 0) { // 最初だけ
		coverGraph->SetDuration(duration);
		coverGraph->SetPosAnimation(WIDTH * 0.5, y, Animation::EaseOut_SINE);
		coverWhite->SetDuration(duration);
		coverWhite->SetPosAnimation(WIDTH * 0.5, y, Animation::EaseOut_SINE);
	}

	coverGraph->SetExAnimation(CalcEx(), Animation::EaseOut_SINE);
	coverGraph->SetAlphaAnimation(CalcAlpha(), Animation::EaseOut_SINE);
	coverWhite->SetExAnimation(CalcEx(), Animation::EaseOut_SINE);
	coverWhite->SetAlphaAnimation(CalcAlphaWhite(), Animation::EaseOut_SINE);

	coverGraph->Update(); // アニメーション更新
	coverWhite->Update();
}

void SongSelectCover::Draw(int scene) {
	int n = GetNow();
	if (n <= 6) {	// 移動中を考えて 5 も描画
		coverWhite->View();
		coverGraph->View();
	}
	switch (scene) {
	case OPTION1:
	case OPTION2:
	case OPTION2_PART:
	case OPTION2_SPEED:
		StopSoundMem(musicHandle);
		danceMovie->Start();
		danceMovie->Loop();
		danceMovie->View();
		break;
	default:
		if (n == 0) {
			if (!loadFlag) {
				musicHandle = LoadSoundMem(music);
				loadFlag = TRUE;
			}
			if (CheckSoundMem(musicHandle) == 0)
				PlaySoundMem(musicHandle, DX_PLAYTYPE_BACK);
		}
		else {
			if (CheckSoundMem(musicHandle) == 1)
				StopSoundMem(musicHandle);
			DeleteSoundMem(musicHandle);
			loadFlag = FALSE;
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

int SongSelectCover::CalcAlphaWhite() {
	return GetNow() ? 0 : 255;
}

double SongSelectCover::CalcEx() {
	return GetNow() ? 0.7 : 1.0;
}
