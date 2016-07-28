#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#include "Main.h"

//êFä÷åW
class Color {
public:
	Color(char *color);
	int Get();
private:
	int c;
};

//ï\é¶à íuä÷åW
class ViewPos {
public :
	ViewPos(float a, float b, int pos = 0, float len = 0);
	void ChangePos(float a, float b);
	void ChangeLenth( float len);
	float GetX();
	float GetY();
private:
	float x, y;
	float xx, yy;
	int p;
};
#endif