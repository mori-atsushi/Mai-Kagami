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

void ViewPos::Init(int a, int b) {
	x = a; y = b;
}

void ViewPos::Init(int a, int b, int pos, int len) {
	switch (pos) {
	case 0:
		x = a; y = b;
		break;
	case 1:
		x = a - len / 2; y = b;
		break;
	case 2:
		x = a - len; y = b;
		break;
	}
}

int ViewPos::GetX() {
	return x;
}

int ViewPos::GetY() {
	return y;
}

void MyDrawText::Init(char *s, int a, int b, int pos, int point) {
	str = s;
	font.Set(point);
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	viewPos.Init(a, b, pos, strLen);
}

void MyDrawText::Draw() {
	DrawStringToHandle(viewPos.GetX(), viewPos.GetY(), str, color.White(), font.Get()); //文字表示
}

void MyDrawLine::Init(int a, int b, int pos, int length, int width) {
	viewPos.Init(a, b, pos, length);
	w = width / SIZE_RATE;
}

void MyDrawLine::Draw() {
	DrawLine(viewPos.GetX(), viewPos.GetY(), viewPos.GetX() + len, viewPos.GetY(), color.White(), 4 / SIZE_RATE);

}

void MyDrawCircle::Init(int a, int b, int radius) {
	viewPos.Init(a, b);
	r = radius;
}

void  MyDrawCircle::Draw() {
	DrawCircleAA(viewPos.GetX(), viewPos.GetY(), r, 100, color.Blue(), TRUE);
}