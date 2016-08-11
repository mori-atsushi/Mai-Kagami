#include "SeetingPop.h"

//ポップアップ用四角形（黒色半透明全画面）
BlackBox::BlackBox()
	: MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black") {}

void BlackBox::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //透明度設定
	MyDrawBox::View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
}

SpeedOption::SpeedOption(Font *font, Songs *songs) {
	button[0] = new TriangleButton(font, "UP", 0, 0);
	button[1] = new TriangleButton(font, "DOWN", 1, 1);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "スピード", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "×1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
	SpeedOption::songs = songs;
}

void SpeedOption::Check(Touch *touch) {
	Song *song = songs->GetSong(songs->GetNowSong());
	if (touch->Get(0) == 1)
		song->ChangeSpeed(1);
	if (touch->Get(1) == 1)
		song->ChangeSpeed(-1);
	char str[256];
	sprintf_s(str, sizeof(str), "×%1.1lf", song->danceMovie->GetSpeed());
	speed[1]->ChangeText(str);
}

void SpeedOption::View() {
	for (int i = 0; i < 2; i++) {
		button[i]->View();
		speed[i]->View();
	}
}

SpeedOption::~SpeedOption() {
	for (int i = 0; i < 2; i++) {
		delete button[i];
		delete speed[i];
	}
}

//スピードオプションポップアップ
SpeedPop::SpeedPop(Font *font, Songs *songs)
	: SpeedOption(font, songs) {
	SpeedPop::songs = songs;
	blackBox = new BlackBox();
	button = new CircleButton2(font, "決定", 4);
	text = new MyDrawText(font, "- 速度設定 -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40);
}

void SpeedPop::Check(Touch *touch) {
	Song *song = songs->GetSong(songs->GetNowSong());
	SpeedOption::Check(touch);
	if (touch->Get(4) == 1)
		song->danceMovie->SetSpeed();
}

void SpeedPop::View() {
	blackBox->View();
	SpeedOption::View();
	button->View();
	text->View();
}

SpeedPop::~SpeedPop() {
	delete blackBox;
	delete button;
	delete text;
}