#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "CommonText.h"
#include "ThroughDefine.h"
#include "Button.h"
#include "SeetingPop.h"
#include "Scene.h"

class ThroughFinish {
public:
	ThroughFinish(Font *font);
	void View();
	~ThroughFinish();
private:
	BlackBox *blackBox;
	Button *button[4];
};

class ThroughDetail : public SubScene {
public:
	ThroughDetail(Font *font, Touch *touch);
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~ThroughDetail();
private:
	Touch *touch;
	DrawTitle *title;
	Button *button;
	ThroughFinish *throughFinish;
};

#endif