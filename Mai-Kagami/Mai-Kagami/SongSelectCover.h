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
	void Update(int, int);  // Change を統合したので、引数追加 Jaity
	void Draw(int scene);
private:
	void Change(int num, int max); // publicから追放されました Jaity
	float CalcY();		// 位置番号から高さを決定
	int CalcAlpha();		// 位置番号から高さを決定
	double CalcEx();		// 位置番号から高さを決定
	boolean playFlag = 0;
	Font *font;
};

#endif