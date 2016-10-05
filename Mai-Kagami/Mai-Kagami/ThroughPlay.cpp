#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(DecorationItem *decorationItem, Songs *songs, Touch *touch, Kinect *kinect)
	: PlayScreen(decorationItem, songs, touch, kinect, THROUGH_START, THROUGH_COUNTDOWN, THROUGH_PLAY, THROUGH_NEXT) {}