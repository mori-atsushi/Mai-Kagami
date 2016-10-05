#include "Sound.h"

//Œø‰Ê‰¹ƒ[ƒh
SoundEffect::SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++) 
		id[i] = LoadSoundMem(path[i]);
}

//Œø‰Ê‰¹Ä¶
void SoundEffect::PlaySoundEffect(int SoundType) {
	PlaySoundMem(id[SoundType], DX_PLAYTYPE_BACK);
}

SoundEffect::~SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++)
		DeleteSoundMem(id[i]);	//Œø‰Ê‰¹‚ğíœ
}