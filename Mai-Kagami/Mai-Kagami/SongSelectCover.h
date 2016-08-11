#ifndef __SONGSELECTCOVER_H_INCLUDED__
#define __SONGSELECTCOVER_H_INCLUDED__

#include <string>
#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawGraph.h"
#include "DrawObject.h"
#include "Font.h"
#include "SongSelectDefine.h"
#include "Songs.h"

class SongSelectCover : public Song{
public:
	SongSelectCover(Font *font, Song *song, const int now);
	void Load();
	void Release();
	void Update(int, int);  // Change ÇìùçáÇµÇΩÇÃÇ≈ÅAà¯êîí«â¡ Jaity
	void Draw(int scene);
private:
	void Change(int num, int max); // publicÇ©ÇÁí«ï˙Ç≥ÇÍÇ‹ÇµÇΩ Jaity
	boolean playFlag = 0;
	Font *font;
};

#endif