#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs) {
	ThroughMain::songs = songs;
	throughStart = new ThroughStart(font);
	throughPlay = new ThroughPlay(font, songs, touch);
	throughPause = new ThroughPause(font, songs, touch);
	throughResult = new ThroughResult(font, songs, touch);
	throughDetail = new ThroughDetail(font);
	scene = THROUGH_START;
	ThroughMain::touch = touch;
}

void ThroughMain::ContentLoad() {
	song = songs->GetSong(songs->GetNowSong());
	throughStart->Load();
	throughPlay->Load();
	throughPause->Load();
	throughResult->Load();
}

int ThroughMain::Switch(const int scene) {
	switch (this->scene)
	{
	case THROUGH_COUNTDOWN:
	case THROUGH_PLAY:
	case THROUGH_START:
		this->scene = throughPlay->Switch(this->scene);
	case THROUGH_PAUSE:
	case THROUGH_SETTING:
		this->scene = throughPause->Switch(this->scene);
		break;
	case THROUGH_RESULT:
		this->scene = throughResult->Switch(this->scene);
		break;
	case THROUGH_DETAIL:
		if (touch->Get(4) == 1)
			this->scene = THROUGH_FINISH;
		break;
	case THROUGH_FINISH:
		if (touch->Get(2) == 1) {
			Delete();
			return SONG_SELECT;
		}
		if (touch->Get(3) == 1) {
			Delete();
			return TOP;
		}
		break;
	}
	if (this->scene == BACK_SONG_SELECT) {
		Delete();
		return SONG_SELECT;
	}
	return THROUGH;
}

void ThroughMain::ContentUpdate() {
	if (nowScene == THROUGH) {
		Load();
		throughStart->Update(scene);
		throughPlay->Update(scene);
		throughPause->Update(scene);
		throughDetail->Update(scene);
		throughResult->Update(scene);
	}
}

void ThroughMain::ContentView() {
	switch (scene)
	{
	case THROUGH_DETAIL:
	case THROUGH_FINISH:
		throughDetail->View();
		break;
	}
	throughPlay->View();
	throughStart->View();
	throughPause->View();
	throughResult->View();
}

void ThroughMain::ContentDelete() {
	scene = THROUGH_START;
}

ThroughMain::~ThroughMain() {

}