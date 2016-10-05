#ifndef __PLAYSCREENOBJECT_H_INCLUDED__
#define __PLAYSCREENOBJECT_H_INCLUDED__

#include "DxLib.h"
#include "DrawObject.h"
#include "SeetingPop.h"
#include "DrawText.h"

//進捗バー
class PlayBar {
public:
	PlayBar(DecorationItem *decorationItem);
	void Load(Song *song);
	void Update();
	void View();
	~PlayBar();
private:
	DecorationItem *decorationItem;
	Song *song;
	MyDrawBar *barAll, *barNow;
	MyDrawCircle *circle[2];
	MyDrawTextV *part[10];
};

//カウントダウン画面
class CountDown : public	SubScene {
public:
	CountDown(DecorationItem *decorationItem, const int thisScene, const int playScene);
	int Switch(const int scene);
	~CountDown();
private:
	void ContentUpdate();
	void ContentView();
	int count; //カウンタ
	int thisScene, playScene; //CountDown画面のシーン、プレイモードのシーン
	BlackBox *blackBox;
	MyDrawText *text;
	MyDrawCircle *circle;
	MyDrawCircleGauge *countCircle1;
	MyDrawCircle *countCircle2;
	MyDrawCircle *countCircle3;
	const int max = 120;
};

#endif