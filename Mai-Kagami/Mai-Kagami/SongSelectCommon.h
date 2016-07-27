#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "Common.h"
#include "Touch.h"
#include "Font.h"
#include "Song.h"

#define BACK_TOP -2
#define BACK -1
#define MAIN 0
#define MODE 1
#define OPTION1 2
#define OPTION2 3

//曲選択画面タイトル
class SongSelectTitle {
public:
	SongSelectTitle(Font *font); //初期化
	void Update(int scene); //計算
	void View(int scene); //表示
	~SongSelectTitle();
private:
	MyDrawText *myDrawText;
	MyDrawText *subTitle;
	MyDrawLine *myDrawLine;
};

//曲選択画面カバー関係
class SongSelectCover {
public:
	SongSelectCover(Font *font); //初期化
	void View(int scene); //表示
	void Update(Touch *touch, int scene);
	~SongSelectCover();
private:
	int n, now;
	Song *song[256];
	MyDrawGraph *grad[2]; //カバー画像
	MyDrawGraph *box; //カバー画像
	MyDrawBox *myDrawBox;
};

#endif