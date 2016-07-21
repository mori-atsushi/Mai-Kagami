#include "Draw.h"

int Color::White() {
	return GetColor(255, 255, 255); //白色
}

int Color::Blue() {
	return GetColor(127, 210, 234); //青色
}

void Font::Set(int p) {
	ID = CreateFontToHandle("遊ゴシック", p / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING_EDGE);
}

int Font::Get() {
	return ID;
}