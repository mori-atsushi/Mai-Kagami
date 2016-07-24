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

//曲選択画面タイトル
class SongSelectTitle {
public:
	SongSelectTitle(); //初期化
	void View(); //表示
	~SongSelectTitle();
private:
	MyDrawText *myDrawText;
	MyDrawLine *myDrawLine;
};

//曲選択画面カバー関係
class SongSelectCover {
public:
	SongSelectCover(); //初期化
	void View(); //表示
	~SongSelectCover();
private:
	MyDrawText *songTitle;
	MyDrawText *songArtist;
	MyDrawText *songLast[2];
	MyDrawLine *myDrawLine;
	MyDrawGraph *myDrawGraph; //カバー画像
	MyDrawGraph *songCover[6]; //カバー画像
	MyDrawGraph *grad[2]; //カバー画像
	MyDrawGraph *box; //カバー画像
	MyDrawBox *myDrawBox;
};

//曲選択画面ボタン関係
class SongSelectButton {
public:
	SongSelectButton(); //初期化
	void View(); //表示
	~SongSelectButton();
private:
	Button *button[4];
};

//曲選択画面関係
class SongSelect {
public:
	SongSelect();
	int Update();
	void View(Loading *loading);
private:
	SongSelectTitle *songSelectTitle; //曲選択画面タイトル
	SongSelectCover *songSelectCover; //選択中の曲
	SongSelectButton *songSelectButton; //ボタン関係
	Touch touch; //サイドタッチパネル
	int loadFlag;
	boolean Load();
	void Delete();
};

#endif