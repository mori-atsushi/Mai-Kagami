#include "PartPause.h"

PartPauseButton::PartPauseButton(Touch *touch) {
	pauseButton = new CircleGraphButton(touch, 0, "img/pause.png");
}

void PartPauseButton::Load() {
	pauseButton->Load();
}

int PartPauseButton::Switch(const int scene) {
	if (pauseButton->GetTouch() == 1)
		return PART_PAUSE;
	return scene;
}

void PartPauseButton::ContentUpdate() {
	switch (nowScene)
	{
	case PART_PLAY:
	case PART_COUNTDOWN:
	case PART_START:
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void PartPauseButton::ContentView() {
	pauseButton->View();
}

void PartPauseButton::Delete() {
	pauseButton->Release();
}

PartPauseButton::~PartPauseButton() {
	delete pauseButton;
}

PartPauseScreen::PartPauseScreen(Font *font, Songs *songs, Touch *touch)
	: PauseScreen(font, songs, touch, PART_PAUSE, PART_START, PART_BACK_SONG_SELECT, PART_SETTING) {}

PartPause::PartPause(Font *font, Songs *songs, Touch *touch) {
	partPauseButton = new PartPauseButton(touch); //ポーズボタン画面
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