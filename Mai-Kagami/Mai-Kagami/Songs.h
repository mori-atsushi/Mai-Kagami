#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "DxLib.h"

class Song {
public:
	Song(const int id, const char *title, const char *artist, const char *folder);
	char *GetSongTitle(); //曲名取得
	char *GetSongArtist(); //アーティスト取得
private:
	char cover[256], music[256], movie[256], title[256], artist[256];
	int id;
};

class Songs {
public:
	Songs();
	int GetSongNum(); //曲数取得
	Song *GetSong(int x);
private:
	Song *song[256];
	int n; //曲数
};

#endif