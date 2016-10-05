#include "PartPlay.h"

PartStart::PartStart(DecorationItem *decorationItem)
	: StartSceen(decorationItem, PART_START, PART_PLAY) {}

//ïîï™ó˚èKâÊñ 
PartPlay::PartPlay(DecorationItem *decorationItem, Songs *songs, Touch *touch, Kinect *kinect)
	: PlayScreen(decorationItem, songs, touch, kinect, PART_START, PART_COUNTDOWN, PART_PLAY, PART_NEXT) {}