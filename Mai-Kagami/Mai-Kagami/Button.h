#ifndef __BUTTON_H_INCLUDED__
#define __BUTTON_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"

#define BUTTON_POS HEIGHT * 0.5
#define BUTTON_INTERVAL HEIGHT * 0.05

//ボタン関係
class Button : public Draw {
public:
	Button(const int num);
	virtual void View() = 0; //表示用関数
};

//三角形のボタン
class TriangleButton : public Button {
public:
	TriangleButton(Font *font, const char *str, const int direction, const int num, char *colorName = "Blue");
	void View();
	~TriangleButton();
private:
	MyDrawTriangle *myDrawTriangle;
	MyDrawText *text; //ボタンの文字
};

//説明文付き三角形のボタン
class TriangleButton2 : public Button {
public:
	TriangleButton2(Font *font, const char *title, const char *str, const int direction, const int num, const float x, const char *colorName);
	void View();
	~TriangleButton2();
private:
	MyDrawText *text; //ボタンの文字
	MyDrawTexts *descriptionText;
	MyDrawTriangle *myDrawTriangle;
	MyDrawBox *myDrawBox;
};

//円のボタン
class CircleButton : public Button {
public:
	CircleButton(Font *font, const char *str, const int num, char *colorName = "Blue"); //文字右寄せボタン
	CircleButton(Font *font, const char *str, const int num, const float x, char *colorName = "Blue"); //文字中央寄せボタン
	void View();
	~CircleButton();
private:
	MyDrawText *text; //ボタンの文字
	MyDrawCircle *myDrawCircle;
};

//文字が丸の中にあるボタン
class CircleButton2 : public Button {
public:
	CircleButton2(Font *font, const char *str, const int num, char *colorName = "Blue");
	void View();
	~CircleButton2();
private:
	MyDrawText *text; //ボタンの文字
	MyDrawCircle *myDrawCircle;
};

//画像付きのボタン
class CircleGraphButton : public Button {
public:
	CircleGraphButton(const int num, const char *fileName);
	void View();
	void Load();
	~CircleGraphButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawGraph *myDrawGraph;
};

#endif