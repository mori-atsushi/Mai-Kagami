#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"

class Song {
public:
	Song(const int id, const char *title, const char *artist, const char *folder);
	char *GetSongTitle(); //曲名取得
	char *GetSongArtist(); //アーティスト取得
	int GetNow();
	void SetNow(const int n);
	void ChangeSpeed(int num);
	MyDrawGraph *coverGraph; //カバー画像
	MyDrawMovie *danceMovie; //動画
protected:
	char music[256], title[256], artist[256]; //音楽ファイル、タイトル、アーティスト名
private:
	int id, *n; //ID、現在の番号
};

class Songs {
public:
	Songs();
	int GetSongNum(); //曲数取得
	Song *GetSong(int x);
	int GetNowSong();
private:
	Song *song[256];
	int n; //曲数
};

#endif