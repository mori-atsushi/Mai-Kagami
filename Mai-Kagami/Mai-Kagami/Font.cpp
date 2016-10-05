#include "Font.h"

//フォントロード
Font::Font() {
	for (int i = 0; i < FONT_NUM; i++) {
		this->id[p[i]] = CreateFontToHandle("M+ 1c", p[i] / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
		printfDx("%d:%d ", p[i], this->id[p[i]]);
	}
}

//フォント取得
int Font::GetFont(int point) {
//	printfDx("%d", p[0]);
	return id[point];
	return 0;
}

//フォントデストラクタ
Font::~Font() {
	for (int i = 0; i < FONT_NUM; i++)
		DeleteFontToHandle(id[p[i]]); //フォントデータを削除
}