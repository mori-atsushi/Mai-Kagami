#ifndef __THROUGHSTART_H_INCLUDED__
#define __THROUGHSTART_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "ThroughDefine.h"

class ThroughStart{
public:
	ThroughStart(Font *f);
	void Update(int scene);
	void View();
	~ThroughStart();
private:
	MyDrawGraph *myDrawGraph;
	MyDrawText *wait;
	MyDrawText *caution;
	MyDrawTexts *annnotation;
	BlackBox *blackBox;
};

#endif