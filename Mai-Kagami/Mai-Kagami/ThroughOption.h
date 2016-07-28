#ifndef __THROUGHOPTION_H_INCLUDED__
#define __THROUGHOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Common.h"
#include "Font.h"
#include "Draw.h"
#include "Touch.h"
#include "SongSelectDefine.h"

class ThroughOptionButton {
public:
	ThroughOptionButton(Font *font);
	void View();
	void Update(Touch *touch, int scene);
	~ThroughOptionButton();
private:
	Button *button[4];
	MyDrawText *speed[2];
	int sp;
};


#endif