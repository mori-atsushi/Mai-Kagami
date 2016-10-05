#ifndef __THROUGHPLAY_H_INCLUDED__
#define __THROUGHPLAY_H_INCLUDED__

#include "PlayScreen.h"
#include "ThroughDefine.h"

//í Çµó˚èKâÊñ 
class ThroughPlay : public PlayScreen {
public:
	ThroughPlay(DecorationItem *decorationItem, Songs *songs, Touch *touch, Kinect *kinect);
};

#endif