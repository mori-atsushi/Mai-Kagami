#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"

class Song {
public:
	Song(const int id, const char *title, const char *artist, const char *folder);
	char *GetSongTitle(); //曲名取得
	char *GetSongArtist(); //アーティスト取得
	int GetNow(); //現在の位置IDを取得
	void SetNow(const int n); //位置IDをセット
	void ChangeSpeed(int num); //動画の再生速度変更
	MyDrawGraph *coverGraph; //カバー画像
	MyDrawMovie *danceMovie; //動画
protected:
	char music[256], title[256], artist[256]; //音楽ファイル、タイトル、アーティスト名
private:
	int id, *n; //ID、現在の番号
};

//パート情報
class SongPart {
public:
	SongPart(const int flame, const char *name);
private:
	int flame;
	std::string name; //文字
};

#endif