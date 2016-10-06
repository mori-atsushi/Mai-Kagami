#include "ThroughOption.h"

ThroughOptionButton::ThroughOptionButton(DecorationItem *decorationItem, Songs *songs, Touch *touch) {
	this->decorationItem = decorationItem;
	this->songs = songs;
	speedOption = new SpeedOption(decorationItem, songs, touch);
	button[0] = new CircleButton(decorationItem, touch, "スタート!", 2);
	button[1] = new CircleButton2(decorationItem, touch, "戻る", 4);
}

int ThroughOptionButton::Switch(const int scene) {
	if (button[0]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return NEXT1;
	}
	if (button[1]->GetTouch() == 1) {
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return MODE;
	}
	return scene;
}

//モード選択ボタン計算
void ThroughOptionButton::ContentUpdate() {
	static int lastScene = TOP;
	if (nowScene == OPTION1) {
		viewFlag = TRUE;
		Song *song = songs->GetSong(songs->GetNowSong());
		song->SetPlayMode(THROUGH_MODE);
		if (lastScene == nowScene) {
			speedOption->Check();
		}
	}
	else {
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

//オプション画面ボタン表示
void ThroughOptionButton::ContentView() {
	speedOption->View();
	for(int i = 0; i < 2; i++)
		button[i]->View();
}

//オプション画面ボタン削除
ThroughOptionButton::~ThroughOptionButton() {
	for(int i = 0; i < 2; i++)
		delete button[i];
	delete speedOption;
}