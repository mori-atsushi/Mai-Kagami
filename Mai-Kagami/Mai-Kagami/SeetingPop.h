#ifndef __SETTINGPOP_H_INCLUDED__
#define __SETTINGPOP_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"
#include "DrawText.h"
#include "Button.h"
#include "DecorationItem.h"
#include "Songs.h"
#include "Touch.h"
#include "Scene.h"

//ポップアップ用四角形（黒色半透明全画面）
class BlackBox : public MyDrawBox {
public:
	BlackBox();
private:
};

//スピードオプション表示
class SpeedOption {
public:
	SpeedOption(DecorationItem *decorationItem, Songs *songs, Touch *touch);
	void Check();
	void View();
	~SpeedOption();
private:
	Button *button[2];
	MyDrawText *speed[2];
	Songs *songs;
};

//区間設定オプション表示
class PartOption {
public:
	PartOption(DecorationItem *decorationItem, Songs *songs, Touch *touch);
	void Load();
	void Init();
	void Check();
	void View();
	~PartOption();
	bool mode;
private:
	Button *button[4];
	MyDrawText *part[4];
	Songs *songs;
	Song *song;
	MyDrawBar *overallPartBar;
	MyDrawBar *selectedPartBar;
	MyDrawCircle *startPoint;
	MyDrawCircle *endPoint;
	MyDrawText* partName[10];
	MyDrawText* caution;
};

//スピードオプションポップアップ
class SpeedPop : public SubScene {
public:
	SpeedPop(DecorationItem *decorationItem, Songs *songs, Touch *touch);
	void Load();
	~SpeedPop();
protected:
	void ContentUpdate();
	void ContentView();
	Songs *songs;
	Song *song;
	SpeedOption *speedOption;
	BlackBox *blackBox;
	Button *button;
	MyDrawText *text;
};

//区間設定オプションポップアップ
class PartPop : public SubScene {
public:
	PartPop(DecorationItem *decorationItem, Songs *songs, Touch *touch);
	void Load();
	void SetButtonMode(bool mode);
	~PartPop();
protected:
	void ContentUpdate();
	void ContentView();
	void Init();
	Songs *songs;
	Song *song;
	PartOption *partOption;
	BlackBox *blackBox;
	CircleButton2 *button;
	MyDrawText *text;
};


#endif