#ifndef __THROUGHOPTION_H_INCLUDED__
#define __THROUGHOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Draw.h"
#include "Touch.h"
#include "SongSelectDefine.h"
#include "Songs.h"

class ThroughOptionButton {
public:
	ThroughOptionButton(Font *font, Songs *songs);
	void View();
	void Update(Touch *touch, int scene);
	~ThroughOptionButton();
private:
	Songs *songs;
	Button *button[4];
	MyDrawText *speed[2];
};

#endif