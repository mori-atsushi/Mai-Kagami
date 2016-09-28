#include "SeetingPop.h"

// �|�b�v�A�b�v�p�l�p�`�i���F�������S��ʁj
BlackBox::BlackBox()
	: MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black") {
	MyDrawBox::SetAlpha(220);
}

// �X�s�[�h�I�v�V�����\��
SpeedOption::SpeedOption(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	button[0] = new TriangleButton(font, touch, "UP", 0, 0);
	button[1] = new TriangleButton(font, touch, "DOWN", 1, 1);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "�X�s�[�h", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "�~1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
}

void SpeedOption::Check() {
	Song *song = songs->GetSong(songs->GetNowSong());
	if (button[0]->GetTouch() == 1)
		song->ChangeSpeed(1);
	if (button[1]->GetTouch() == 1)
		song->ChangeSpeed(-1);
	char str[256];
	sprintf_s(str, sizeof(str), "�~%1.1lf", song->danceMovie->GetSpeed());
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

// ��Ԑݒ�I�v�V�����\��
PartOption::PartOption(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	button[0] = new TriangleButton(font, touch, "", 0, 0);
	button[1] = new TriangleButton(font, touch, "", 1, 1);
	button[2] = new TriangleButton(font, touch, "", 0, 2);
	button[3] = new TriangleButton(font, touch, "", 1, 3);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	part[0] = new MyDrawText(font, "�n�߁F", WIDTH * 0.67, height, 0, 30);
	part[1] = new MyDrawText(font, "", WIDTH * 0.79, height, 0, 30, "Yellow");
	part[2] = new MyDrawText(font, "�I���F", WIDTH * 0.67, height + BUTTON_INTERVAL * 2, 0, 30);
	part[3] = new MyDrawText(font, "", WIDTH * 0.79, height + BUTTON_INTERVAL * 2, 0, 30, "Yellow");
}

void PartOption::Init() {
	song = songs->GetSong(songs->GetNowSong());
	part[1]->ChangeText(song->GetPart(song->StartPart())->GetName());
	part[3]->ChangeText(song->GetPart(song->EndPart())->GetName());
}

void PartOption::Check() {
	song = songs->GetSong(songs->GetNowSong());
	if (button[0]->GetTouch() == 1)
		song->ChangeStart(1);
	if (button[1]->GetTouch() == 1)
		song->ChangeStart(-1);
	if (button[2]->GetTouch() == 1)
		song->ChangeEnd(1);
	if (button[3]->GetTouch() == 1)
		song->ChangeEnd(-1);
	part[1]->ChangeText(song->GetPart(song->StartPart())->GetName());
	part[3]->ChangeText(song->GetPart(song->EndPart())->GetName());
}

void PartOption::View() {
	for (int i = 0; i < 4; i++) {
		button[i]->View();
		part[i]->View();
	}
}

PartOption::~PartOption() {
	for (int i = 0; i < 4; i++) {
		delete button[i];
		delete part[i];
	}
}

// �X�s�[�h�I�v�V�����|�b�v�A�b�v
SpeedPop::SpeedPop(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	speedOption = new SpeedOption(font, songs, touch);
	blackBox = new BlackBox();
	button = new CircleButton2(font, touch, "����", 4);
	text = new MyDrawText(font, "- ���x�ݒ� -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40);
}

void SpeedPop::Load() {
	song = songs->GetSong(songs->GetNowSong());
}

void SpeedPop::ContentUpdate() {
	speedOption->Check();
}

void SpeedPop::ContentView() {
	blackBox->View();
	speedOption->View();
	button->View();
	text->View();
}

SpeedPop::~SpeedPop() {
	delete speedOption;
	delete blackBox;
	delete button;
	delete text;
}

// ��Ԑݒ�I�v�V�����|�b�v�A�b�v
PartPop::PartPop(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	blackBox = new BlackBox();
	partOption = new PartOption(font, songs, touch);
	button = new CircleButton2(font, touch, "����", 4);
	text = new MyDrawText(font, "- ��Ԑݒ� -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40);
}

void PartPop::Load() {
	song = songs->GetSong(songs->GetNowSong());
}

void PartPop::ContentUpdate() {
	partOption->Check();
}

void PartPop::ContentView() {
	blackBox->View();
	partOption->View();
	button->View();
	text->View();
}

void PartPop::Init() {
	partOption->Init();
}

PartPop::~PartPop() {
	delete partOption;
	delete blackBox;
	delete button;
	delete text;
}