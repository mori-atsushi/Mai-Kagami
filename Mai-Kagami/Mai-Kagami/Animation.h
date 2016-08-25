#ifndef __ANIMATION_H_INCLUDED__
#define __ANIMATION_H_INCLUDED__

#include "Animation.h"
#define _USE_MATH_DEFINES  // 円周率M_PIを使うため
#include <math.h>
#include "DxLib.h"

typedef unsigned long MyTime;

class Animation {
public:
	MyTime GetTime();
	void Reset();
	enum {
		LINER,		// 線形
		SINE,		// 正弦波(遅早遅)
		SINE_2,		// 正弦波(早遅)
		SINE_3,		// 正弦波(遅早)
		QUAD,		// 2次式
		LINER_QUAD,	// 1次=>2次
		QUAD_LINER,	// 2次=>1次
	};
protected:
	double UpdateRate();
	void SetRate(MyTime, int);
	void SetTime(MyTime);
private:
	MyTime t = 0;		// アニメーションの現在時刻
	MyTime duration;	// アニメーション動作時間
	int ease = LINER;	// アニメーション種類
};


#endif