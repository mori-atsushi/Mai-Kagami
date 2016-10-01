#ifndef __TOUCH_H_INCLUDED__
#define __TOUCH_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Serial.h"

class Touch {
public:
	Touch();
	void Check(); //確認
	int Get(int num); //取得
	boolean Input(int num, int wait = 30, int duration = 10);  // キーが入力されているか
	boolean Input2(int num, int wait1 = 30, int duration1 = 10, int wait2 = 100, int duration2 = 6);  // キーが入力されているか
	~Touch();
private:
	Serial *serial;
	int key[5];
};


#endif