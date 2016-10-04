#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "DecorationItem.h"
#include "Draw.h"

enum Alignment{ALIGNMENT_LEFT, ALIGNMENT_CENTER, ALIGNMENT_RIGHT};

//テキスト関係
class MyDrawText : public Color, public Draw2{
public:
	MyDrawText(DecorationItem *decorationItem, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void ContentView(); //描画
	void ChangeText(char *str); //テキスト変更
	void ChangeFont(DecorationItem *decorationItem, const int point); //フォントサイズ変更
	float GetHeight(); //縦取得
	float GetWidth(); //幅取得
protected:
	int decorationItem, point; //フォント情報、ポジション情報、フォントサイズ
	std::string s; //文字
};

//縦書きテキスト
class MyDrawTextV : public MyDrawText {
public:
	MyDrawTextV(DecorationItem *decorationItem, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void ContentView();
private:
	float RotCenterX;
};

//複数行のテキスト
class MyDrawTexts : public Color, public Draw {
public:
	MyDrawTexts(DecorationItem *decorationItem, const char *str, const float x, const float y, const int pos, const int point, const float lineInterval, const char *colorName = "White");
	void ContentView();
	void ChangePos(const float x, const float y);
	void ChangeText(const char *str); //テキスト変更
	float GetWidth(); //幅取得
	float GetHeight(); //高さ取得
	~MyDrawTexts();
private:
	MyDrawText *myDrawText[256];
	DecorationItem *decorationItem;
	int l = 0, p, inter, point; //行数, ポジション情報, 間隔、ポイント数
	char color[100];
};

//アンダーライン付きテキスト
class MyDrawTextLine : public Color, public Draw {
public:
	MyDrawTextLine(DecorationItem *decorationItem, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName = "White");
	void ContentView();
	void ChangePos(const float x, const float y);
	void ChangeText(char *str); //テキスト変更
	~MyDrawTextLine();
private:
	MyDrawText *myDrawText;
	int pos;
	float x1, x2, y1, y2, w, l; //座標、線の太さ、線の長さ
};

#endif