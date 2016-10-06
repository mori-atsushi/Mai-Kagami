#ifndef __PARTRESULTMAIN_H_INCLUDED__
#define __PARTRESULTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "DecorationItem.h"
#include "Touch.h"
#include "Songs.h"
#include "PartResultDefine.h"
#include "PartResult.h"

class PartResultMain : public Scene {
public:
	PartResultMain(DecorationItem *decorationItem, Touch *touch, Songs *songs);
	MainScene Switch(const MainScene scene);
	~PartResultMain();
private:
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
	int scene;
	int bgmHandle; //bgm
	DecorationItem *decorationItem;
	PartResult *partResult;
	PartFinish *partFinish;
};

#endif