#ifndef __DRAWTEXT_H_INCLUDED__
#define __DRAWTEXT_H_INCLUDED__

#include <string.h>
#include <string>
#include "DxLib.h"
#include "Font.h"
#include "Draw.h"

// �e�L�X�g�֌W
class MyDrawText : public Color, public Draw2{
public:
	MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void ContentView(); // �`��
	void ChangeText(char *str); // �e�L�X�g�ύX
	void ChangeFont(Font *font, const int point); // �t�H���g�T�C�Y�ύX
	float GetHeight(); // �c�擾
	float GetWidth(); // ���擾
protected:
	int f, point; // �t�H���g���A�|�W�V�������A�t�H���g�T�C�Y
	std::string s; // ����
};

// �c�����e�L�X�g
class MyDrawTextV : public MyDrawText {
public:
	MyDrawTextV(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName = "White"); // pos=����:0 / ������:1 / �E��:2
	void ContentView();
private:
	float RotCenterX;
};

// �����s�̃e�L�X�g
class MyDrawTexts : public Color, public Draw {
public:
	MyDrawTexts(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineInterval, const char *colorName = "White");
	void ContentView();
	void ChangePos(const float x, const float y);
	void ChangeText(const char *str); // �e�L�X�g�ύX
	float GetWidth(); // ���擾
	float GetHeight(); // �����擾
	~MyDrawTexts();
private:
	MyDrawText *myDrawText[256];
	Font *f;
	int l = 0, p, inter, point; // �s��, �|�W�V�������, �Ԋu�A�|�C���g��
	char color[100];
};

// �A���_�[���C���t���e�L�X�g
class MyDrawTextLine : public Color, public Draw {
public:
	MyDrawTextLine(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName = "White");
	void ContentView();
	void ChangePos(const float x, const float y);
	void ChangeText(char *str); // �e�L�X�g�ύX
	~MyDrawTextLine();
private:
	MyDrawText *myDrawText;
	int pos;
	float x1, x2, y1, y2, w, l; // ���W�A���̑����A���̒���
};

#endif