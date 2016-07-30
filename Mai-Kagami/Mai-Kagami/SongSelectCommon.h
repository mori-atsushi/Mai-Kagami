#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "Common.h"
#include "Touch.h"
#include "Font.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "SongSelectDefine.h"

//曲選択画面タイトル
class SongSelectTitle : public Draw {
public:
	SongSelectTitle(Font *font, const float x, const float y); //初期化
	void Update(int scene); //計算
	void View(); //表示
	~SongSelectTitle();
private:
	MyDrawTextLine *title;
	MyDrawText *subTitle;
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
	MyDrawTextLine *songTitle;
	MyDrawText *songArtist;
	MyDrawText *songLast[2];
};

#endif