#include "Button.h"

//�{�^��
Button::Button(const int num) 
	: Draw(0, BUTTON_POS + num * BUTTON_INTERVAL) {}

//�O�p�`�̃{�^��
TriangleButton::TriangleButton(Font *font, const char *str, const int direction, const int num, char *colorName)
	: Button(num) {
	text = new MyDrawText(font, str, WIDTH * 0.94, GetY() * SIZE_RATE, 2, 30);
	myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.03, direction, colorName);
}

void TriangleButton::View() {
	myDrawTriangle->View();
	text->View();
}

TriangleButton::~TriangleButton() {
	delete myDrawTriangle;
	delete text;
}

//�������t���O�p�`�̃{�^��
TriangleButton2::TriangleButton2(Font *font, const char *title, const char *str, const int direction, const int num, const float x, const char *colorName)
	: Button(num) {
	float pos = GetY() * SIZE_RATE;
	text = new MyDrawText(font, title, x, pos - HEIGHT * 0.03, 0, 30, colorName);
	descriptionText = new MyDrawTexts(font, str, x, pos + HEIGHT * 0.01, 0, 20, 15);

	float width = WIDTH * 0.35;
	myDrawBox = new MyDrawBox(x + width / 2, GetY() * SIZE_RATE, width + WIDTH * 0.05, HEIGHT * 0.09, 2, colorName);
	myDrawTriangle = new MyDrawTriangle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.03, direction, colorName);
}

void TriangleButton2::View() {
	descriptionText->View();
	myDrawBox->View();
	myDrawTriangle->View();
	text->View();
}

TriangleButton2::~TriangleButton2() {
	delete myDrawTriangle;
	delete myDrawBox;
	delete descriptionText;
	delete text;
}


//�����E�񂹃{�^��
CircleButton::CircleButton(Font *font, const char *str, const int num, char *colorName) 
	: Button(num) {
	text = new MyDrawText(font, str, WIDTH * 0.94, GetY() * SIZE_RATE, 2, 30);
	myDrawCircle = new MyDrawCircle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.015, 7, colorName);
}

//���������񂹃{�^��
CircleButton::CircleButton(Font *font, const char *str, const int num, const float x, char *colorName)
	: Button(num) {
	text = new MyDrawText(font, str, x, GetY() * SIZE_RATE, 1, 30);
	myDrawCircle = new MyDrawCircle(WIDTH * 0.97, GetY() * SIZE_RATE, WIDTH * 0.015, 7, colorName);
}

void CircleButton::View() {
	myDrawCircle->View();
	text->View();
}

CircleButton::~CircleButton() {
	delete text;
	delete myDrawCircle;
}

//�������ۂ̒��ɂ���{�^��
CircleButton2::CircleButton2(Font *font, const char *str, const int num, char *colorName)
	: Button(num) {
	float r = WIDTH * 0.045;
	float x = WIDTH - r - 4;
	text = new MyDrawText(font, str, x, GetY() * SIZE_RATE, 1, 30, "Black");
	myDrawCircle = new MyDrawCircle(x, GetY() * SIZE_RATE, r, colorName);
}

void CircleButton2::View() {
	myDrawCircle->View();
	text->View();
}

CircleButton2::~CircleButton2() {
	delete text;
	delete myDrawCircle;
}

//�摜�t���̃{�^��
CircleGraphButton::CircleGraphButton(const int num, const char *fileName) 
	: Button(num) {
	float r = WIDTH * 0.075;
	myDrawCircle = new MyDrawCircle(WIDTH, GetY() * SIZE_RATE, r);
	myDrawGraph = new MyDrawGraph(WIDTH  - 35, GetY() * SIZE_RATE, fileName);
}

void CircleGraphButton::Load() {
	myDrawGraph->Load();
}

void CircleGraphButton::View() {
	myDrawCircle->View();
	myDrawGraph->View();
}

CircleGraphButton::~CircleGraphButton() {
	delete myDrawCircle;
	delete myDrawGraph;
}