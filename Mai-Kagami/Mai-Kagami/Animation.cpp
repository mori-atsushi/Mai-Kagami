#include "Animation.h"

// アニメーションの進行割合を更新して戻り値へ
// 終了時刻, タイプ, 遅延
double Animation::UpdateRate() {
	double r, rate;
	if (duration)
		r = (double)t / duration;
	else
		r = 1;
	switch (ease) {
	case SINE:
		rate = (1 - cos(r * M_PI)) / 2;
		break;
	case SINE_2:
		rate = sin(r * M_PI / 2);
		break;
	case SINE_3:
		rate = 1 - cos(r * M_PI / 2);
		break;
	case QUAD:
		rate = r < 0.5 ? r * r * 2 : - (r - 1) * (r - 1) * 2 + 1;
		break;
	case LINER_QUAD:
		rate = r < 0.5 ? r * 4 / 3 : - (r - 1) * (r - 1) * 4 / 3 + 1;
		break;
	case QUAD_LINER:
		rate = r < 0.5 ? r * r * 4 / 3 : (r * 4 - 1) / 3;
		break;
	case LINER: default:
		rate = r;
		break;
	}
	if (t < duration)
		t++;
	return rate;
}

// パラメータ代入
void Animation::SetRate(MyTime _duration, int _ease = LINER) {
	duration = _duration <= 0 ? 0 : _duration;
	ease = _ease;
}

// アニメーション時刻を強制変更 (引数に0を入れれば時刻初期化)
void Animation::SetTime(MyTime _t) {
	t = _t;
}

MyTime Animation::GetTime() {
	return t;
}

void Animation::Reset() {
	SetTime(0);
}