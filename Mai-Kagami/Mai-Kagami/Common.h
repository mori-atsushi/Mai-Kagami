#ifndef __COMMON_H_INCLUDED__
#define __COMMON_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawObject.h"

#define BUTTON_POS		HEIGHT * 0.5
#define BUTTON_INTERVAL	HEIGHT * 0.05

//ƒ{ƒ^ƒ“ŠÖŒW
class Button : public Draw {
public:
	Button(Font *font, const char *str, const int type, const int num, char *colorName="Blue");
	Button(Font *font, const char *str, const int type, const int num, const float x, char *colorName = "Blue");
	Button(Font *font, const char *str, const int num, char *colorName = "Blue");
	Button(Font *font, const char *title, const char *str, const int type, const int num, const float x, const char *colorName);
	void View();
	~Button();
private:
	MyDrawText *myDrawText;
	MyDrawText *descriptionText;
	MyDrawTriangle *myDrawTriangle;
	MyDrawCircle *myDrawCircle;
	MyDrawBox *myDrawBox;
	char *s;
	int t, n;
	void SetType(const int type, const int num, const char *colorName);
};

#endif