#ifndef __MODESELECT_H_INCLUDED__
#define __MODESELECT_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "SongSelectDefine.h"
#include "Font.h"
#include "Scene.h"
#include "Touch.h"

class ModeSelectButton : public SubScene{
public:
	ModeSelectButton(Font *font, Touch *touch);
	SongSelectScene Switch(const SongSelectScene scene);
	void ContentUpdate();
	void ContentView();
	~ModeSelectButton();
private:
	Button *button[3];
};

#endif