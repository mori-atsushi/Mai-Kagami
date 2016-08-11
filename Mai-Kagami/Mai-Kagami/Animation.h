#ifndef __ANIMATION_H_INCLUDED__
#define __ANIMATION_H_INCLUDED__

#include "Animation.h"

typedef unsigned long MyTime;

class Animation {
public:
	double ProgressRate(MyTime, int, MyTime);
	void Stop();
	enum {
		LINER,
		EASE
	};
private:
	unsigned long t;  // アニメーションの現在時刻
};


#endif