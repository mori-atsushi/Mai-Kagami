#include "PartOption.h"

PartOptionPreview2::PartOptionPreview2(DecorationItem *decorationItem, Songs *songs, Touch *touch) 
	: PartOptionPreview(decorationItem, songs, touch, OPTION2, OPTION2_PART, OPTION2_SPEED) {
	this->decorationItem = decorationItem;
	button[0] = new CircleButton(decorationItem, touch, "スタート!", 3, WIDTH * 0.8);
	button[1] = new CircleButton2(decorationItem, touch, "戻る", 4);
}

int PartOptionPreview2::Switch(const int scene) {
	if (button[0]->GetTouch() == 1) {
		return NEXT2;
	}
	if (button[1]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return MODE;
	}
	return PartOptionPreview::Switch(scene);
}

void PartOptionPreview2::ContentView() {
	for (int i = 0; i < 2; i++)
		button[i]->View();
	PartOptionPreview::ContentView();
}

PartOptionPreview2::~PartOptionPreview2() {
	for (int i = 0; i < 2; i++)
		delete button[i];
}

PartOptionButton::PartOptionButton(DecorationItem *decorationItem, Songs *songs, Touch *touch) 
	: PartOptionPop(decorationItem, songs, touch, OPTION2, OPTION2_PART, OPTION2_SPEED, new PartOptionPreview2(decorationItem, songs, touch)) {}