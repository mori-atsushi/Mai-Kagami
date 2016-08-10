#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs) {
	speedOption = new SpeedOption(font, songs);
	button = new CircleButton(font, "スタート!", 2);
}


//モード選択ボタン表示
void ThroughOptionButton::View() {
	speedOption->View();
	button->View();
}

void ThroughOptionButton::Update(int scene) {
	if (scene == OPTION1)
		speedOption->Update();
}

//モード選択削除
ThroughOptionButton::~ThroughOptionButton() {
	delete button;
	delete speedOption;
}