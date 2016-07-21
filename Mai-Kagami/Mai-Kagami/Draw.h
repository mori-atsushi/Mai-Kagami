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

#endif