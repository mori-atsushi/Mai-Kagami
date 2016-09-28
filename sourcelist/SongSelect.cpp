#include "SongSelect.h"

// �ȑI����ʃ{�^��������
SongSelectButton::SongSelectButton(Font *font, Touch *touch) {
	button[0] = new TriangleButton(font, touch, "�O�̋Ȃ�", 0, 0);
	button[1] = new CircleButton(font, touch, "����", 1);
	button[2] = new TriangleButton(font, touch, "���̋Ȃ�", 1, 2);
	button[3] = new CircleButton2(font, touch, "�I��", 4);
}

// �ȑI����ʃ{�^����ʐ؂�ւ�
int SongSelectButton::Switch(const int scene) {
	if (button[1]->GetTouch() == 1)
		return MODE;
	if (button[3]->GetTouch() == 1)
		return BACK;
	return scene;
}

// �ȑI����ʃ{�^���v�Z
void SongSelectButton::ContentUpdate() {
	if (nowScene == MAIN)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

// �ȑI����ʃ{�^���\��
void SongSelectButton::ContentView() {
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

SongSelectButton::~SongSelectButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
}

// �I���p�|�b�v�A�b�v
SongSelectPop::SongSelectPop(Font *font, Touch *touch) {
	this->touch = touch;
	blackBox = new BlackBox();
	title = new MyDrawText(font, "- �I�� -", WIDTH * 0.75, HEIGHT * 0.4, 1, 40, "Blue");
	message = new MyDrawText(font, "�{���ɏI��\n���܂����H", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	button[0] = new CircleButton(font, touch, "�͂�", 1, WIDTH * 0.75, "White");
	button[1] = new CircleButton(font, touch, "������", 2, WIDTH * 0.75, "White");
}

int SongSelectPop::Switch(const int scene) {
	if (touch->Get(1) == 1)
		return BACK_TOP;
	if (touch->Get(2) == 1)
		return MAIN;
	return scene;
}

void SongSelectPop::ContentUpdate() {
	if (nowScene == BACK)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void SongSelectPop::ContentView() {
	blackBox->View();
	title->View();
	message->View();
	for (int i = 0; i < 2; i++)
		button[i]->View();
}

SongSelectPop::~SongSelectPop() {
	delete blackBox;
	delete title;
	delete message;
	for (int i = 0; i < 2; i++)
		delete button[i];
}