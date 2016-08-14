#ifndef __THROUGHOPTION_H_INCLUDED__
#define __THROUGHOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Draw.h"
#include "Touch.h"
#include "SongSelectDefine.h"
#include "Songs.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "SongSelectDefine.h"

class ThroughOptionButton : public SubScene{
public:
	ThroughOptionButton(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~ThroughOptionButton();
private:
	Touch *touch;
	Songs *songs;
	SpeedOption *speedOption;
	Button *button[2];
	MyDrawText *speed[2];
};

#endif