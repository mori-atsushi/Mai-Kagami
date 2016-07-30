#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs) {
	button[0] = new Button(font, "UP", 1, 0);
	button[1] = new Button(font, "DOWN", 2, 1);
	button[2] = new Button(font, "スタート!", 0, 2);
	button[3] = new Button(font, "戻る", 4);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "スピード", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "×1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
	ThroughOptionButton::songs = songs;
}


//モード選択ボタン表示
void ThroughOptionButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->View();
	for (int i = 0; i < 2; i++)
		speed[i]->View();
}

void ThroughOptionButton::Update(Touch *touch, int scene) {
	if (scene == OPTION1) {
		Song *song = songs->GetSong(songs->GetNowSong());

		char str[256];
		sprintf_s(str, sizeof(str), "×%1.1lf", song->GetSpeed());
		speed[1]->ChangeText(str);
	}
}

//モード選択削除
ThroughOptionButton::~ThroughOptionButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
	for (int i = 0; i < 2; i++)
		delete speed[i];
}