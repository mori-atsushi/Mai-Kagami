#ifndef __TOUCH_H_INCLUDED__
#define __TOUCH_H_INCLUDED__

#include "DxLib.h"

class Touch {
public:
	void Check(); // �m�F
	int Get(int num); // �擾
	boolean Input(int num, int wait = 30, int duration = 10);  // �L�[�����͂���Ă��邩
	boolean Input2(int num, int wait1 = 30, int duration1 = 10, int wait2 = 100, int duration2 = 6);  // �L�[�����͂���Ă��邩
private:
	int key[5];
};


#endif