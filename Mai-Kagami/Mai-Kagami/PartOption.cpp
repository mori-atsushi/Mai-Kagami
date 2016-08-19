#include "PartOption.h"

PartOptionButton::PartOptionButton(Font *font, Songs *songs, Touch *touch) {
	button[0] = new CircleButton(font, touch, "区間：イントロ ～ Aパート１", 0, WIDTH * 0.75);
	button[1] = new CircleButton(font, touch, "速度：×0.6", 1, WIDTH * 0.75);
	button[2] = new CircleButton(font, touch, "スタート!", 2, WIDTH * 0.75);
	button[3] = new CircleButton2(font, touch, "戻る", 4);
}

SongSelectScene PartOptionButton::Switch(const SongSelectScene scene) {
	if (button[3]->GetTouch() == 1)
		return MODE;
	return scene;
}

void PartOptionButton::ContentUpdate() {
	if (nowScene == OPTION2)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void PartOptionButton::ContentView() {
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

PartOptionButton::~PartOptionButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}