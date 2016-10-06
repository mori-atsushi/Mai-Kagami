#ifndef __MODESELECT_H_INCLUDED__
#define __MODESELECT_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "SongSelectDefine.h"
#include "DecorationItem.h"
#include "Scene.h"
#include "Touch.h"

class ModeSelectButton : public SubScene{
public:
	ModeSelectButton(DecorationItem *decorationItem, Touch *touch);
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~ModeSelectButton();
private:
	DecorationItem *decorationItem;
	Button *button[3];
};

#endif