#include "ThroughPause.h"

ThroughPause::ThroughPause(Font *font, Songs *songs, Touch *touch) {
	this->touch = touch;
	this->songs = songs;
	pauseButton = new CircleGraphButton(0, "img/pause.png");
	blackBox = new BlackBox();
	title = new MyDrawText(font, "- ポーズ -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40, "Yellow");
	button[0] = new CircleGraphTextButton(font, "戻る", 0, "img/play.png");
	button[1] = new CircleGraphTextButton(font, "はじめから", 1, "img/rewind.png");
	button[2] = new CircleGraphTextButton(font, "曲選択へ", 2, "img/back.png");
	button[3] = new CircleGraphTextButton(font, "設定変更", 3, "img/setting.png");
	speedPop = new SpeedPop(font, songs);
	flag = FALSE;
}

void ThroughPause::Load() {
	pauseButton->Load();
	for (int i = 0; i < 4; i++)
		button[i]->Load();
}

int ThroughPause::Switch(const int scene) {
	Song *song = songs->GetSong(songs->GetNowSong());
	switch (scene)
	{
	case THROUGH_COUNTDOWN:
	case THROUGH_PLAY:
	case THROUGH_START:
		if (touch->Get(0) == 1)
			return THROUGH_PAUSE;
	case THROUGH_PAUSE:
		if (touch->Get(0) == 1)
			return THROUGH_START;
		if (touch->Get(1) == 1) {
			song->danceMovie->Seek();
			return THROUGH_START;
		}
		if (touch->Get(2) == 1)
			return BACK_SONG_SELECT;
		if (touch->Get(3) == 1)
			return THROUGH_SETTING;
	case THROUGH_SETTING:
		if (touch->Get(4) == 1)
			return THROUGH_PAUSE;
	}
	return scene;
}

void ThroughPause::ContentUpdate() {
	switch (nowScene)
	{
	case THROUGH_SETTING:
		speedPop->Check(touch);
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
	switch (nowScene)
	{
	case THROUGH_PAUSE:
		blackBox->View();
		title->View();
		for (int i = 0; i < 4; i++)
			button[i]->View();
		break;
	case THROUGH_SETTING:
		speedPop->View();
		break;
	default:
		pauseButton->View();
		break;
	}
}

ThroughPause::~ThroughPause() {
	delete pauseButton;
	delete blackBox;
	delete speedPop;
}