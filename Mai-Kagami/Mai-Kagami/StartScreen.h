#ifndef __STARTSCREEN_H_INCLUDED__
#define __STARTSCREEN_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "SeetingPop.h"
#include "Scene.h"

class StartSceen : public SubScene {
public:
	StartSceen(DecorationItem *decorationItem, const int startScene, const int playScene);
	void Load();
	~StartSceen();
private:
	void ContentUpdate();
	void ContentView();
	int startScene;
	int playScene;
	MyDrawGraph *myDrawGraph;
	MyDrawText *wait;
	MyDrawText *caution;
	MyDrawTexts *annotation;
	BlackBox *blackBox;
};

#endif