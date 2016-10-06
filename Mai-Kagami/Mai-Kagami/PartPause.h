#ifndef __PARTPAUSE_H_INCLUDED__
#define __PARTPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "DecorationItem.h"
#include "Songs.h"
#include "PartDefine.h"
#include "SeetingPop.h"
#include "PauseScreen.h"
#include "Touch.h"
#include "Scene.h"
#include "PartOptionPop.h"
#include "Kinect.h"

//ポーズボタン画面
class PartPauseButton : public SubScene {
public:
	PartPauseButton(DecorationItem *decorationItem, Touch *touch, Songs *songs, Kinect *kinect);
	void Load();
	int Switch(const int scene);
	void Delete();
	~PartPauseButton();
private:
	void ContentUpdate();
	void ContentView();
	DecorationItem *decorationItem;
	Songs *songs;
	Kinect *kinect;
	CircleGraphButton *button[2]; //ボタン
};

//ポーズ画面
class PartPauseScreen : public PauseScreen {
public:
	PartPauseScreen(DecorationItem *decorationItem, Songs *songs, Touch *touch);
};

class PartOptionPreview3 : public PartOptionPreview {
public:
	PartOptionPreview3(DecorationItem *decorationItem, Songs *songs, Touch *touch);
	int Switch(const int scene);
	~PartOptionPreview3();
private:
	BlackBox *blackBox;
	void ContentView();
	Button *button;
};

//設定変更画面
class PartPauseSetting : public PartOptionPop {
public:
	PartPauseSetting(DecorationItem *decorationItem, Songs *songs, Touch *touch);
};

//ポーズ関係
class PartPause : public SubScene {
public:
	PartPause(DecorationItem *decorationItem, Songs *songs, Touch *touch, Kinect *kinect);
	void Load();
	int Switch(const int scene);
	void Delete();
	~PartPause();
private:
	void ContentUpdate();
	void ContentView();
	Songs *songs;
	boolean flag; //ポーズ中かどうかのフラグ
	PartPauseButton *partPauseButton; //ポーズボタン画面
	PartPauseScreen *partPauseScreen; //ポーズ画面
	PartPauseSetting *partPauseSetting; //設定変更画面
};

#endif