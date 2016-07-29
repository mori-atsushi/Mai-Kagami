#include "Common.h"

//ボタン初期化
Button::Button(Font *font, char *str, int type, int num) : Draw() {
	int pos = BUTTON_POS + num * BUTTON_INTERVAL;
	const int fontSize = 30; //フォントサイズ
	Draw::ChangePos(WIDTH, pos);
	t = type;
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE - WIDTH * 0.06, GetY() * SIZE_RATE, 2, fontSize);
	switch (t)
	{
	case 0:
		myDrawCircle = new MyDrawCircle(WIDTH * 0.97, pos, WIDTH * 0.015, 7);
		break;
	case 1:
		myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, pos, WIDTH * 0.03, 0);
		break;
	case 2:
		myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, pos, WIDTH * 0.03, 1);
		break;
	case 3:
		myDrawText = new MyDrawText(font, str, WIDTH * 0.955, pos, 1, fontSize, "Black");
		myDrawCircle = new MyDrawCircle(WIDTH * 0.955, pos, WIDTH * 0.042);
		break;
	case 4:
		myDrawText->ChangePos(GetX() * SIZE_RATE - WIDTH * 0.25, GetY() * SIZE_RATE);
		myDrawCircle = new MyDrawCircle(WIDTH * 0.97, pos, WIDTH * 0.015, 7, "White");
		break;
	}
}

Button::Button(Font *font, char *title, char *str, int num, char *colorName) : Draw() {
	int pos = BUTTON_POS + num * BUTTON_INTERVAL;
	const int fontSize = 30; //フォントサイズ
	t = 5;
	myDrawText = new MyDrawText(font, title, WIDTH * 0.57, pos - HEIGHT * 0.03, 0, fontSize, colorName);
	descriptionText = new MyDrawText(font, str, WIDTH * 0.57, pos, 0, 20);
	myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, pos, WIDTH * 0.03, 2, colorName);
	myDrawBox = new MyDrawBox(WIDTH * 0.74, pos, WIDTH * 0.4, HEIGHT * 0.09, 2, colorName);
}

//ボタン表示
void Button::View() {
	switch (t)
	{
	case 0:
	case 3:
	case 4:
		myDrawCircle->View();
		break;
	case 5:
		descriptionText->View();
		myDrawBox->View();
	case 1:
	case 2:
		myDrawTriangle->View();
		break;
	}
	myDrawText->View();
}

Button::~Button() {
	delete myDrawText;
	delete myDrawTriangle;
	delete myDrawCircle;
	delete myDrawBox;
}