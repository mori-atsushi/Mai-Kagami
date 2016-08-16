#include "ThroughPause.h"

ThroughPauseButton::ThroughPauseButton(Touch *touch) {
	pauseButton = new CircleGraphButton(touch, 0, "img/pause.png");
}

void ThroughPauseButton::Load() {
	pauseButton->Load();
}

ThroughScene ThroughPauseButton::Switch(const ThroughScene scene) {
	if (pauseButton->GetTouch() == 1)
		return THROUGH_PAUSE;
	return scene;
}

void ThroughPauseButton::ContentUpdate() {
	switch (nowScene)
	{
	case THROUGH_PLAY:
	case THROUGH_COUNTDOWN:
	case THROUGH_START:
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void ThroughPauseButton::ContentView() {
	pauseButton->View();
}

void ThroughPauseButton::Delete() {
	pauseButton->Release();
}

ThroughPauseButton::~ThroughPauseButton() {
	delete pauseButton;
}

ThroughPauseScreen::ThroughPauseScreen(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	blackBox = new BlackBox();
	title = new MyDrawText(font, "- ポーズ -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40, "Yellow");
	button[0] = new CircleGraphTextButton(font, touch, "戻る", 0, "img/play.png");
	button[1] = new CircleGraphTextButton(font, touch, "はじめから", 1, "img/rewind.png");
	button[2] = new CircleGraphTextButton(font, touch, "曲選択へ", 2, "img/back.png");
	button[3] = new CircleGraphTextButton(font, touch, "設定変更", 3, "img/setting.png");
}

void ThroughPauseScreen::Load() {
	for (int i = 0; i < 4; i++)
		button[i]->Load();
}

ThroughScene ThroughPauseScreen::Switch(const ThroughScene scene) {
	Song *song = songs->GetSong(songs->GetNowSong());
	if (button[0]->GetTouch() == 1)
		return THROUGH_START;
	if (button[1]->GetTouch() == 1) {
		song->danceMovie->Seek();
		return THROUGH_START;
	}
	if (button[2]->GetTouch() == 1)
		return THROUGH_BACK_SONG_SELECT;
	if (button[3]->GetTouch() == 1)
		return THROUGH_SETTING;
	return scene;
}

void ThroughPauseScreen::ContentUpdate() {
	if (nowScene == THROUGH_PAUSE)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughPauseScreen::ContentView() {
	blackBox->View();
	title->View();
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

void ThroughPauseScreen::Delete() {
	for (int i = 0; i < 4; i++)
		button[i]->Release();
}

ThroughPauseScreen::~ThroughPauseScreen() {
	delete blackBox;
	delete title;
	for (int i = 0; i < 4; i++)
		delete button[i];
}

ThroughScene ThroughPauseSetting::Switch(const ThroughScene scene) {
	if (button->GetTouch() == 1) {
		song->danceMovie->SetSpeed();
		return THROUGH_PAUSE;
	}
	return scene;
}

void ThroughPauseSetting::ContentUpdate() {
	if (nowScene == THROUGH_SETTING) {
		SpeedPop::ContentUpdate();
		viewFlag = TRUE;
	}
	else {
		viewFlag = FALSE;
	}
}

ThroughPause::ThroughPause(Font *font, Songs *songs, Touch *touch) {
	throughPauseButton = new ThroughPauseButton(touch); //ポーズボタン画面
	throughPauseScreen = new ThroughPauseScreen(font, songs, touch);
	throughPauseSetting = new ThroughPauseSetting(font, songs, touch);
	flag = FALSE;
}

void ThroughPause::Load() {
	throughPauseButton->Load();
	throughPauseScreen->Load();
	throughPauseSetting->Load();
}

ThroughScene ThroughPause::Switch(const ThroughScene scene) {
	switch (scene)
	{
	case THROUGH_COUNTDOWN:
	case THROUGH_PLAY:
	case THROUGH_START:
		return throughPauseButton->Switch(scene);
	case THROUGH_PAUSE:
		return throughPauseScreen->Switch(scene);
	case THROUGH_SETTING:
		return throughPauseSetting->Switch(scene);
	}
	return scene;
}

void ThroughPause::ContentUpdate() {
	throughPauseButton->Update(nowScene);
	throughPauseScreen->Update(nowScene);
	throughPauseSetting->Update(nowScene);

	switch (nowScene)
	{
	case THROUGH_SETTING:
	case THROUGH_PLAY:
	case THROUGH_PAUSE:
	case THROUGH_COUNTDOWN:
	case THROUGH_START:
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void ThroughPause::ContentView() {
	throughPauseButton->View();
	throughPauseScreen->View();
	throughPauseSetting->View();
}

void ThroughPause::Delete() {
	throughPauseButton->Delete();
	throughPauseScreen->Delete();
	throughPauseSetting->Delete();
}

ThroughPause::~ThroughPause() {
	delete throughPauseButton;
	delete throughPauseScreen;
	delete throughPauseSetting;
}