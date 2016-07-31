#ifndef __THROUGHMAIN_H_INCLUDED__
#define __THROUGHMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "Songs.h"
#include "Main.h"
#include "DrawText.h"
#include "ThroughStart.h"

class ThroughMain {
public:
	ThroughMain(Font *font, Songs *songs);
	int Update();
	void View();
	~ThroughMain();
private:
	Font *f;
	ThroughStart *throughStart;
	int loadFlag;
	void Load();
	void Delete();
};

#endif