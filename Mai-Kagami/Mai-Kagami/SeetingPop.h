#ifndef __SETTINGPOP_H_INCLUDED__
#define __SETTINGPOP_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"
#include "DrawText.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"
#include "Touch.h"

//ポップアップ用四角形（黒色半透明全画面）
class BlackBox : public MyDrawBox {
public:
	BlackBox();
private:
};

//スピードオプション表示
class SpeedOption {
public:
	SpeedOption(Font *font, Songs *songs, Touch *touch);
	void Check(Touch *touch);
	void View();
	~SpeedOption();
private:
	Button *button[2];
	MyDrawText *speed[2];
	Songs *songs;
};

//スピードオプションポップアップ
class SpeedPop : public SpeedOption {
public:
	SpeedPop(Font *font, Songs *songs, Touch *touch);
	void Check(Touch *touch);
	void View();
	~SpeedPop();
private:
	Songs *songs;
	BlackBox *blackBox;
	Button *button;
	MyDrawText *text;
};

#endif