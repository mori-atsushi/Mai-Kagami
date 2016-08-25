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
	void Load(int);
	void Release();
	void Update(int, int);  // Change ‚ğ“‡‚µ‚½‚Ì‚ÅAˆø”’Ç‰Á Jaity
	void Draw(int scene);
private:
	void Change(int num, int max); // public‚©‚ç’Ç•ú‚³‚ê‚Ü‚µ‚½ Jaity
	float GetY();            // ˆÊ’u”Ô†‚©‚ç‚‚³‚ğŒˆ’è
	boolean playFlag = 0;
	Font *font;
};

#endif