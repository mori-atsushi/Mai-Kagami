#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs) {
	speedOption = new SpeedOption(font, songs);
	button[0] = new CircleButton(font, "スタート!", 2);
	button[1] = new CircleButton2(font, "戻る", 4);
}


//モード選択ボタン表示
void ThroughOptionButton::View() {
	speedOption->View();
	for(int i = 0; i < 2; i++)
		button[i]->View();
}

void ThroughOptionButton::Check(Touch *touch) {
	speedOption->Check(touch);
}

//モード選択削除
ThroughOptionButton::~ThroughOptionButton() {
	for(int i = 0; i < 2; i++)
		delete button[i];
	delete speedOption;
}