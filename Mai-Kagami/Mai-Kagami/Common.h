#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"

#define BUTTON_POS		HEIGHT * 0.5
#define BUTTON_INTERVAL	HEIGHT * 0.05

//ƒ{ƒ^ƒ“ŠÖŒW
class Button {
public:
	Button(Font *font, char *str, int type, int num);
	Button(Font *font, char *title, char *str, int num, char *colorName);
	void Draw();
	~Button();
private:
	MyDrawText *myDrawText;
	MyDrawText *descriptionText;
	MyDrawTriangle *myDrawTriangle;
	MyDrawCircle *myDrawCircle;
	MyDrawBox *myDrawBox;
	char *s;
	int t, n;
};

#endif