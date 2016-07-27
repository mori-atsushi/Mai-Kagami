#ifndef __THROUGHOPTION_H_INCLUDED__
#define __THROUGHOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Common.h"
#include "Font.h"
#include "Draw.h"

class ThroughOptionButton {
public:
	ThroughOptionButton(Font *font);
	void View();
	~ThroughOptionButton();
private:
	Button *button[4];
	MyDrawText *speed[2];
};

class PreviewMovie {
public:
	void Load(char *folder);
private:
	int movieId;
};


#endif