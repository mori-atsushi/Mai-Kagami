#ifndef __TOUCH_H_INCLUDED__
#define __TOUCH_H_INCLUDED__

#include "DxLib.h"

class Touch {
public:
	void Check();
	int Get(int num);
private:
	int key[5];
};


#endif