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
private:
	int GetWidth(); //幅取得
	int f, p; //フォント情報、ポジション情報
	std::string s; //文字
};

#endif