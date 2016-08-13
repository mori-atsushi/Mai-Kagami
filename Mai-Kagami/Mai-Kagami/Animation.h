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
protected:
	double UpdateRate();
	void SetRate(MyTime, int);
	void SetTime(MyTime);
	enum {
		LINER,
		EASE
	};
private:
	MyTime t = 0;		// アニメーションの現在時刻
	MyTime duration;	// アニメーション動作時間
	int ease = LINER;	// アニメーション種類
};


#endif