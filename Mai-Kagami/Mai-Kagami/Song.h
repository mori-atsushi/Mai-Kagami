#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include <string>
#include "DxLib.h"
#include "Draw.h"

class Song {
public:
	Song(char *title, char *artist, char *folder, int now);
	void Update();
	void Draw();
	void Change(int num);
	~Song();
private:
	MyDrawText *songTitle;
	MyDrawText *songArtist;
	MyDrawText *songLast[2];
	MyDrawLine *myDrawLine;
	MyDrawGraph *myDrawGraph; //カバー画像
	MyDrawGraph *songCover[6]; //カバー画像
	int n;
};

#endif