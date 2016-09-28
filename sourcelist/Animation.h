#ifndef __ANIMATION_H_INCLUDED__
#define __ANIMATION_H_INCLUDED__

#include "Animation.h"
#define _USE_MATH_DEFINES  // �~����M_PI���g������
#include <math.h>
#include "DxLib.h"

typedef unsigned long MyTime;

class Animation {
public:
	MyTime GetTime();
	void Reset();
	void SetDuration(MyTime);
	enum Easing {
		LINER,			// ���`
		EaseInOut_SINE,	// �����g(�x���x)
		EaseOut_SINE,	// �����g(���x)
		EaseIn_SINE,	// �����g(�x��)
		EaseInOut_QUAD,	// 2����
		LinerInEaseOut_QUAD,	// 1��=>2��
		EaseInLinerOut_QUAD,	// 2��=>1��
		EaseOutBack_QUAD, // �񎟎�(������Ƃ͂ݏo�Ė߂�)
	};
protected:
	double UpdateRate(Easing);
	void SetTime(MyTime);
private:
	MyTime t = 0;		// �A�j���[�V�����̌��ݎ���
	MyTime duration;	// �A�j���[�V�������쎞��
// 	int ease = LINER;	// �A�j���[�V�������
};


#endif