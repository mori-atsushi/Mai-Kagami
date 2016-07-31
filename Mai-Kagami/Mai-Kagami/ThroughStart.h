#ifndef __THROUGHSTART_H_INCLUDED__
#define __THROUGHSTART_H_INCLUDED__

#include "DxLib.h"
#include "Font.h"
#include "DrawGraph.h"
#include "DrawText.h"

class ThroughStart{
public:
	ThroughStart(Font *f);
	void View();
	~ThroughStart();
private:
	MyDrawGraph *myDrawGraph;
	MyDrawText *wait;
	MyDrawText *caution;
	MyDrawTexts *annnotation;
};

#endif