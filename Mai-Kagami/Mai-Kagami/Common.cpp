#include "Common.h"

//ボタン初期化
Button::Button(Font *font, const char *str, const int type, const int num, char *colorName)
	: Draw(WIDTH * 0.94, BUTTON_POS + num * BUTTON_INTERVAL) {
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE, GetY() * SIZE_RATE, 2, 30);
	Set(type, num, colorName);
}

Button::Button(Font *font, const char *str, const int type, const int num, const float x, char *colorName)
	: Draw(x, BUTTON_POS + num * BUTTON_INTERVAL) {
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE, GetY() * SIZE_RATE, 1, 30);
	Set(type, num, colorName);
}

Button::Button(Font *font, const char *str, const int num, char *colorName) 
	: Draw() {
	float r = WIDTH * 0.045;
	Draw::ChangePos(WIDTH - r - 4, BUTTON_POS + num * BUTTON_INTERVAL);
	t = 3;
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE, GetY() * SIZE_RATE, 1, 30, "Black");
	myDrawCircle = new MyDrawCircle(GetX() * SIZE_RATE, GetY() * SIZE_RATE, r, colorName);
}

Button::Button(Font *font, char *title, char *str, int num, char *colorName) : Draw() {
	int pos = BUTTON_POS + num * BUTTON_INTERVAL;
	const int fontSize = 30; //フォントサイズ
	t = 4;
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
		myDrawCircle->View();
		break;
	case 4:
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

void Button::Set(const int type, const int num, char *colorName) {
	t = type;
	switch (t)
	{
	case 0:
		myDrawCircle = new MyDrawCircle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.015, 7, colorName);
		break;
	case 1:
		myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.03, 0, colorName);
		break;
	case 2:
		myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.03, 1, colorName);
		break;
	}
}