#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "DxLib.h"
#include "Songs.h"

class ThroughPlay {
public:
	ThroughPlay(Song *song);
	void View();
	~ThroughPlay();
private:
	Song *song;
};

#endif