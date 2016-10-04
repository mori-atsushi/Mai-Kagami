#include "Bezier.h"

Bezier::Bezier(const double x1, const double y1, const double x2, const double y2) {
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

//計算
double Bezier::Calc(const double x) {
	double now_x, now_abs, pre_abs = 1, y;
	double t;
	int c = 0;
	const int N = 1000;	// 大きいほど精度良・計算量多

	for (c = 0; c < N + 1; c++) {
		t = (double)c / N;
		now_x = t*t*t + 3 * t*t*(1 - t)*x2 + 3 * t*(1 - t)*(1 - t)*x1;
		now_abs = x - now_x > 0 ? x - now_x : now_x - x;
		if (pre_abs < now_abs) {
			t = (double)(c - 1) / N;
			break;
		}
		pre_abs = now_abs;
	}
	y = t*t*t + 3 * t*t*(1 - t)*y2 + 3 * t*(1 - t)*(1 - t)*y1;

	return y;
}