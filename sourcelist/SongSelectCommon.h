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
#include "User.h"

// 曲選択画面タイトル
class SongSelectTitle : public SubScene {
public:
	SongSelectTitle(Font *font); // 初期化
	void ContentUpdate(); // 計算
	void ContentView(); // 表示
	~SongSelectTitle();
private:
	DrawTitle *title;
	DrawSubtitle *subTitle;
};

// 曲選択画面カバー関係
class SongInformation : public SubScene {
public:
	SongInformation(Font *font, Songs *songs, Touch *touch, User *user); // 初期化
	void Load();
	void ContentView(); // 表示
	void ContentUpdate();
	void Delete();
	~SongInformation();
private:
	int n, now;
	User *user;
	Touch *touch;
	SongSelectCover *songCover[256];
	Songs *songs;
	SongSelectCover *nowSong;
	MyDrawGraph *grad[2]; // カバー画像
// 	MyDrawGraph *box; // カバー画像
	MyDrawBox *myDrawBox;
	MyDrawText *songLast[2];
};

#endif