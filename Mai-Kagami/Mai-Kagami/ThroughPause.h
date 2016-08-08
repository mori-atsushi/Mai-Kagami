#ifndef __THROUGHPAUSE_H_INCLUDED__
#define __THROUGHPAUSE_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "ThroughDefine.h"

class ThroughPause {
public:
	ThroughPause(Font *font);
	void Update(int scene);
	void Load();
	void View();
	~ThroughPause();
private:
	CircleGraphButton *pauseButton; //ˆêŽž’âŽ~—pƒ{ƒ^ƒ“
};

#endif