#ifndef __THROUGHSTART_H_INCLUDED__
#define __THROUGHSTART_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "ThroughDefine.h"
#include "SeetingPop.h"
#include "Scene.h"

class ThroughStart : public SubScene{
public:
	ThroughStart(Font *f);
	void ContentUpdate();
	void ContentView();
	~ThroughStart();
private:
	MyDrawGraph *myDrawGraph;
	MyDrawText *wait;
	MyDrawText *caution;
	MyDrawTexts *annotation;
	BlackBox *blackBox;
};

#endif