#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "CommonText.h"
#include "ThroughDefine.h"
#include "Button.h"
#include "SeetingPop.h"
#include "Scene.h"

class ThroughFinish : public SubScene {
public:
	ThroughFinish(Font *font, Touch *touch);
	void ContentUpdate();
	void ContentView();
	~ThroughFinish();
private:
	BlackBox *blackBox;
	Button *button[4];
};

class ThroughDetail : public SubScene {
public:
	ThroughDetail(Font *font, Touch *touch);
	ThroughScene Switch(const ThroughScene scene);
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