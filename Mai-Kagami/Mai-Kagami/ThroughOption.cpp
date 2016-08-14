#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs, Touch *touch) {
	this->touch = touch;
	speedOption = new SpeedOption(font, songs);
	button[0] = new CircleButton(font, "スタート!", 2);
	button[1] = new CircleButton2(font, "戻る", 4);
}

int ThroughOptionButton::Switch(const int scene) {
	if (touch->Get(2) == 1)
		return NEXT;
	if (touch->Get(4) == 1)
		return MODE;
	return scene;
}

//モード選択ボタン計算
void ThroughOptionButton::ContentUpdate() {
	if (nowScene == OPTION1) {
		viewFlag = TRUE;
		speedOption->Check(touch);
	}
	else {
		viewFlag = FALSE;
	}
}

//オプション画面ボタン表示
void ThroughOptionButton::ContentView() {
	speedOption->View();
	for(int i = 0; i < 2; i++)
		button[i]->View();
}

//オプション画面ボタン削除
ThroughOptionButton::~ThroughOptionButton() {
	for(int i = 0; i < 2; i++)
		delete button[i];
	delete speedOption;
}