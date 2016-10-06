#ifndef _SOUND_H_INCLUDE_
#define _SOUND_H_INCLUDE_

#include "DxLib.h"

#define SOUND_NUM 4

enum sound{SOUND_EFFECT_LOGIN, SOUND_EFFECT_CHOICE, SOUND_EFFECT_DECIDE, SOUND_EFFECT_ERROR};


class SoundEffect {
public:
	SoundEffect();
	void PlaySoundEffect(int SoundType);
	~SoundEffect();
private:
	int id[SOUND_NUM];
	char path[SOUND_NUM][64] = {
		"./se/decide.wav",
		"./se/choice.wav",
		"./se/decide.wav",
		"./se/error.wav"
	};

};
#endif // ! _SOUND_H_INCLUDE_
