#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"

#define BUTTON_POS		HEIGHT * 0.5
#define BUTTON_INTERVAL	HEIGHT * 0.05

//ƒ{ƒ^ƒ“ŠÖŒW
class Button {
public:
	Button(Font *font, char *str, int type, int num, int position = 0);
	void Draw();
	~Button();
private:
	MyDrawText *myDrawText;
	MyDrawRing *myDrawRing;
	MyDrawTriangle *myDrawTriangle;
	MyDrawCircle *myDrawCircle;
	char *s;
	int t, n;
};

#endif