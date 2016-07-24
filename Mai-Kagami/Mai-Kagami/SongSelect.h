#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Common.h"

//曲選択画面タイトル
class SongSelectTitle {
public:
	void Init(); //初期化
	void View(); //表示
private:
	MyDrawText myDrawText;
	MyDrawLine myDrawLine;
};

//曲選択画面カバー関係
class SongSelectCover {
public:
	void Init(); //初期化
	void View(); //表示
private:
	MyDrawText songTitle;
	MyDrawText songArtist;
	MyDrawText songLast[2];
	MyDrawLine myDrawLine;
	MyDrawGraph myDrawGraph; //カバー画像
	MyDrawGraph songCover[6]; //カバー画像
	MyDrawGraph grad[2]; //カバー画像
	MyDrawGraph box; //カバー画像
	MyDrawBox myDrawBox;
};

//曲選択画面ボタン関係
class SongSelectButton {
public:
	void Init(); //初期化
	void View(); //表示
private:
	Button button[4];
};

//曲選択画面関係
class SongSelect {
public:
	int Load();
	void Update();
	void View();
private:
	void LoadThread(); //ロードスレッド
	SongSelectTitle songSelectTitle; //曲選択画面タイトル
	SongSelectCover songSelectCover; //選択中の曲
	SongSelectButton songSelectButton; //ボタン関係
	int loadFlag;
};

#endif