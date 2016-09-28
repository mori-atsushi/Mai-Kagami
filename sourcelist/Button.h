#ifndef __BUTTON_H_INCLUDED__
#define __BUTTON_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"
#include "Touch.h"

#define BUTTON_POS HEIGHT * 0.5
#define BUTTON_INTERVAL HEIGHT * 0.05

// �{�^���֌W
class Button : public Draw {
public:
	Button(const int num, Touch *touch);
	int GetTouch(); // ���̃{�^����������Ă���t���[�������擾
private:
	virtual void ContentView() = 0; // �\���p�֐�
	Touch *touch; // �^�b�`
	int num; // �{�^���ԍ�
};

// �O�p�`�̃{�^��
class TriangleButton : public Button {
public:
	TriangleButton(Font *font, Touch *touch, const char *str, const int direction, const int num, char *colorName = "Blue");
	void ContentView();
	~TriangleButton();
private:
	MyDrawTriangle2 *myDrawTriangle2;
	MyDrawText *text; // �{�^���̕���
};

// �������t���O�p�`�̃{�^��
class TriangleButton2 : public Button {
public:
	TriangleButton2(Font *font, Touch *touch, const char *title, const char *str, const int direction, const int num, const float x, const char *colorName);
	void ContentView();
	~TriangleButton2();
private:
	MyDrawText *text; // �{�^���̕���
	MyDrawTexts *descriptionText;
	MyDrawTriangle2 *myDrawTriangle2;
	MyDrawBox *myDrawBox;
};

// �~�̃{�^��
class CircleButton : public Button {
public:
	CircleButton(Font *font, Touch *touch, const char *str, const int num, char *colorName = "Blue"); // �����E�񂹃{�^��
	CircleButton(Font *font, Touch *touch, const char *str, const int num, const float x, char *colorName = "Blue"); // ���������񂹃{�^��
	void ContentView();
	~CircleButton();
private:
	MyDrawText *text; // �{�^���̕���
	MyDrawCircle *myDrawCircle;
};

// �������ۂ̒��ɂ���{�^��
class CircleButton2 : public Button {
public:
	CircleButton2(Font *font, Touch *touch, const char *str, const int num, char *colorName = "Blue");
	void ContentView();
	~CircleButton2();
private:
	MyDrawText *text; // �{�^���̕���
	MyDrawCircle *myDrawCircle;
};

// �摜�t���̃{�^��
class CircleGraphButton : public Button {
public:
	CircleGraphButton(Touch *touch, const int num, const char *fileName);
	void ContentView();
	void Load();
	void Release();
	~CircleGraphButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawGraph *myDrawGraph;
};

// �摜�A�e�L�X�g�t���̃{�^��
class CircleGraphTextButton : public Button {
public:
	CircleGraphTextButton(Font *font, Touch *touch, const char *str, const int num, const char *fileName);
	void Load();
	void ContentView();
	void Release();
	~CircleGraphTextButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawGraph *myDrawGraph;
	MyDrawText *text;
};

#endif