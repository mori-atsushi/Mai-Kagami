#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "Songs.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"

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
class ThroughPlay {
public:
	ThroughPlay(Font *font);
	void Load(Song *song);
	void View();
	void Update();
	~ThroughPlay();
private:
	Font *font;
	Song *song;
	CircleGraphButton *pauseButton; //一時停止用ボタン
	ThroughPlayBar *throughPlayBar; //進捗バー
};

#endif