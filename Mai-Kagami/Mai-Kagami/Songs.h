#ifndef __SONGS_H_INCLUDED__
#define __SONGS_H_INCLUDED__

#include "DxLib.h"

class Song {
public:
	Song(const int id, const char *title, const char *artist, const char *folder);
private:
	char cover[256], music[256], movie[256];
	int id;
};

class Songs {
public:
	Songs();
private:
	Song *song[256];
	int n; //ã»êî
};

#endif