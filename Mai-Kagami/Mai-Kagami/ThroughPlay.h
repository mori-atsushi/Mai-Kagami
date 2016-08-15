#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "DxLib.h"
#include "Songs.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "Touch.h"
#include "KinectDistance.h"

//進捗バー
class ThroughPlayBar {
public:
	ThroughPlayBar(Font *font);
	void Load(Song *song);
	void Update();
	void View();
	~ThroughPlayBar();
private:
	Font *font;
	Song *song;
	MyDrawBar *barAll, *barNow;
	MyDrawCircle *circle[2];
	MyDrawTextV *part[10];
};

//カウントダウン画面用再生三角形
class PlayTriangle : public MyDrawTriangle {
public:
	PlayTriangle(const float x, const float y);
};


//カウントダウン画面
class ThroughCountDown {
public:
	ThroughCountDown(Font *font);
	void Update();
	void View();
	boolean GetFlag();
	void SetFlag(const boolean flag);
	~ThroughCountDown();
private:
	boolean flag; //表示非表示
	int count; //カウンタ
	BlackBox *blackBox;
	MyDrawText *text;
	MyDrawCircle *circle;
	MyDrawCircleGauge *countCircle1;
	MyDrawCircle *countCircle2;
	PlayTriangle *playTriangle;
	const int max = 120;
};

//通し練習画面
class ThroughPlay : public SubScene {
public:
	ThroughPlay(Font *font, Songs *songs, Touch *touch);
	void Load();
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~ThroughPlay();
private:
	Songs *songs;
	Song *song;
	Touch *touch;
	ThroughPlayBar *throughPlayBar; //進捗バー
	ThroughCountDown *throughCountDown; //カウントダウン画面
};

#endif