#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "CommonText.h"
#include "ThroughDefine.h"
#include "Button.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "ThroughResultObject.h"

class ThroughFinish : public SubScene {
public:
	ThroughFinish(Font *font, Touch *touch);
	ThroughScene Switch(const ThroughScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughFinish();
private:
	BlackBox *blackBox;
	Button *button[4];
};

class ThroughDetailScreen : public SubScene {
public:
	ThroughDetailScreen(Font *font, Touch *touch);
	ThroughScene Switch(const ThroughScene scene);
	void Load();
	~ThroughDetailScreen();
private:
	void ContentUpdate();
	void ContentView();
	DrawTitle *title;
	TimingBar *timingBar;
	ExpressionBar *expressionBar;
	ResultComment *resultComment;
	ResultBody *resultBody;
	Button *button;
};

class ThroughDetail : public SubScene {
public:
	ThroughDetail(Font *font, Touch *touch);
	ThroughScene Switch(const ThroughScene scene);
	void Load();
	~ThroughDetail();
private:
	void ContentUpdate();
	void ContentView();
	ThroughDetailScreen *throughDetailScreen;
	ThroughFinish *throughFinish;
};

#endif