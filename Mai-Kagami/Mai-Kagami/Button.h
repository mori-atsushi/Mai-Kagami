#ifndef __BUTTON_H_INCLUDED__
#define __BUTTON_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"
#include "Touch.h"

#define BUTTON_POS HEIGHT * 0.5
#define BUTTON_INTERVAL HEIGHT * 0.05

//ボタン関係
class Button : public Draw {
public:
	Button(const int num, Touch *touch);
	int GetTouch(); //そのボタンが押されているフレーム数を取得
	void SetMode(bool mode);	//ボタンの有効、無効を切り替え(true:有効、false:無効)
private:
	virtual void ContentView() = 0; //表示用関数
	Touch *touch; //タッチ
	int num; //ボタン番号
	bool mode = true;	//true:有効、false:無効
};

//三角形のボタン
class TriangleButton : public Button {
public:
	TriangleButton(DecorationItem *decorationItem, Touch *touch, const char *str, const int direction, const int num, char *colorName = "Blue");
	void ContentView();
	~TriangleButton();
private:
	MyDrawTriangle2 *myDrawTriangle2;
	MyDrawText *text; //ボタンの文字
};

//説明文付き三角形のボタン
class TriangleButton2 : public Button {
public:
	TriangleButton2(DecorationItem *decorationItem, Touch *touch, const char *title, const char *str, const int direction, const int num, const float x, const char *colorName);
	void ContentView();
	~TriangleButton2();
private:
	MyDrawText *text; //ボタンの文字
	MyDrawTexts *descriptionText;
	MyDrawTriangle2 *myDrawTriangle2;
	MyDrawBox *myDrawBox;
};

//円のボタン
class CircleButton : public Button {
public:
	CircleButton(DecorationItem *decorationItem, Touch *touch, const char *str, const int num, char *colorName = "Blue"); //文字右寄せボタン
	CircleButton(DecorationItem *decorationItem, Touch *touch, const char *str, const int num, const float x, char *colorName = "Blue"); //文字中央寄せボタン
	void ContentView();
	~CircleButton();
private:
	MyDrawText *text; //ボタンの文字
	MyDrawCircle *myDrawCircle;
};

//文字が丸の中にあるボタン
class CircleButton2 : public Button {
public:
	CircleButton2(DecorationItem *decorationItem, Touch *touch, const char *str, const int num, char *colorName = "Blue");
	void ContentView();
	void SetMode(bool mode);
	~CircleButton2();
private:
	MyDrawText *text; //ボタンの文字
	MyDrawCircle *myDrawCircle;
	char *colorName;
};

//画像付きのボタン
class CircleGraphButton : public Button {
public:
	CircleGraphButton(Touch *touch, const int num, const char *fileName);
	void ContentView();
	void Load();
	void Release();
	~CircleGraphButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawGraph *myDrawGraph;
};

//画像、テキスト付きのボタン
class CircleGraphTextButton : public Button {
public:
	CircleGraphTextButton(DecorationItem *decorationItem, Touch *touch, const char *str, const int num, const char *fileName);
	void Load();
	void ContentView();
	void Release();
	~CircleGraphTextButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawGraph *myDrawGraph;
	MyDrawText *text;
};

#endif