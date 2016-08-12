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
	EASE:
		rate = (1 - cos(r * M_PI)) / 2;
	LINER: default:
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