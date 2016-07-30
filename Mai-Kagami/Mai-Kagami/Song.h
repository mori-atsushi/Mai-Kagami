#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include <string>
#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawGraph.h"
#include "DrawObject.h"
#include "Font.h"
#include "SongSelectDefine.h"
#include "Songs.h"

class Song2 : public Song{
public:
	Song2(Font *font, Song *song, const int now);
	void Load();
	void Release();
	void Update();
	void Draw(int scene);
	void Change(int num, int max);
	void ChangeSpeed(int num);
	void LoadMovie();
	void StopMovie();
	void ReleaseMovie();
	int GetNow();
private:
	int n, speed;
	boolean playFlag = 0;
	Font *font;
};

#endif