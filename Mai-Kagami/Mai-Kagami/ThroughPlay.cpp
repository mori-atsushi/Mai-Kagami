#include "ThroughPlay.h"

ThroughPlay::ThroughPlay(DecorationItem *decorationItem, Songs *songs, Touch *touch) 
	: PlayScreen(decorationItem , songs, touch, THROUGH_START, THROUGH_COUNTDOWN, THROUGH_PLAY, THROUGH_NEXT) {}