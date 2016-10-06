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

class RecommendButton : public Button {
public:
	RecommendButton(DecorationItem *decorationItem, Songs *songs, Touch* touch, Result *result, const int num);
	void Update();
	void ContentView();
	~RecommendButton();
private:
	MyDrawTextLine *text;
	MyDrawText *textSub;
	
	MyDrawCircle *myDrawCircle;
	Result *result;
	Songs *songs;
};

class ThroughFinish : public SubScene {
public:
	ThroughFinish(DecorationItem *decorationItem, Songs *songs, Touch *touch, Result *result);
	ThroughResultScene Switch(const ThroughResultScene scene);
	void ContentUpdate();
	void ContentView();
	~ThroughFinish();
private:
	BlackBox *blackBox;
	RecommendButton *rButton;
	Button *button[3];
	Songs *songs;
	Result *result;
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
	DecorationItem *decorationItem;
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

#endif