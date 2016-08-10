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
	button[2] = new CircleButton2(font, "決定", 4);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "スピード", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "×1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
	SpeedOption::songs = songs;
}

void SpeedOption::Update() {
	Song *song = songs->GetSong(songs->GetNowSong());

	char str[256];
	sprintf_s(str, sizeof(str), "×%1.1lf", song->danceMovie->GetSpeed());
	speed[1]->ChangeText(str);
}

void SpeedOption::View() {
	for (int i = 0; i < 3; i++)
		button[i]->View();
	for (int i = 0; i < 2; i++)
		speed[i]->View();
}

SpeedOption::~SpeedOption() {
	for (int i = 0; i < 3; i++)
	delete button[i];
for (int i = 0; i < 2; i++)
	delete speed[i];
}

//スピードオプションポップアップ
SpeedPop::SpeedPop(Font *font, Songs *songs)
	: SpeedOption(font, songs) {
	blackBox = new BlackBox();
}

void SpeedPop::View() {
	blackBox->View();
	SpeedOption::View();
}

void SpeedPop::Update() {
	SpeedOption::Update();
}

SpeedPop::~SpeedPop() {
	delete blackBox;
}