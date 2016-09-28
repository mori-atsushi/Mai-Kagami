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
	coverWhite->Load();
	Change(0, max);

	coverGraph->ChangePos(WIDTH * 0.5, CalcY());
	coverGraph->SetAlpha(CalcAlpha());
	coverGraph->ChangeEx(CalcEx());
	coverWhite->ChangePos(WIDTH * 0.5, CalcY());
	coverWhite->SetAlpha(CalcAlphaWhite());
	coverWhite->ChangeEx(CalcEx());
	playFlag = FALSE;
}

void SongSelectCover::Release() {
	coverGraph->Release();
	coverWhite->Release();
}

// �\���ʒu�̌v�Z
void SongSelectCover::Update(int num, int max) {
	// static int t = 0;	// �ז� Jaity
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
	else if (coverGraph->GetTime() == 0) { // �ŏ�����
		coverGraph->SetDuration(duration);
		coverGraph->SetPosAnimation(WIDTH * 0.5, y, Animation::EaseOut_SINE);
		coverWhite->SetDuration(duration);
		coverWhite->SetPosAnimation(WIDTH * 0.5, y, Animation::EaseOut_SINE);
	}

	coverGraph->SetExAnimation(CalcEx(), Animation::EaseOut_SINE);
	coverGraph->SetAlphaAnimation(CalcAlpha(), Animation::EaseOut_SINE);
	coverWhite->SetExAnimation(CalcEx(), Animation::EaseOut_SINE);
	coverWhite->SetAlphaAnimation(CalcAlphaWhite(), Animation::EaseOut_SINE);

	coverGraph->Update(); // �A�j���[�V�����X�V
	coverWhite->Update();
}

void SongSelectCover::Draw(int scene) {
	int n = GetNow();
	if (n <= 6) {	// �ړ������l���� 5 ���`��
		coverWhite->View();
		coverGraph->View();
	}
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
// 			PlayMusic(music, DX_PLAYTYPE_LOOP); // �d���̂ňꎞ�I�ɏ��� Jaity
			playFlag = TRUE;
		}
		else if (n != 0) {
			playFlag = FALSE;
		}
		break;
	}
}

// �Ȃ̈ʒuID��ύX
void SongSelectCover::Change(int num, int max) {
	int n = GetNow();
	n = (n + num + max + 2) % max - 2;
	SetNow(n);
}

// y���W���Z�o���Ď擾
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
