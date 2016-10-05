#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "CommonText.h"
#include "ThroughDefine.h"
#include "Button.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "ThroughResultObject.h"
#include "ThroughResultDefine.h"
#include "Result.h"

class ThroughFinish : public SubScene {
public:
	ThroughFinish(DecorationItem *decorationItem, Touch *touch);
	ThroughResultScene Switch(const ThroughResultScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughFinish();
private:
	BlackBox *blackBox;
	Button *button[4];
};

class ThroughDetailScreen : public SubScene {
public:
	ThroughDetailScreen(DecorationItem *decorationItem, Songs *songs, Touch *touch, Result *result);
	ThroughResultScene Switch(const ThroughResultScene scene);
	void Load();
	void Delete();
	~ThroughDetailScreen();
private:
	void ContentUpdate();
	void ContentView();
	DrawTitle *title;
	TimingBar *timingBar;
	ExpressionBar *expressionBar;
	ResultComment *resultComment;
	ResultBody *resultBody;
	ResultGraph *resultGraph;
	Button *button;
	Songs *songs;
	Result *result;
};

class ThroughDetail : public SubScene {
public:
	ThroughDetail(DecorationItem *decorationItem, Songs *songs, Touch *touch, Result *result);
	ThroughResultScene Switch(const ThroughResultScene scene);
	void Load();
	void Delete();
	~ThroughDetail();
private:
	void ContentUpdate();
	void ContentView();
	ThroughDetailScreen *throughDetailScreen;
	ThroughFinish *throughFinish;
};

class RecommendButton : public Button {
public:
	RecommendButton(DecorationItem *decorationItem, Touch* touch, const int num);
	void ContentView();
	~RecommendButton();
private:
	MyDrawTextLine *text;
	MyDrawText *textSub;

	MyDrawCircle *myDrawCircle;
};

#endif