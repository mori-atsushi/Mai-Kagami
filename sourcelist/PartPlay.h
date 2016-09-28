#ifndef __PARTPLAY_H_INCLUDED__
#define __PARTPLAY_H_INCLUDED__

#include "StartScreen.h"
#include "PlayScreen.h"
#include "PartDefine.h"

class PartStart : public StartSceen {
public:
	PartStart(Font *f);
};

// •”•ª—ûK‰æ–Ê
class PartPlay : public PlayScreen {
public:
	PartPlay(Font *font, Songs *songs, Touch *touch, Kinect *kinect);
};

#endif