#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"

class Color {
public:
	int White(); //白色
	int Blue(); //青色
private:
};

class Font {
public:
	void Set(int p); //ポイント数セット
	int Get(); //フォントID取り出し
private:
	int ID; //フォントID
};

class ViewPos {
public :
	void Init(int a, int b);
	void Init(int a, int b, int pos, int len);
	int GetX();
	int GetY();
private:
	int x, y;
};

class MyDrawText {
public:
	void Init(char *s, int a, int b, int pos, int point); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void Draw();
private:
	ViewPos viewPos;
	Font font;
	Color color;
	char *str; //文字
	int strLen; //文字列の長さ
};

class MyDrawLine {
public:
	void Init(int a, int b, int pos, int length, int width); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void Draw();
private:
	ViewPos viewPos;
	Font font;
	Color color;
	int len; //文字列の長さ
	int w;
};

class MyDrawCircle {
public:
	void Init(int a, int b, int radius);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
};

#endif