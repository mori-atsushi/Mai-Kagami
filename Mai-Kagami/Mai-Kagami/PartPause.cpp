#include "PartPause.h"

PartPauseButton::PartPauseButton(Touch *touch, Songs *songs) {
	this->songs = songs;
	button[0] = new CircleGraphButton(touch, 0, "img/pause.png");
	button[1] = new CircleGraphButton(touch, 2, "img/pause.png");
}

void PartPauseButton::Load() {
	for(int i = 0; i < 2; i++)
		button[i]->Load();
}

int PartPauseButton::Switch(const int scene) {
	static int lastScene = PART_START;
	if (button[0]->GetTouch() == 1)
		return PART_PAUSE;
	if (button[1]->GetTouch() > 0)
		return PART_REWIND;
	if (scene == PART_REWIND)
		return lastScene;
	lastScene = scene;
	return scene;
}

void PartPauseButton::ContentUpdate() {
	Song *song = songs->GetSong(songs->GetNowSong());
	if (button[1]->GetTouch() > 0) {
		if(song->danceMovie->GetStartFlame() <= song->danceMovie->GetNowFlame())
			song->danceMovie->Seek(song->danceMovie->GetNowFlame()-5);
	}

	switch (nowScene)
	{
	case PART_PLAY:
	case PART_COUNTDOWN:
	case PART_START:
	case PART_REWIND:
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void PartPauseButton::ContentView() {
	for (int i = 0; i < 2; i++)
		button[i]->View();
}

void PartPauseButton::Delete() {
	for (int i = 0; i < 2; i++)
		button[i]->Release();
}

PartPauseButton::~PartPauseButton() {
	for (int i = 0; i < 2; i++)
		delete button[i];
}

PartPauseScreen::PartPauseScreen(Font *font, Songs *songs, Touch *touch)
	: PauseScreen(font, songs, touch, PART_PAUSE, PART_START, PART_BACK_SONG_SELECT, PART_SETTING) {}

PartPause::PartPause(Font *font, Songs *songs, Touch *touch) {
	partPauseButton = new PartPauseButton(touch, songs); //ポーズボタン画面
	partPauseScreen = new PartPauseScreen(font, songs, touch);
	flag = FALSE;
}

void PartPause::Load() {
	partPauseButton->Load();
	partPauseScreen->Load();
}

int PartPause::Switch(const int scene) {
	switch (scene)
	{
	case PART_COUNTDOWN:
	case PART_PLAY:
	case PART_START:
	case PART_REWIND:
		return partPauseButton->Switch(scene);
	case PART_PAUSE:
		return partPauseScreen->Switch(scene);
	}
	return scene;
}

void PartPause::ContentUpdate() {
	partPauseButton->Update(nowScene);
	partPauseScreen->Update(nowScene);

	switch (nowScene)
	{
	case PART_SETTING:
	case PART_PLAY:
	case PART_PAUSE:
	case PART_COUNTDOWN:
	case PART_REWIND:
	case PART_START:
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void PartPause::ContentView() {
	partPauseButton->View();
	partPauseScreen->View();
}

void PartPause::Delete() {
	partPauseButton->Delete();
	partPauseScreen->Delete();
}

PartPause::~PartPause() {
	delete partPauseButton;
	delete partPauseScreen;
}