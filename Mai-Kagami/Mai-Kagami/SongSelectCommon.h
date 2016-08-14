#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "CommonText.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "SongSelectDefine.h"
#include "Scene.h"

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
class SongInformation : public SubScene {
public:
	SongInformation(Font *font, Songs *songs, Touch *touch); //初期化
	void Load();
	void ContentView(); //表示
	void ContentUpdate();
	void Delete();
	~SongInformation();
private:
	int n, now;
	Touch *touch;
	SongSelectCover *songCover[256];
	Songs *songs;
	SongSelectCover *nowSong;
	MyDrawGraph *grad[2]; //カバー画像
	MyDrawGraph *box; //カバー画像
	MyDrawBox *myDrawBox;
	MyDrawText *songLast[2];
};

#endif