#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Font *font, Songs *songs, Touch *touch, Kinect *kinect) 
	: PlayScreen(font , songs, touch, kinect, THROUGH_START, THROUGH_COUNTDOWN, THROUGH_PLAY, THROUGH_NEXT) {}