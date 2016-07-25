#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Common.h"
#include "Touch.h"
#include "Loading.h"
#include "Song.h"
#include "Font.h"

//曲選択画面タイトル
class SongSelectTitle {
public:
	SongSelectTitle(Font *font); //初期化
	void View(); //表示
	~SongSelectTitle();
private:
	MyDrawText *myDrawText;
	MyDrawLine *myDrawLine;
};

//曲選択画面カバー関係
class SongSelectCover {
public:
	SongSelectCover(Font *font); //初期化
	void View(); //表示
	void Update(int num = -1);
	~SongSelectCover();
private:
	Song *song[256];
	MyDrawGraph *grad[2]; //カバー画像
	MyDrawGraph *box; //カバー画像
	MyDrawBox *myDrawBox;
};

//曲選択画面ボタン関係
class SongSelectButton {
public:
	SongSelectButton(Font *font); //初期化
	void View(); //表示
	~SongSelectButton();
private:
	Button *button[4];
};

//ポップアップ関係
class SongSelectPop {
public:
	SongSelectPop(Font *font);
	void Update(int num);
	void View();
	boolean Flag();
	~SongSelectPop();
private:
	MyDrawBox *myDrawBox;
	MyDrawText *title;
	MyDrawText *message;
	MyDrawText *buttonMessage[2];
	MyDrawRing *buttonRing[2];
	boolean flag;
};

//曲選択画面関係
class SongSelect {
public:
	SongSelect(Font *font);
	int Update();
	void View(Loading *loading);
private:
	Font *f;
	SongSelectTitle *songSelectTitle; //曲選択画面タイトル
	SongSelectCover *songSelectCover; //選択中の曲
	SongSelectButton *songSelectButton; //ボタン関係
	SongSelectPop *songSelectPop; //終了用ポップアップ
	Touch touch; //サイドタッチパネル
	int loadFlag;
	boolean Load();
	void Delete();
};

#endif