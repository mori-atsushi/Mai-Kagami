#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include "DxLib.h"
#include "Main.h"

//FÖW
class Color {
public:
	void Set(char *color);
	int Get();
private:
	int c;
};

//tHgÖW
class Font {
public:
	void Set(int p); //|CgZbg
	int Get(); //tHgIDæèoµ
private:
	int ID; //tHgID
};

//\¦ÊuÖW
class ViewPos {
public :
	void Init(float a, float b, int pos = 0, float len = 0);
	float GetX();
	float GetY();
private:
	float x, y;
};

//eLXgÖW
class MyDrawText {
public:
	void Init(char *s, int a, int b, int pos, int point); // pos=¶ñ¹:0 / ñ¹:1 / Eñ¹:2
	void Draw(); //`æ
	int GetWidth(); //æ¾
private:
	ViewPos viewPos;
	Font font;
	Color color;
	char *str; //¶
	int strLen; //¶ñÌ·³
};

//üÖW
class MyDrawLine {
public:
	void Init(int a, int b, int pos, int length, int width); // pos=¶ñ¹:0 / ñ¹:1 / Eñ¹:2
	void Draw();
private:
	ViewPos viewPos;
	Font font;
	Color color;
	int len; //¶ñÌ·³
	int w;
};

//~ÖW
class MyDrawCircle {
public:
	void Init(int a, int b, int radius);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
};

//Oih[ic^jÖW
class MyDrawRing {
public:
	void Init(int a, int b, int radius, float width);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
	float w;
};

//³Op`ÖW
class MyDrawTriangle {
public:
	void Init(int a, int b, int width, int direction);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int d;
	float w;
};

//lp`ÖW
class MyDrawBox {
public:
	void Init(int a, int b, int width, int height);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int w, h;
};

//æÖW
class MyDrawGraph {
public:
	void Init(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
private:
	ViewPos viewPos;
	int handle;
	double ex;
};

#endif