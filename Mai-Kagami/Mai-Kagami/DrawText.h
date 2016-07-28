#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

//テキスト関係
class MyDrawText : public Color, public Draw{
public:
	MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void View(); //描画
	void ChangeText(char *str); //テキスト変更
protected:
	float GetHeight(); //縦取得
private:
	float GetWidth(); //幅取得
	int f, p, point; //フォント情報、ポジション情報、フォントサイズ
	float x, y; //座標
	std::string s; //文字
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