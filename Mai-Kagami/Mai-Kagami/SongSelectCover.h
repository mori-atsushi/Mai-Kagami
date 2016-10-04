#ifndef __SONGSELECTCOVER_H_INCLUDED__
#define __SONGSELECTCOVER_H_INCLUDED__

#include <string>
#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawGraph.h"
#include "DrawObject.h"
#include "DecorationItem.h"
#include "SongSelectDefine.h"
#include "Songs.h"

class SongSelectCover : public Song{
public:
	SongSelectCover(DecorationItem *decorationItem, Song *song, const int now);
	void Load(int);
	void Release();
	void Update(int, int);
	void Draw(int scene);
private:
	void Change(int num, int max);
	float CalcY();
	int CalcAlpha();
	int CalcAlphaWhite();
	double CalcEx();
	boolean playFlag = 0;
	DecorationItem *decorationItem;
};

#endif