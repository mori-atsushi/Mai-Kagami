#include "Common.h"

//ボタン初期化
Button::Button(Font *font, char *str, int type, int num, int position) {
	int pos = BUTTON_POS + num * BUTTON_INTERVAL;
	const int fontSize = 30; //フォントサイズ
	t = type;
	switch (t)
	{
	case 0:
		myDrawText = new MyDrawText(font, str, WIDTH * 0.94, pos - HEIGHT * 0.0085, 2, fontSize);
		myDrawRing = new MyDrawRing(WIDTH * 0.97, pos, WIDTH * 0.015, 7);
		break;
	case 1:
		myDrawText = new MyDrawText(font, str, WIDTH * 0.94, pos - HEIGHT * 0.0085, 2, fontSize);
		myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, pos, WIDTH * 0.03, 0);
		break;
	case 2:
		myDrawText = new MyDrawText(font, str, WIDTH * 0.94, pos - HEIGHT * 0.0085, 2, fontSize);
		myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, pos, WIDTH * 0.03, 1);
		break;
	case 3:
		myDrawText = new MyDrawText(font, str, WIDTH * 0.955, pos - HEIGHT * 0.0085, 1, fontSize);
		myDrawCircle = new MyDrawCircle(WIDTH * 0.955, pos, WIDTH * 0.042);
		break;
	case 4:
		myDrawText = new MyDrawText(font, str, WIDTH * 0.75, pos - HEIGHT * 0.0085, 1, fontSize);
		myDrawRing = new MyDrawRing(WIDTH * 0.97, pos, WIDTH * 0.015, 7, "White");
		break;
	}
}

//ボタン表示
void Button::Draw() {
	switch (t)
	{
	case 0:
	case 4:
		myDrawRing->Draw();
		break;
	case 1:
	case 2:
		myDrawTriangle->Draw();
		break;
	case 3:
		myDrawCircle->Draw();
		break;
	}
	myDrawText->Draw();
}

Button::~Button() {
	delete myDrawText;
	delete myDrawRing;
	delete myDrawTriangle;
	delete myDrawCircle;
}