#ifndef __DRAWOBJECT_H_INCLUDED__
#define __DRAWOBJECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"

//ê¸ä÷åW
class MyDrawLine {
public:
	MyDrawLine(int a, int b, int pos, int length, int width); // pos=ç∂äÒÇπ:0 / íÜâõäÒÇπ:1 / âEäÒÇπ:2
	void Draw();
	~MyDrawLine();
private:
	ViewPos *viewPos;
	Color *color;
	int len; //ï∂éöóÒÇÃí∑Ç≥
	int w;
};

//â~ä÷åW
class MyDrawCircle {
public:
	MyDrawCircle(int a, int b, int radius, char *colorName = "Blue");
	MyDrawCircle(int a, int b, int radius, float width, char *colorName = "Blue");
	void Draw();
	~MyDrawCircle();
private:
	ViewPos *viewPos;
	Color *color;
	int r;
	float w;
};

//ê≥éOäpå`ä÷åW
class MyDrawTriangle {
public:
	MyDrawTriangle(int a, int b, int width, int direction, char *colorName = "Blue");
	void Draw();
	~MyDrawTriangle();
private:
	ViewPos *viewPos;
	Color *color;
	int d;
	float w;
};

//éläpå`ä÷åW
class MyDrawBox {
public:
	MyDrawBox(int a, int b, int width, int height, char *colorName = "White");
	MyDrawBox(int a, int b, int width, int height, float line, char *colorName = "Blue");
	void Draw();
	~MyDrawBox();
private:
	ViewPos *viewPos;
	Color *color;
	int w, h;
	float l;
};

#endif