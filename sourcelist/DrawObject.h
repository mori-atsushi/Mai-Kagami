#ifndef __DRAWOBJECT_H_INCLUDED__
#define __DRAWOBJECT_H_INCLUDED__

#include "DxLib.h"
#define _USE_MATH_DEFINES
#include "Main.h"
#include "Draw.h"

// �~�֌W
class MyDrawCircle : public Draw, public Color{
public:
	MyDrawCircle(const float x, const float y, const float radius, const char *colorName = "Blue"); // �~�������i�h��Ԃ�����j
	MyDrawCircle(const float x, const float y, const float radius, const float width, const char *colorName = "Blue"); // �~�������i�h��Ԃ��Ȃ��j
	void ContentView();
private:
	float r, w; // ���a�A���̑���
};

// �p�x�t���̉~(���̂�)
class MyDrawCircleGauge : public MyDrawCircle , public Pos{
public:
	MyDrawCircleGauge(const float x, const float y, const float radius, const double degree, const float width, const char *colorName = "Blue");
	void ContentView();
	void ChangeDegree(const double degree);
	float GetEndX();
	float GetEndY();
private:
	float r; // ���a
	double rad; // �p�x�i���W�A���j
};

// ��
class MyDrawLine : public Draw, public Color {
public:
	MyDrawLine(const float width, const char *colorName = "Blue");
	MyDrawLine(const float x1, const float y1, const float x2, const float y2, const float width, const char *colorName = "Blue");
	void ChangePos(const float x1, const float y1, const float x2, const float y2);
private:
	void ContentView();
	float x1, y1, x2, y2, w;
};

class MyDrawTriangle : public Draw, public Color {
public:
	MyDrawTriangle(const char *colorName = "Blue");
	MyDrawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const char *colorName = "Blue");
	void ChangePos(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3);
private:
	void ContentView();
	float x1, y1, x2, y2, x3, y3;
};

// ���O�p�`�֌W
class MyDrawTriangle2 : public MyDrawTriangle {
public:
	MyDrawTriangle2(const float x, const float y, const float width, const int direction, const char *colorName = "Blue");
private:
	int d;
	float w;
};

// �l�p�`�֌W
class MyDrawBox : public Draw, public Color {
public:
	MyDrawBox(const float x, const float y, const float width, const float height, const char *colorName = "White"); // �l�p�`�������i�h��Ԃ�����j
	MyDrawBox(const float x, const float y, const float width, const float height, const float line, const char *colorName = "Blue"); // �l�p�`�������i�h��Ԃ��Ȃ��j
	void ContentView();
	void ChangeSize(const float width, const float height);
private:
	float w, h, l; // ���A�����A���̑���
};

class MyDrawBar : public MyDrawBox {
public:
	MyDrawBar(const float x, const float y, const float width, const float height, const char *colorName = "White"); // �l�p�`�������i�h��Ԃ�����j
	void ChangeSize(const float width, const float height);
private:
	float x, y; // ���W
};

#endif