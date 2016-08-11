#include "Animation.h"
#include <math.h>
#define PI 3.1415926535897932

// アニメーションの進行割合を返す
// 終了時刻, タイプ, 遅延
double Animation::ProgressRate(MyTime end, int ease = LINER, MyTime delay = 0) {
	double r, rate;
	r = (double)(t - delay) / (end - delay);
	switch (ease) {
	EASE:
		rate = (1 - cos(r * PI)) / 2;
	LINER: default:
		rate = r;
		break;
	}
	t = ++t % (end + delay);
	return rate;
}

// アニメーション停止・リセット
void Animation::Stop() {
	t = 0;
}