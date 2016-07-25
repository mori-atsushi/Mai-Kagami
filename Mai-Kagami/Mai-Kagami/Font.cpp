#include "Font.h"

//フォント指定
Font::Font() {
	ID[0] = CreateFontToHandle("M+ 1c", 20 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
	ID[1] = CreateFontToHandle("M+ 1c", 24 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
	ID[2] = CreateFontToHandle("M+ 1c", 30 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
	ID[3] = CreateFontToHandle("M+ 1c", 36 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
	ID[4] = CreateFontToHandle("M+ 1c", 40 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
	ID[5] = CreateFontToHandle("M+ 1c", 46 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
	ID[6] = CreateFontToHandle("M+ 1c", 50 / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
}

//フォント取得
int Font::Get(int point) {
	switch (point)
	{
	case 20:
		return ID[0];
	case 24:
		return ID[1];
	case 30:
		return ID[2];
	case 36:
		return ID[3];
	case 40:
		return ID[4];
	case 46:
		return ID[5];
	case 50:
		return ID[6];
	default:
		return ID[0];
	}
}

//フォントデストラクタ
Font::~Font() {
	for (int i = 0; i < FONT_NUM; i++)
		DeleteFontToHandle(ID[i]); //フォントデータを削除
}