#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "Songs.h"
#include "DrawText.h"
#include "DrawObject.h"

class ThroughPlay {
public:
	ThroughPlay(Font *font);
	void Load(Song *song);
	void View();
	void Update();
	~ThroughPlay();
private:
	Font *font;
	Song *song;
	MyDrawTextLine *songTitle;
	MyDrawText *songArtist;
	MyDrawBar *barAll, *barNow;
	MyDrawCircle *circle[2];
	MyDrawTextV *part[10];
};

#endif