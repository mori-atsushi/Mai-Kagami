#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font) {
	button[0] = new Button(font, "UP", 1, 0);
	button[1] = new Button(font, "DOWN", 2, 1);
	button[2] = new Button(font, "スタート!", 0, 2);
	button[3] = new Button(font, "戻る", 3, 4);
	speed[0] = new MyDrawText(font, "スピード", WIDTH * 0.72, HEIGHT * 0.5165, 0, 30);
	speed[1] = new MyDrawText(font, "×1.0", WIDTH * 0.86, HEIGHT * 0.5165, 0, 30, "Yellow");
}


//モード選択ボタン表示
void ThroughOptionButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->Draw();
	for (int i = 0; i < 2; i++)
		speed[i]->Draw();
}

//モード選択削除
ThroughOptionButton::~ThroughOptionButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
	for (int i = 0; i < 2; i++)
		delete speed[i];
}