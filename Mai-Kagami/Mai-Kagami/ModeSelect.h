#ifndef __MODESELECT_H_INCLUDED__
#define __MODESELECT_H_INCLUDED__

#include "DxLib.h"
#include "Common.h"
#include "Font.h"

class ModeSelectButton {
public:
	ModeSelectButton(Font *font);
	void View();
	~ModeSelectButton();
private:
	Button *button[3];
};

#endif