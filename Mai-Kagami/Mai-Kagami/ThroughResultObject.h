#ifndef __THROUGHRESULTOBJECT_H_INCLUDED__
#define __THROUGHRESULTOBJECT_H_INCLUDED__

#include "Dxlib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"

class ScoreBar : public Draw {
public:
	ScoreBar(Font *font, const float y, const char *title, const char *para1, const char *para2);
	void Load(const int p);
	~ScoreBar();
private:
	void ContentView();
	MyDrawTextLine *title;
	MyDrawText *para[2];
	MyDrawBox *box[8];
	MyDrawGraph *mark;
	MyDrawText *score;
};

class TimingBar : public ScoreBar {
public:
	TimingBar(Font *font);
};

class ExpressionBar : public ScoreBar {
public:
	ExpressionBar(Font *font);
};

class ResultComment : public Draw {
public:
	ResultComment(Font *font);
	~ResultComment();
private:
	void ContentView();
	MyDrawTextLine *title;
	MyDrawTexts *comment;
};

#endif