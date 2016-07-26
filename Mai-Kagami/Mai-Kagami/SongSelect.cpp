#include "SongSelect.h"

//曲選択画面ボタン初期化
SongSelectButton::SongSelectButton(Font *font) {
	button[0] = new Button(font, "前の曲へ", 1, 0);
	button[1] = new Button(font, "決定", 0, 1);
	button[2] = new Button(font, "次の曲へ", 2, 2);
	button[3] = new Button(font, "終了", 3, 4);
}

//曲選択画面ボタン表示
void SongSelectButton::View() {
	for (int i = 0; i < 4; i++)
		button[i]->Draw();
}

SongSelectButton::~SongSelectButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}

SongSelectPop::SongSelectPop(Font *font) {
	myDrawBox = new MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black");
	title = new MyDrawText(font, "- 終了 -", WIDTH * 0.75, HEIGHT * 0.4, 1, 40, "Blue");
	message = new MyDrawText(font, "本当に終了\nしますか？", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	button[0] = new Button(font, "はい", 4, 1);
	button[1] = new Button(font, "いいえ", 4, 2);
}

void SongSelectPop::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //透明度設定
	myDrawBox->Draw();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
	title->Draw();
	message->Draw();
	for (int i = 0; i < 2; i++)
		button[i]->Draw();
}

SongSelectPop::~SongSelectPop() {
	delete myDrawBox;
	delete title;
	delete message;
	for (int i = 0; i < 2; i++)
		delete button[i];
}