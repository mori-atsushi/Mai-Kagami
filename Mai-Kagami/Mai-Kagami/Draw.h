#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include <string>
#include "DxLib.h"
#include "Main.h"
#include "Font.h"

//FŠÖŒW
class Color {
public:
	Color(char *color);
	int Get();
private:
	int c;
};

//•\¦ˆÊ’uŠÖŒW
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

//ƒeƒLƒXƒgŠÖŒW
class MyDrawText {
public:
	MyDrawText(Font *font, char *s, int a, int b, int pos, int point, char *colorName = "White"); // pos=¶Šñ‚¹:0 / ’†‰›Šñ‚¹:1 / ‰EŠñ‚¹:2
	void Draw(); //•`‰æ
	void ChangeText(char *s);
	int GetWidth(); //•æ“¾
	~MyDrawText();
private:
	int f;
	ViewPos *viewPos;
	Color *color;
	std::string str; //•¶š
};

//üŠÖŒW
class MyDrawLine {
public:
	MyDrawLine(int a, int b, int pos, int length, int width); // pos=¶Šñ‚¹:0 / ’†‰›Šñ‚¹:1 / ‰EŠñ‚¹:2
	void Draw();
	~MyDrawLine();
private:
	ViewPos *viewPos;
	Color *color;
	int len; //•¶š—ñ‚Ì’·‚³
	int w;
};

//‰~ŠÖŒW
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

//³OŠpŒ`ŠÖŒW
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

//lŠpŒ`ŠÖŒW
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

//‰æ‘œŠÖŒW
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

//“®‰æŠÖŒW
class MyDrawMovie {
public:
	MyDrawMovie(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	void ChangeSpeed(double speed);
	~MyDrawMovie();
private:
	ViewPos *viewPos;
	int handle; //“®‰æ‚Ìƒnƒ“ƒhƒ‹
	double ex; //“®‰æ‚ÌƒTƒCƒY
};

#endif