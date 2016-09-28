#include "Animation.h"

// �A�j���[�V�����̐i�s�������X�V���Ė߂�l��
// �I������, �^�C�v, �x��
double Animation::UpdateRate(Easing ease) {
	double r, rate;
	if (duration)
		r = (double)t / duration;
	else
		r = 1;
	switch (ease) {
	case EaseInOut_SINE:
		rate = (1 - cos(r * M_PI)) / 2;
		break;
	case EaseOut_SINE:
		rate = sin(r * M_PI / 2);
		break;
	case EaseIn_SINE:
		rate = 1 - cos(r * M_PI / 2);
		break;
	case EaseInOut_QUAD:
		rate = r < 0.5 ? r * r * 2 : - (r - 1) * (r - 1) * 2 + 1;
		break;
	case LinerInEaseOut_QUAD:
		rate = r < 0.5 ? r * 4 / 3 : - (r - 1) * (r - 1) * 4 / 3 + 1;
		break;
	case EaseInLinerOut_QUAD:
		rate = r < 0.5 ? r * r * 4 / 3 : (r * 4 - 1) / 3;
		break;
	case EaseOutBack_QUAD:
		// rate = - (r - 2.0 / 3) * (r - 2.0 / 3) * 3 + 4.0 / 3;
		rate = - (r - 3.0 / 4) * (r - 3.0 / 4) * 2 + 9.0 / 8;
		break;
	case LINER: default:
		rate = r;
		break;
	}
	if (t < duration)
		t++;
	return rate;
}

// �p�����[�^���
// void Animation::SetRate(MyTime _duration, int _ease = LINER) {
void Animation::SetDuration(MyTime _duration) {
	duration = _duration <= 0 ? 0 : _duration;
// 	ease = _ease;
}

// �A�j���[�V���������������ύX (������0������Ύ���������)
void Animation::SetTime(MyTime _t) {
	t = _t;
}

MyTime Animation::GetTime() {
	return t;
}

void Animation::Reset() {
	SetTime(0);
}