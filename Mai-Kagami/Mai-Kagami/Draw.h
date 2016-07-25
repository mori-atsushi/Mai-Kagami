#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include "DxLib.h"
#include "Main.h"

//FÖW
class Color {
public:
	Color(char *color);
	int Get();
private:
	int c;
};

//tHgÖW
class Font {
public:
	Font(int p); //|CgZbg
	int Get(); //tHgIDæèoµ
	~Font();
private:
	int ID; //tHgID
};

//\¦ÊuÖW
class ViewPos {
public :
	ViewPos(float a, float b, int pos = 0, float len = 0);
	void ChangePos(float a, float b);
	float GetX();
	float GetY();
private:
	float x, y;
};

//eLXgÖW
class MyDrawText {
public:
	MyDrawText(char *s, int a, int b, int pos, int point, char *colorName = "White"); // pos=¶ñ¹:0 / ñ¹:1 / Eñ¹:2
	void Draw(); //`æ
	int GetWidth(); //æ¾
	~MyDrawText();
private:
	Font *font;
	Color *color;
	char *str; //¶
	int x, y, p;
};

//üÖW
class MyDrawLine {
public:
	MyDrawLine(int a, int b, int pos, int length, int width); // pos=¶ñ¹:0 / ñ¹:1 / Eñ¹:2
	void Draw();
	~MyDrawLine();
private:
	ViewPos *viewPos;
	Color *color;
	int len; //¶ñÌ·³
	int w;
};

//~ÖW
class MyDrawCircle {
public:
	MyDrawCircle(int a, int b, int radius);
	void Draw();
	~MyDrawCircle();
private:
	ViewPos *viewPos;
	Color *color;
	int r;
};

//Oih[ic^jÖW
class MyDrawRing {
public:
	MyDrawRing(int a, int b, int radius, float width, char *colorName = "Blue");
	void Draw();
	~MyDrawRing();
private:
	ViewPos *viewPos;
	Color *color;
	int r;
	float w;
};

//³Op`ÖW
class MyDrawTriangle {
public:
	MyDrawTriangle(int a, int b, int width, int direction);
	void Draw();
	~MyDrawTriangle();
private:
	ViewPos *viewPos;
	Color *color;
	int d;
	float w;
};

//lp`ÖW
class MyDrawBox {
public:
	MyDrawBox(int a, int b, int width, int height, char *colorName = "White");
	void Draw();
	~MyDrawBox();
private:
	ViewPos *viewPos;
	Color *color;
	int w, h;
};

//æÖW
class MyDrawGraph {
public:
	MyDrawGraph(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	~MyDrawGraph();
private:
	ViewPos *viewPos;
	int handle;
	double ex;
};

#endif