#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "PlayScreen.h"
#include "ThroughDefine.h"

// �ʂ����K���
class ThroughPlay : public PlayScreen {
public:
	ThroughPlay(Font *font, Songs *songs, Touch *touch, Kinect *kinect);
};

#endif