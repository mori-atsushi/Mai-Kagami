#include "Button.h"

//ボタン
Button::Button(const int num) 
	: Draw(0, BUTTON_POS + num * BUTTON_INTERVAL) {}

//三角形のボタン
TriangleButton::TriangleButton(Font *font, const char *str, const int direction, const int num, char *colorName)
	: Button(num) {
	text = new MyDrawText(font, str, WIDTH * 0.94, GetY() * SIZE_RATE, 2, 30);
	myDrawTriangle2 = new MyDrawTriangle2(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.03, direction, colorName);
}

void TriangleButton::ContentView() {
	myDrawTriangle2->View();
	text->View();
}

TriangleButton::~TriangleButton() {
	delete myDrawTriangle2;
	delete text;
}

//説明文付き三角形のボタン
TriangleButton2::TriangleButton2(Font *font, const char *title, const char *str, const int direction, const int num, const float x, const char *colorName)
	: Button(num) {
	float pos = GetY() * SIZE_RATE;
	text = new MyDrawText(font, title, x, pos - HEIGHT * 0.03, 0, 30, colorName);
	descriptionText = new MyDrawTexts(font, str, x, pos + HEIGHT * 0.01, 0, 20, 15);

	float width = WIDTH * 0.35;
	myDrawBox = new MyDrawBox(x + width / 2, GetY() * SIZE_RATE, width + WIDTH * 0.05, HEIGHT * 0.09, 2, colorName);
	myDrawTriangle2 = new MyDrawTriangle2(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.03, direction, colorName);
}

void TriangleButton2::ContentView() {
	descriptionText->View();
	myDrawBox->View();
	myDrawTriangle2->View();
	text->View();
}

TriangleButton2::~TriangleButton2() {
	delete myDrawTriangle2;
	delete myDrawBox;
	delete descriptionText;
	delete text;
}


//文字右寄せボタン
CircleButton::CircleButton(Font *font, const char *str, const int num, char *colorName) 
	: Button(num) {
	text = new MyDrawText(font, str, WIDTH * 0.94, GetY() * SIZE_RATE, 2, 30);
	myDrawCircle = new MyDrawCircle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.015, 7, colorName);
}

//文字中央寄せボタン
CircleButton::CircleButton(Font *font, const char *str, const int num, const float x, char *colorName)
	: Button(num) {
	text = new MyDrawText(font, str, x, GetY() * SIZE_RATE, 1, 30);
	myDrawCircle = new MyDrawCircle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.015, 7, colorName);
}

void CircleButton::ContentView() {
	myDrawCircle->View();
	text->View();
}

CircleButton::~CircleButton() {
	delete text;
	delete myDrawCircle;
}

//文字が丸の中にあるボタン
CircleButton2::CircleButton2(Font *font, const char *str, const int num, char *colorName)
	: Button(num) {
	float r = WIDTH * 0.045;
	float x = WIDTH - r - 4;
	text = new MyDrawText(font, str, x, GetY() * SIZE_RATE, 1, 30, "Black");
	myDrawCircle = new MyDrawCircle(x, GetY() * SIZE_RATE, r, colorName);
}

void CircleButton2::ContentView() {
	myDrawCircle->View();
	text->View();
}

CircleButton2::~CircleButton2() {
	delete text;
	delete myDrawCircle;
}

//画像付きのボタン
CircleGraphButton::CircleGraphButton(const int num, const char *fileName) 
	: Button(num) {
	float r = WIDTH * 0.075;
	myDrawCircle = new MyDrawCircle(WIDTH, GetY() * SIZE_RATE, r);
	myDrawGraph = new MyDrawGraph(WIDTH  - 35, GetY() * SIZE_RATE, fileName);
}

void CircleGraphButton::Load() {
	myDrawGraph->Load();
}

void CircleGraphButton::ContentView() {
	myDrawCircle->View();
	myDrawGraph->View();
}

CircleGraphButton::~CircleGraphButton() {
	delete myDrawCircle;
	delete myDrawGraph;
}

//画像、テキスト付きのボタン
CircleGraphTextButton::CircleGraphTextButton(Font *font, const char *str, const int num, const char *fileName)
	: Button(num) {
	float x = WIDTH * 0.965;
	float y = GetY() * SIZE_RATE;
	float r = WIDTH * 0.026;
	text = new MyDrawText(font, str, x - r - 12, GetY() * SIZE_RATE, 2, 30);
	myDrawCircle = new MyDrawCircle(x, y, r, "Blue");
	myDrawGraph = new MyDrawGraph(x, y, fileName, 0.6);
}

void CircleGraphTextButton::Load() {
	myDrawGraph->Load();
}

void CircleGraphTextButton::ContentView() {
	text->View();
	myDrawCircle->View();
	myDrawGraph->View();
}

CircleGraphTextButton::~CircleGraphTextButton() {
	delete text;
	delete myDrawCircle;
	delete myDrawGraph;
}