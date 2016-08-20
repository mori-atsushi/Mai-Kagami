#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(Font *font, Songs *songs, Touch *touch) 
	: PlayScreen(font , songs, touch, THROUGH_START, THROUGH_COUNTDOWN, THROUGH_PLAY, THROUGH_NEXT) {}