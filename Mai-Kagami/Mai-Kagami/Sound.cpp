#include "Sound.h"

//効果音ロード
SoundEffect::SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++) 
		id[i] = LoadSoundMem(path[i]);
}

//効果音IDを削除
int SoundEffect::GetSoundEffect(int SoundType) {
	return id[SoundType];
}

SoundEffect::~SoundEffect() {
	for (int i = 0; i < SOUND_NUM; i++)
		DeleteSoundMem(id[i]);	//効果音を削除
}