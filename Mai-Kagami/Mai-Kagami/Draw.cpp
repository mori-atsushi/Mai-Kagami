#include "Draw.h"

//色指定
Color::Color(char *color) {
	if(!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //白色
	else if(!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //青色
	else if(!strcmp(color, "Black"))
		c = GetColor(0, 0, 0); //黒色
	else if (!strcmp(color, "Yellow"))
		c = GetColor(255, 255, 0); //黄色
}

//色取得
int Color::Get() {
	return c;
}

//ポジション指定(右寄せ/中央寄せ/左寄せ)
ViewPos::ViewPos(float a, float b, int pos, float len) {
	p = pos;
	x = a / SIZE_RATE; y = b / SIZE_RATE;
	xx = x; yy = y;
	switch (p) {
	case 1:
		x -= len / 2;
		break;
	case 2:
		x -= len;
		break;
	}
}

void ViewPos::ChangePos(float a, float b) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
}

void ViewPos::ChangeLenth(float len) {
	x = xx; y = yy;
	switch (p) {
	case 1:
		x -= len / 2;
		break;
	case 2:
		x -= len;
		break;
	}
}

//x座標取得
float ViewPos::GetX() {
	return x;
}

//y座標取得
float ViewPos::GetY() {
	return y;
}