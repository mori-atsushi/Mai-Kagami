#ifndef __PLAYSCREENOBJECT_H_INCLUDED__
#define __PLAYSCREENOBJECT_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"
#include "SeetingPop.h"
#include "DrawText.h"

// �i���o�[
class PlayBar {
public:
	PlayBar(Font *font);
	void Load(Song *song);
	void Update();
	void View();
	~PlayBar();
private:
	Font *font;
	Song *song;
	MyDrawBar *barAll, *barNow;
	MyDrawCircle *circle[2];
	MyDrawTextV *part[10];
};

// �J�E���g�_�E����ʗp�Đ��O�p�`
class PlayTriangle : public MyDrawTriangle {
public:
	PlayTriangle(const float x, const float y);
};


// �J�E���g�_�E�����
class CountDown : public	SubScene {
public:
	CountDown(Font *font, const int thisScene, const int playScene);
	int Switch(const int scene);
	~CountDown();
private:
	void ContentUpdate();
	void ContentView();
	int count; // �J�E���^
	int thisScene, playScene; // CountDown��ʂ̃V�[���A�v���C���[�h�̃V�[��
	BlackBox *blackBox;
	MyDrawText *text;
	MyDrawCircle *circle;
	MyDrawCircleGauge *countCircle1;
	MyDrawCircle *countCircle2;
	PlayTriangle *playTriangle;
	const int max = 120;
};

#endif