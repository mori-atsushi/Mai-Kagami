#include "DrawObject.h"

//円初期化（塗りつぶしあり）
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = 0;
}

//円初期化（塗りつぶしなし）
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//円表示
void  MyDrawCircle::View() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(GetX(), GetY(), r, 100, Color::Get(), flag, w);
}

//角度付きの円初期化
MyDrawCircleGauge::MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName) 
	:MyDrawCircle(0, 0, width, colorName), Draw(x, y){
	r = radius / SIZE_RATE;
	ChangeDegree(degree);
}

void MyDrawCircleGauge::View() {
	for (double i = 0; i < rad; i += 0.02) {
		float x = (Draw::GetX() + r * sin(i)) * SIZE_RATE;
		float y = (Draw::GetY() - r * cos(i)) * SIZE_RATE;
		MyDrawCircle::ChangePos(x, y);
		MyDrawCircle::View();
	}
	MyDrawCircle::ChangePos(GetEndX() * SIZE_RATE, GetEndY() * SIZE_RATE);
	MyDrawCircle::View();
}

void MyDrawCircleGauge::ChangeDegree(const double degree) {
	rad = 2 * M_PI * degree / 100;
}

float  MyDrawCircleGauge::GetEndX() {
	return Draw::GetX() + r * sin(rad);
}

float  MyDrawCircleGauge::GetEndY() {
	return Draw::GetY() - r * cos(rad);
}

//三角形初期化
MyDrawTriangle::MyDrawTriangle(const float x, const float y, const float width, const int direction, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	d = direction;
}

//三角形表示
void  MyDrawTriangle::View() {
	float x1, x2, x3, y1, y2, y3;
	float a = w * sqrt(3) / 4;

	x1 = x2 = x3 = GetX();
	y1 = y2 = y3 = GetY();

	switch (d)
	{
	case 0:
		x2 -= w / 2; x3 += w / 2;
		y1 -= a; y2 += a; y3 += a;
		break;
	case 1:
		x2 -= w / 2; x3 += w / 2;
		y1 += a; y2 -= a; y3 -= a;
		break;
	case 2:
		y2 -= w / 2; y3 += w / 2;
		x1 += a; x2 -= a; x3 -= a;
		break;
	}

	DrawTriangleAA(x1, y1, x2, y2, x3, y3, Color::Get(), TRUE);
}

//四角形初期化(塗りつぶしあり)
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = 0;
}

//四角形初期化（塗りつぶしなし）
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = line / SIZE_RATE;
}

//四角形表示
void  MyDrawBox::View() {
	boolean flag = TRUE;
	if (l != 0)
		flag = FALSE;
	float x1 = GetX() - w / 2 + 1;
	float y1 = GetY() - h / 2 + 1;
	float x2 = GetX() + w / 2;
	float y2 = GetY() + h / 2;

	DrawBoxAA(x1, y1, x2, y2, Color::Get(), flag, l);
}

void MyDrawBox::ChangeSize(const float width, const float height) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
}

//進捗バー初期化
MyDrawBar::MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName)
	:MyDrawBox(x + width / 2, y, width, height, colorName) {
	MyDrawBar::x = x;
	MyDrawBar::y = y;
}

void MyDrawBar::ChangeSize(const float width, const float height) {
	MyDrawBox::ChangeSize(width, height);
	ChangePos(x + width / 2, y);
}