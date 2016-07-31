#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "Songs.h"
#include "DrawText.h"

class ThroughPlay {
public:
	ThroughPlay(Font *font, Song *song);
	void View();
	~ThroughPlay();
private:
	Song *song;
	MyDrawTextLine *songTitle;
	MyDrawText *songArtist;
};

#endif