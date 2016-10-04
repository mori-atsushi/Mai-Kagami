#include "Sound.h"

//Œø‰Ê‰¹ƒ[ƒh
SoundEffect::SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++)
		id[i] = LoadSoundMem(path[i]);
}

//Œø‰Ê‰¹ID‚ğíœ
int SoundEffect::Get(int SoundType) {
	return id[SoundType];
}

SoundEffect::~SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++)
		DeleteSoundMem(id[i]);	//Œø‰Ê‰¹‚ğíœ
}