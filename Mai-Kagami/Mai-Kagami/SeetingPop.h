#ifndef __SETTINGPOP_H_INCLUDED__
#define __SETTINGPOP_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"
#include "DrawText.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"

//ポップアップ用四角形（黒色半透明全画面）
class BlackBox : public MyDrawBox {
public:
	BlackBox();
	void View();
private:
};

//スピードオプション表示
class SpeedOption {
public:
	SpeedOption(Font *font, Songs *songs);
	void Update();
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
	SpeedPop(Font *font, Songs *songs);
	void Update();
	void View();
	~SpeedPop();
private:
	BlackBox *blackBox;
	Button *button;
};

#endif