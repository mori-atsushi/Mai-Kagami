#ifndef __THROUGHPAUSE_H_INCLUDED__
#define __THROUGHPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "ThroughDefine.h"

class ThroughPause {
public:
	ThroughPause(Font *font);
	void Update(int scene);
	void Load();
	void View();
	~ThroughPause();
private:
	boolean flag; //ポーズ中かどうかのフラグ
	CircleGraphButton *pauseButton; //一時停止用ボタン
	BlackBox *blackBox; //背景半透明黒の四角形
	MyDrawText *title;
	Button *button[4];
};

#endif