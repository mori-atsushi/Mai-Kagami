#include "Font.h"

//フォントロード
Font::Font() {
	for (int i = 0; i < FONT_NUM; i++)
		this->id[p[i]] = CreateFontToHandle("M+ 1c", p[i] / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
}

//フォント取得
int Font::GetFont(int point) {
	return id[point];
}

//フォントデストラクタ
Font::~Font() {
	for (int i = 0; i < FONT_NUM; i++)
		DeleteFontToHandle(id[p[i]]); //フォントデータを削除
}