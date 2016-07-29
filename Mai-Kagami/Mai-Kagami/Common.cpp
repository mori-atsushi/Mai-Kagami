#include "Common.h"

//ボタン初期化
Button::Button(Font *font, const char *str, const int type, const int num, char *colorName)
	: Draw(WIDTH * 0.94, BUTTON_POS + num * BUTTON_INTERVAL) {
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE, GetY() * SIZE_RATE, 2, 30);
	SetType(type, num, colorName);
}

Button::Button(Font *font, const char *str, const int type, const int num, const float x, char *colorName)
	: Draw(x, BUTTON_POS + num * BUTTON_INTERVAL) {
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE, GetY() * SIZE_RATE, 1, 30);
	SetType(type, num, colorName);
}

Button::Button(Font *font, const char *title, const char *str, const int type, const int num, const float x, const char *colorName)
	: Draw(x, BUTTON_POS + num * BUTTON_INTERVAL) {
	int pos = BUTTON_POS + num * BUTTON_INTERVAL;
	t = type;
	myDrawText = new MyDrawText(font, title, GetX() * SIZE_RATE, pos - HEIGHT * 0.03, 0, 30, colorName);
	descriptionText = new MyDrawText(font, str, GetX() * SIZE_RATE, pos, 0, 20);
	float width = WIDTH * 0.35;
	myDrawBox = new MyDrawBox(GetX() * SIZE_RATE + width / 2, GetY() * SIZE_RATE, width + WIDTH * 0.05, HEIGHT * 0.09, 2, colorName);
	SetType(type, num, colorName);
}

Button::Button(Font *font, const char *str, const int num, char *colorName) : Draw() {
	float r = WIDTH * 0.045;
	Draw::ChangePos(WIDTH - r - 4, BUTTON_POS + num * BUTTON_INTERVAL);
	t = 4;
	myDrawText = new MyDrawText(font, str, GetX() * SIZE_RATE, GetY() * SIZE_RATE, 1, 30, "Black");
	myDrawCircle = new MyDrawCircle(GetX() * SIZE_RATE, GetY() * SIZE_RATE, r, colorName);
}

//ボタン表示
void Button::View() {
	switch (t)
	{
	case 0:
	case 4:
		myDrawCircle->View();
		break;
	case 3:
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

void Button::SetType(const int type, const int num, const char *colorName) {
	t = type;
	float x = WIDTH * 0.97;
	switch (t)
	{
	case 0:
		myDrawCircle = new MyDrawCircle(x, GetY() * SIZE_RATE, WIDTH * 0.015, 7, colorName);
		break;
	case 1:
		myDrawTriangle = new MyDrawTriangle(x, GetY() * SIZE_RATE, WIDTH * 0.03, 0, colorName);
		break;
	case 2:
		myDrawTriangle = new MyDrawTriangle(x, GetY() * SIZE_RATE, WIDTH * 0.03, 1, colorName);
		break;
	case 3:
		myDrawTriangle = new MyDrawTriangle(x, GetY() * SIZE_RATE, WIDTH * 0.03, 2, colorName);
		break;
	}
}