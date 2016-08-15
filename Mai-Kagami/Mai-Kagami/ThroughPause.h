#ifndef __THROUGHPAUSE_H_INCLUDED__
#define __THROUGHPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"
#include "Touch.h"
#include "Scene.h"

class ThroughPause : public SubScene {
public:
	ThroughPause(Font *font, Songs *songs, Touch *touch);
	void Load();
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughPause();
private:
	Touch *touch;
	Songs *songs;
	boolean flag; //ポーズ中かどうかのフラグ
	CircleGraphButton *pauseButton; //一時停止用ボタン
	BlackBox *blackBox; //背景半透明黒の四角形
	MyDrawText *title;
	CircleGraphTextButton *button[4];
	SpeedPop *speedPop;
};

#endif