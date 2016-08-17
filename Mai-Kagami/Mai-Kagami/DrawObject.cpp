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
void  MyDrawCircle::ContentView() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(x, y, r, 100, Color::Get(), flag, w);
}

//角度付きの円初期化
MyDrawCircleGauge::MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName) 
	:MyDrawCircle(0, 0, width, colorName), Pos(x, y){
	r = radius / SIZE_RATE;
	ChangeDegree(degree);
}

void MyDrawCircleGauge::ContentView() {
	for (double i = 0; i < rad; i += 0.02) {
		float xx = (Pos::x + r * sin(i)) * SIZE_RATE;
		float yy = (Pos::y - r * cos(i)) * SIZE_RATE;
		MyDrawCircle::ChangePos(xx, yy);
		MyDrawCircle::ContentView();
	}
	MyDrawCircle::ChangePos(GetEndX() * SIZE_RATE, GetEndY() * SIZE_RATE);
	MyDrawCircle::ContentView();
}

void MyDrawCircleGauge::ChangeDegree(const double degree) {
	rad = 2 * M_PI * degree / 100;
}

float  MyDrawCircleGauge::GetEndX() {
	return Pos::x + r * sin(rad);
}

float  MyDrawCircleGauge::GetEndY() {
	return Pos::y - r * cos(rad);
}

//線初期化
MyDrawLine::MyDrawLine(const float width, const char *colorName)
	: Color(colorName) {}

//線初期化
MyDrawLine::MyDrawLine(const float x1, const float y1, const float x2, const float y2, const float width, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2);
	w = width / SIZE_RATE;
}

//三角形表示
void MyDrawLine::ContentView() {
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}

void MyDrawLine::ChangePos(const float x1, const float y1, const float x2, const float y2) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
}

//三角形初期化
MyDrawTriangle::MyDrawTriangle(const char *colorName) 
	: Color(colorName) {}

//三角形初期化
MyDrawTriangle::MyDrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//三角形表示
void MyDrawTriangle::ContentView() {
	DrawTriangleAA(x1, y1, x2, y2, x3, y3, Color::Get(), TRUE);
}


void MyDrawTriangle::ChangePos(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
	this->x3 = x3 / SIZE_RATE;
	this->y3 = y3 / SIZE_RATE;
}

//正三角形初期化
MyDrawTriangle2::MyDrawTriangle2(const float x, const float y, const float width, const int direction, const char *colorName)
	: MyDrawTriangle(colorName) {
	w = width;
	d = direction;

	float x1, x2, x3, y1, y2, y3;
	float a = w * sqrt(3) / 4;

	x1 = x2 = x3 = x;
	y1 = y2 = y3 = y;

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

	ChangePos(x1, y1, x2, y2, x3, y3);
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
void  MyDrawBox::ContentView() {
	boolean flag = TRUE;
	if (l != 0)
		flag = FALSE;
	float x1 = x - w / 2;
	float y1 = y - h / 2;
	float x2 = x + w / 2;
	float y2 = y + h / 2;

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