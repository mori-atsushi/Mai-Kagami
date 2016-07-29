#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

//テキスト関係
class MyDrawText : public Color, public Draw2{
public:
	MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void View(); //描画
	void ChangeText(char *str); //テキスト変更
	float GetHeight(); //縦取得
	float GetWidth(); //幅取得
private:
	int f, point; //フォント情報、ポジション情報、フォントサイズ
	std::string s; //文字
};

//複数行のテキスト
class MyDrawTexts : public Color, public Draw {
public:
	MyDrawTexts(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineInterval, const char *colorName = "White");
	void View();
	float GetWidth(); //幅取得
	~MyDrawTexts();
private:
	MyDrawText *myDrawText[256];
	float x, y; //座標
	int l, p; //行数, ポジション情報
	void CalcPos(); //位置計算
};

//アンダーライン付きテキスト
class MyDrawTextLine : public MyDrawText {
public:
	MyDrawTextLine(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName = "White");
	void View();
private:
	float x1, x2, y1, y2, w; //座標、線の太さ
};

#endif