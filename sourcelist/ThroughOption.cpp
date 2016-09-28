#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	speedOption = new SpeedOption(font, songs, touch);
	button[0] = new CircleButton(font, touch, "�X�^�[�g!", 2);
	button[1] = new CircleButton2(font, touch, "�߂�", 4);
}

int ThroughOptionButton::Switch(const int scene) {
	if (button[0]->GetTouch() == 1)
		return NEXT1;
	if (button[1]->GetTouch() == 1)
		return MODE;
	return scene;
}

// ���[�h�I���{�^���v�Z
void ThroughOptionButton::ContentUpdate() {
	static int lastScene = TOP;
	if (nowScene == OPTION1) {
		viewFlag = TRUE;
		Song *song = songs->GetSong(songs->GetNowSong());
		song->danceMovie->SetStartFlame();
		song->danceMovie->SetEndFlame();
		if (lastScene == nowScene) {
			speedOption->Check();
		}
	}
	else {
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

// �I�v�V������ʃ{�^���\��
void ThroughOptionButton::ContentView() {
	speedOption->View();
	for(int i = 0; i < 2; i++)
		button[i]->View();
}

// �I�v�V������ʃ{�^���폜
ThroughOptionButton::~ThroughOptionButton() {
	for(int i = 0; i < 2; i++)
		delete button[i];
	delete speedOption;
}