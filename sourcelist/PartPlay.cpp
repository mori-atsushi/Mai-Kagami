#include "PartPlay.h"

PartStart::PartStart(Font *f)
	: StartSceen(f, PART_START, PART_PLAY) {}

// •”•ª—ûK‰æ–Ê
PartPlay::PartPlay(Font *font, Songs *songs, Touch *touch, Kinect *kinect)
	: PlayScreen(font, songs, touch, kinect, PART_START, PART_COUNTDOWN, PART_PLAY, PART_NEXT) {}