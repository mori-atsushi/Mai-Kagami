#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "Song.h"
#include "DxLib.h"
#include "DrawGraph.h"

class Songs {
public:
	Songs();
	int GetSongNum(); //‹È”æ“¾
	Song *GetSong(int x);
	int GetNowSong();
private:
	Song *song[256];
	int n; //‹È”
};

#endif