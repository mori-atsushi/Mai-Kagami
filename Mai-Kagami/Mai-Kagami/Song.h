#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include <string>
#include "DxLib.h"
#include "Draw.h"
#include "Font.h"

class Song {
public:
	Song(Font *font, char *title, char *artist, char *folder, int now);
	void Update();
	void Draw(int scene);
	void Change(int num);
	void ChangeSpeed(int num);
	void LoadMovie();
	void StopMovie();
	void ReleaseMovie();
	int GetNow();
	~Song();
private:
	char music[256];
	char movie[256];
	int n, speed;
	boolean playFlag = 0;
	Font *font;
	MyDrawText *songTitle;
	MyDrawText *songArtist;
	MyDrawText *songLast[2];
	MyDrawLine *myDrawLine;
	MyDrawGraph *myDrawGraph; //ÉJÉoÅ[âÊëú
	MyDrawMovie *myDrawMovie;
};

#endif