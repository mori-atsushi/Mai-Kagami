#ifndef __FONT_H_INCLUDED__
#define __FONT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"

#define FONT_NUM 7

//フォント関係
class Font {
public:
	Font(); //ポイント数セット
	int Get(int point); //フォントID取り出し
	~Font();
private:
	int ID[FONT_NUM]; //フォントID
};

#endif