#include "PauseScreen.h"

PauseScreen::PauseScreen(DecorationItem *decorationItem, Songs *songs, Touch *touch, const int pauseScene, const int startScene, const int songSelectScene, const int settingScene) {
	this->decorationItem = decorationItem;
	this->songs = songs;
	this->pauseScene = pauseScene;
	this->startScene = startScene;
	this->songSelectScene = songSelectScene;
	this->settingScene = settingScene;
	blackBox = new BlackBox();
	title = new MyDrawText(decorationItem, "- ポーズ -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40, "Yellow");
	button[0] = new CircleGraphTextButton(decorationItem, touch, "戻る", 0, "img/play.png");
	button[1] = new CircleGraphTextButton(decorationItem, touch, "はじめから", 1, "img/rewind.png");
	button[2] = new CircleGraphTextButton(decorationItem, touch, "曲選択へ", 2, "img/back.png");
	button[3] = new CircleGraphTextButton(decorationItem, touch, "設定変更", 3, "img/setting.png");
}

void PauseScreen::Load() {
	for (int i = 0; i < 4; i++)
		button[i]->Load();
}

int PauseScreen::Switch(const int scene) {
	Song *song = songs->GetSong(songs->GetNowSong());
	//戻るボタン
	if (button[0]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return startScene;
	}
	//頭出しボタン
	if (button[1]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		song->danceMovie->Seek();
		return startScene;
	}
	//曲選択へ戻るボタン
	if (button[2]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return songSelectScene;
	}
	//設定ボタン
	if (button[3]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return settingScene;
	}
	return scene;
}

void PauseScreen::ContentUpdate() {
	if (nowScene == pauseScene)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void PauseScreen::ContentView() {
	blackBox->View();
	title->View();
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

void PauseScreen::Delete() {
	for (int i = 0; i < 4; i++)
		button[i]->Release();
}

PauseScreen::~PauseScreen() {
	delete blackBox;
	delete title;
	for (int i = 0; i < 4; i++)
		delete button[i];
}