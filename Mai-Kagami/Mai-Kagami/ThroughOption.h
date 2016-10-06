#ifndef __THROUGHOPTION_H_INCLUDED__
#define __THROUGHOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "DecorationItem.h"
#include "Draw.h"
#include "Touch.h"
#include "SongSelectDefine.h"
#include "Songs.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "SongSelectDefine.h"

class ThroughOptionButton : public SubScene{
public:
	ThroughOptionButton(DecorationItem *decorationItem, Songs *songs, Touch *touch);
	int Switch(const int scene);
	~ThroughOptionButton();
private:
	DecorationItem *decorationItem;
	Songs *songs;
	void ContentUpdate();
	void ContentView();
	SpeedOption *speedOption;
	Button *button[2];
	MyDrawText *speed[2];
};

#endif