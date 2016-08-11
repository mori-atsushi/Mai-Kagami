#ifndef __ANIMATION_H_INCLUDED__
#define __ANIMATION_H_INCLUDED__

#include "Animation.h"
#include <math.h>

#ifndef PI
#define PI 3.1415926535897932
#endif

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