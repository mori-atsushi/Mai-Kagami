#ifndef __THROUGHPAUSE_H_INCLUDED__
#define __THROUGHPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"
#include "PauseScreen.h"
#include "Touch.h"
#include "Scene.h"

// �|�[�Y�{�^�����
class ThroughPauseButton : public SubScene {
public:
	ThroughPauseButton(Touch *touch);
	void Load();
	int Switch(const int scene);
	void Delete();
	~ThroughPauseButton();
private:
	void ContentUpdate();
	void ContentView();
	CircleGraphButton *pauseButton; // �ꎞ��~�p�{�^��
};

// �|�[�Y���
class ThroughPauseScreen : public PauseScreen {
public:
	ThroughPauseScreen(Font *font, Songs *songs, Touch *touch);
};

// ���x�ύX���
class ThroughPauseSetting : public SpeedPop {
public:
	ThroughPauseSetting::ThroughPauseSetting(Font *font, Songs *songs, Touch *touch) : SpeedPop(font, songs, touch) {};
	int Switch(const int scene);
	void ContentUpdate();
};

// �|�[�Y�֌W
class ThroughPause : public SubScene {
public:
	ThroughPause(Font *font, Songs *songs, Touch *touch);
	void Load();
	int Switch(const int scene);
	void Delete();
	~ThroughPause();
private:
	void ContentUpdate();
	void ContentView();
	Songs *songs;
	boolean flag; // �|�[�Y�����ǂ����̃t���O
	ThroughPauseButton *throughPauseButton; // �|�[�Y�{�^�����
	ThroughPauseScreen *throughPauseScreen; // �|�[�Y���
	ThroughPauseSetting *throughPauseSetting; // ���x�ύX���
};

#endif