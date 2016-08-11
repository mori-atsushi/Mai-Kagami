#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "CommonText.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "SongSelectDefine.h"

//曲選択画面タイトル
class SongSelectTitle {
public:
	SongSelectTitle(Font *font); //初期化
	void Update(int scene); //計算
	void View(); //表示
	~SongSelectTitle();
private:
	DrawTitle *title;
	DrawSubtitle *subTitle;
	int scene;
};

//曲選択画面カバー関係
class SongInformation {
public:
	SongInformation(Font *font, Songs *songs); //初期化
	void Load();
	void View(int scene); //表示
	void Update(Touch *touch, int scene);
	void Release();
	~SongInformation();
private:
	int n, now;
	SongSelectCover *songCover[256];
	Songs *songs;
	SongSelectCover *nowSong;
	MyDrawGraph *grad[2]; //カバー画像
	MyDrawGraph *box; //カバー画像
	MyDrawBox *myDrawBox;
	MyDrawText *songLast[2];
};

#endif