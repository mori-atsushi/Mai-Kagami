#ifndef __PARTPAUSE_H_INCLUDED__
#define __PARTPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"
#include "PartDefine.h"
#include "SeetingPop.h"
#include "PauseScreen.h"
#include "Touch.h"
#include "Scene.h"
#include "PartOptionPop.h"

// �|�[�Y�{�^�����
class PartPauseButton : public SubScene {
public:
	PartPauseButton(Touch *touch, Songs *songs);
	void Load();
	int Switch(const int scene);
	void Delete();
	~PartPauseButton();
private:
	void ContentUpdate();
	void ContentView();
	Songs *songs;
	CircleGraphButton *button[2]; // �{�^��
};

// �|�[�Y���
class PartPauseScreen : public PauseScreen {
public:
	PartPauseScreen(Font *font, Songs *songs, Touch *touch);
};

class PartOptionPreview3 : public PartOptionPreview {
public:
	PartOptionPreview3(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
	~PartOptionPreview3();
private:
	BlackBox *blackBox;
	void ContentView();
	Button *button;
};

// �ݒ�ύX���
class PartPauseSetting : public PartOptionPop {
public:
	PartPauseSetting(Font *font, Songs *songs, Touch *touch);
};

// �|�[�Y�֌W
class PartPause : public SubScene {
public:
	PartPause(Font *font, Songs *songs, Touch *touch);
	void Load();
	int Switch(const int scene);
	void Delete();
	~PartPause();
private:
	void ContentUpdate();
	void ContentView();
	Songs *songs;
	boolean flag; // �|�[�Y�����ǂ����̃t���O
	PartPauseButton *partPauseButton; // �|�[�Y�{�^�����
	PartPauseScreen *partPauseScreen; // �|�[�Y���
	PartPauseSetting *partPauseSetting; // �ݒ�ύX���
};

#endif