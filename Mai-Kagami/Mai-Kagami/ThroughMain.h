#ifndef __THROUGHMAIN_H_INCLUDED__
#define __THROUGHMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "Songs.h"
#include "Main.h"
#include "DrawText.h"
#include "ThroughStart.h"
#include "ThroughDefine.h"
#include "ThroughPlay.h"
#include "ThroughPause.h"
#include "Touch.h"
#include "KinectDistance.h"

class ThroughMain {
public:
	ThroughMain(Font *font, Touch *touch, Songs *songs);
	int Update();
	void View();
	~ThroughMain();
private:
	Font *f;
	Songs *songs;
	ThroughStart *throughStart;
	ThroughPlay *throughPlay;
	ThroughPause *throughPause;
	int loadFlag;
	void Load();
	void Delete();
	int scene;
	Touch *touch;
};

#endif