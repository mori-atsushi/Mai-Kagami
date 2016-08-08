#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "Font.h"
#include "Song.h"

class ThroughResult {
public:
	ThroughResult(Font *font);
	void Update();
	void Load(Song *song);
	void View();
	~ThroughResult();
private:
	MyDrawTextLine *title;
	Song *song;
};

#endif