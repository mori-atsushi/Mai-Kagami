#ifndef __THROUGHDETAIL_H_INCLUDED__
#define __THROUGHDETAIL_H_INCLUDED__

#include "DxLib.h"
#include "CommonText.h"
#include "Button.h"

class ThroughDetail {
public:
	ThroughDetail(Font *font);
	void View();
	~ThroughDetail();
private:
	DrawTitle *title;
	Button *button;
};

#endif