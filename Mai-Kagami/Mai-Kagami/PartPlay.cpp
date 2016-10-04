#include "PartPlay.h"

PartStart::PartStart(DecorationItem *decorationItem)
	: StartSceen(decorationItem, PART_START, PART_PLAY) {}

//ïîï™ó˚èKâÊñ 
PartPlay::PartPlay(DecorationItem *decorationItem, Songs *songs, Touch *touch)
	: PlayScreen(decorationItem, songs, touch, PART_START, PART_COUNTDOWN, PART_PLAY, PART_NEXT) {}