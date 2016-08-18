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
#include "ThroughCountDown.h"

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

//通し練習画面
class ThroughPlay : public SubScene {
public:
	ThroughPlay(Font *font, Songs *songs, Touch *touch);
	void Load();
	ThroughScene Switch(const ThroughScene scene);
	void Delete();
	~ThroughPlay();
private:
	void ContentUpdate();
	void ContentView();
	Songs *songs;
	Song *song;
	ThroughPlayBar *throughPlayBar; //進捗バー
	ThroughCountDown *throughCountDown; //カウントダウン画面
};

#endif