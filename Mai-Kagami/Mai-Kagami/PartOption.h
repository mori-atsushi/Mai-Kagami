#ifndef __PARTOPTION_H_INCLUDED__
#define __PARTOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "Font.h"
#include "Songs.h"
#include "Song.h"
#include "Touch.h"
#include "SongSelectDefine.h"
#include "SeetingPop.h"
#include "Button.h"

class PartOptionSpeedPop : public SpeedPop {
public:
	PartOptionSpeedPop(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
private:
	void ContentUpdate();
};

class PartOptionButton : public SubScene {
public:
	PartOptionButton(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
	void Load();
	void Delete();
	~PartOptionButton();
private:
	Songs *songs;
	void ContentUpdate();
	void ContentView();
	Button *button[4];
	PartOptionSpeedPop *speedPop;
};


#endif