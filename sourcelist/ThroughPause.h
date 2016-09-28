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

// ポーズボタン画面
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
	CircleGraphButton *pauseButton; // 一時停止用ボタン
};

// ポーズ画面
class ThroughPauseScreen : public PauseScreen {
public:
	ThroughPauseScreen(Font *font, Songs *songs, Touch *touch);
};

// 速度変更画面
class ThroughPauseSetting : public SpeedPop {
public:
	ThroughPauseSetting::ThroughPauseSetting(Font *font, Songs *songs, Touch *touch) : SpeedPop(font, songs, touch) {};
	int Switch(const int scene);
	void ContentUpdate();
};

// ポーズ関係
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
	boolean flag; // ポーズ中かどうかのフラグ
	ThroughPauseButton *throughPauseButton; // ポーズボタン画面
	ThroughPauseScreen *throughPauseScreen; // ポーズ画面
	ThroughPauseSetting *throughPauseSetting; // 速度変更画面
};

#endif