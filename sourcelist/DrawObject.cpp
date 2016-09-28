#include "DrawObject.h"

// �~�������i�h��Ԃ�����j
// MyDrawCircle(x���W�Ay���W�A���a�A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = 0;
}

// �~�������i�h��Ԃ��Ȃ��j
// MyDrawCircle(x���W�Ay���W�A���a�A���̑����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawCircle::MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName)
	:Draw(x, y), Color(colorName) {
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

// �~�\��
void  MyDrawCircle::ContentView() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(x, y, r, 100, Color::Get(), flag, w);
}

// �p�x�t���̉~������(�h��Ԃ��Ȃ�)
// MyDrawCircleGauge(x���W�Ay���W�A���a�A�p�x�i���w��j�A���̑����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawCircleGauge::MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName) 
	:MyDrawCircle(0, 0, width, colorName), Pos(x, y){
	r = radius / SIZE_RATE;
	ChangeDegree(degree); // �p�x�������烉�W�A���ɕύX
}

// �p�x�t���̉~�`��
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

// �p�x�t���̉~�@�p�x�������烉�W�A���ɕύX���ĕۑ�
void MyDrawCircleGauge::ChangeDegree(const double degree) {
	rad = 2 * M_PI * degree / 100;
}

// �p�x�t���̉~�@�ŏIX���W���擾
float  MyDrawCircleGauge::GetEndX() {
	return Pos::x + r * sin(rad);
}

// �p�x�t���̉~�@�ŏIY���W���擾
float  MyDrawCircleGauge::GetEndY() {
	return Pos::y - r * cos(rad);
}

// ���������i���W�w��Ȃ��A���ƂŎw�肷��ꍇ�j
// MyDrawLine(�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawLine::MyDrawLine(const float width, const char *colorName)
	: Color(colorName) {}

// ���������i���W�w�肠��j
// MyDrawLine(�n�_x���W�A�n�_y���W�A�I�_x���W�A�I�_y���W�A�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawLine::MyDrawLine(const float x1, const float y1, const float x2, const float y2, const float width, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2);
	w = width / SIZE_RATE;
}

// ���\��
void MyDrawLine::ContentView() {
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}

// ���̍��W�w��
void MyDrawLine::ChangePos(const float x1, const float y1, const float x2, const float y2) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
}

// �O�p�`������
MyDrawTriangle::MyDrawTriangle(const char *colorName) 
	: Color(colorName) {}

// �O�p�`������
// MyDrawTriangle(�_�Px���W�A�_�Py���W�A�_�Qx���W�A�_�Qy���W�A�_�Rx���W�A�_�Ry���W�A�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawTriangle::MyDrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const char *colorName)
	: Color(colorName) {
	ChangePos(x1, y1, x2, y2, x3, y3);
}

// �O�p�`�\��
void MyDrawTriangle::ContentView() {
	DrawTriangleAA(x1, y1, x2, y2, x3, y3, Color::Get(), TRUE);
}

// �O�p�` ���W�w��
void MyDrawTriangle::ChangePos(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3) {
	this->x1 = x1 / SIZE_RATE;
	this->y1 = y1 / SIZE_RATE;
	this->x2 = x2 / SIZE_RATE;
	this->y2 = y2 / SIZE_RATE;
	this->x3 = x3 / SIZE_RATE;
	this->y3 = y3 / SIZE_RATE;
}

// ���O�p�`������
// MyDrawTriangle2(x���W�Ay���W�A��ӂ̒����A�����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
// �����i�O�F������A�P�F�������A�Q�F�������j
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

// �l�p�`������(�h��Ԃ�����)
// MyDrawBox(x���W�Ay���W�A���̒����A�c�̒����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ���F
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = 0;
}

// �l�p�`�������i�h��Ԃ��Ȃ��j
// MyDrawBox(x���W�Ay���W�A���̒����A�c�̒����A���̑����A�F)�@���F�͏ȗ��\�A�ȗ������ꍇ�F
MyDrawBox::MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName)
	:Draw(x, y), Color(colorName) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = line / SIZE_RATE;
}

// �l�p�`�\��
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

// �l�p�`�T�C�Y�ύX
void MyDrawBox::ChangeSize(const float width, const float height) {
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
}

// �i���o�[������
MyDrawBar::MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName)
	:MyDrawBox(x + width / 2, y, width, height, colorName) {
	MyDrawBar::x = x;
	MyDrawBar::y = y;
}

// �i���o�[�T�C�Y�ύX
void MyDrawBar::ChangeSize(const float width, const float height) {
	MyDrawBox::ChangeSize(width, height);
	ChangePos(x + width / 2, y);
}