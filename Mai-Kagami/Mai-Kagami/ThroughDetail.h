#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "CommonText.h"
#include "ThroughDefine.h"
#include "Button.h"
#include "SeetingPop.h"

class ThroughFinish {
public:
	ThroughFinish(Font *font);
	void View();
	~ThroughFinish();
private:
	BlackBox *blackBox;
	Button *button[4];
};

class ThroughDetail {
public:
	ThroughDetail(Font *font);
	void View();
	void Update(const int scene);
	~ThroughDetail();
private:
	DrawTitle *title;
	Button *button;
	ThroughFinish *throughFinish;
	int scene;
};

#endif