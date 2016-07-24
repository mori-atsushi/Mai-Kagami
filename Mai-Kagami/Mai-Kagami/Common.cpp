#include "Common.h"

//ボタン初期化
void Button::Init(char *str, int type, int num) {
	int pos = BUTTON_POS + num * BUTTON_INTERVAL;
	myDrawText.Init(str, WIDTH * 0.94, pos - HEIGHT * 0.0085, 2, 30);
	t = type;
	switch (t)
	{
	case 0:
		myDrawRing.Init(WIDTH * 0.97, pos, WIDTH * 0.015, 7);
		break;
	case 1:
		myDrawTriangle.Init(WIDTH * 0.97, pos, WIDTH * 0.03, 0);
		break;
	case 2:
		myDrawTriangle.Init(WIDTH * 0.97, pos, WIDTH * 0.03, 1);
		break;
	case 3:
		myDrawText.Init(str, WIDTH * 0.955, pos - HEIGHT * 0.0085, 1, 30);
		myDrawCircle.Init(WIDTH * 0.955, pos, WIDTH * 0.042);
		break;
	}
}

//ボタン表示
void Button::Draw() {
	switch (t)
	{
	case 0:
		myDrawRing.Draw();
		break;
	case 1:
	case 2:
		myDrawTriangle.Draw();
		break;
	case 3:
		myDrawCircle.Draw();
		break;
	}
	myDrawText.Draw();
}