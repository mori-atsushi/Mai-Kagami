#include "DecorationItem.h"

DecorationItem::DecorationItem() 
	: Font(), SoundEffect(){
	font = new Font();
	soundEffect = new SoundEffect();
}

int DecorationItem::GetFont(int point) {
	return GetFont(point);
}

int DecorationItem::GetSoundEffect(int SoundType) {
	return GetSoundEffect(SoundType);
}

DecorationItem::~DecorationItem() {
	delete font;
	delete soundEffect;
}