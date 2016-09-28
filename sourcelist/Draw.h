#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#include "Main.h"
#include "Animation.h"

// �F�֌W
class Color {
public:
	Color(const char *color);
	void ChangeColor(const char *color);
protected:
	int Get();
private:
	int c;
};

// �\���ʒu�p�N���X
class Pos : public Animation {
public:
	void ChangePos(const float x, const float y); // ���W�ύX
	void SetPosAnimation(float target_x, float target_y, Easing ease = LINER);  // Jaity
	void Update();	// �A�j���[�V�����X�V
	float GetX(); // x���W�擾
	float GetY(); // y���W�擾
protected:
	Pos();
	Pos(const float x, const float y); // ������
	float x, y;
private:
	float target_x, target_y;	// �A�j���[�V�������̖ڕW���W
	float default_x, default_y;	// �A�j���[�V�����J�n���̍��W
	Easing ease_pos;
};

// �`��p�N���X
class Draw : public Pos {
public:
	Draw();
	Draw(const float x, const float y);
	void View();
	void SetAlpha(const int alpha = 255); // �����x�w��
	int GetAlpha();
	void SetAlphaAnimation(int alpha = 255, Easing ease = LINER);
	void Update();	// �A�j���[�V�����X�V
	void SetViewFlag(const boolean viewFlag);
private:
	virtual void ContentView() = 0; // �\�����\�b�h
	int alpha = 255; // �����x
	int target_alpha, default_alpha;
	Easing ease_alpha;
	boolean viewFlag = TRUE;
};

// �`��p�N���X�i�ʒu�w�肠��j
class Draw2 : public Draw {
public:
	Draw2(const int position);
	Draw2(const float x, const float y, const int pos);
	void ChangePos();
	void ChangePos(const float x, const float y);
	float GetX(); // x���W�擾
	float GetY(); // y���W�擾
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
protected:
	int p; // �|�W�V�������
private :
	float xx, yy; // ���W
};

#endif