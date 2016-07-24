#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <string.h>
#include <math.h>
#include "DxLib.h"
#include "Main.h"

//色関係
class Color {
public:
	void Set(char *color);
	int Get();
private:
	int c;
};

//フォント関係
class Font {
public:
	void Set(int p); //ポイント数セット
	int Get(); //フォントID取り出し
private:
	int ID; //フォントID
};

//表示位置関係
class ViewPos {
public :
	void Init(float a, float b, int pos = 0, float len = 0);
	float GetX();
	float GetY();
private:
	float x, y;
};

//テキスト関係
class MyDrawText {
public:
	void Init(char *s, int a, int b, int pos, int point); // pos=左寄せ:0 / 中央寄せ:1 / 右寄せ:2
	void Draw(); //描画
	int GetWidth(); //幅取得
private:
	ViewPos viewPos;
	Font font;
	Color color;
	char *str; //文字
	int strLen; //文字列の長さ
};

//線関係
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

//円関係
class MyDrawCircle {
public:
	void Init(int a, int b, int radius);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int r;
};

//リング（ドーナツ型）関係
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

//正三角形関係
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

//四角形関係
class MyDrawBox {
public:
	void Init(int a, int b, int width, int height);
	void Draw();
private:
	ViewPos viewPos;
	Color color;
	int w, h;
};

//画像関係
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