#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "Song.h"
#include "DxLib.h"
#include "DrawGraph.h"
#include "Font.h"

class Songs {
public:
	Songs(Font *font);
	int GetSongNum(); //ã»êîéÊìæ
	Song *GetSong(int x);
	int GetNowSong();
private:
	Song *song[256];
	int n; //ã»êî
};

#endif