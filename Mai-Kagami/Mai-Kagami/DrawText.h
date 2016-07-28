#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

//テキスト関係
class MyDrawText {
public:
	MyDrawText(Font *font, char *s, int a, int b, int pos, int point, char *colorName = "White"); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void Draw(); //描画
	void ChangeText(char *s);
	int GetWidth(); //幅取得
	~MyDrawText();
private:
	int f;
	ViewPos *viewPos;
	Color *color;
	std::string str; //文字
};

#endif