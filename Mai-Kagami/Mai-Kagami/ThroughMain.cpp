#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs) {
	ThroughMain::songs = songs;
	throughStart = new ThroughStart(font);
	throughPlay = new ThroughPlay(font, songs, touch);
	throughPause = new ThroughPause(font, songs);
	throughResult = new ThroughResult(font);
	throughDetail = new ThroughDetail(font);
	scene = THROUGH_START;
	ThroughMain::touch = touch;
}

void ThroughMain::ContentLoad() {
	song = songs->GetSong(songs->GetNowSong());
	throughStart->Load();
	throughPlay->Load();
	throughPause->Load();
	throughResult->Load(song);
}

int ThroughMain::Switch(const int scene) {
	switch (this->scene)
	{
	case THROUGH_RESULT:
		if (touch->Get(4) == 1)
			this->scene = THROUGH_DETAIL;
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
	case THROUGH_SETTING:
		throughPause->Check(touch);
		break;
	}
	this->scene = throughPlay->Switch(this->scene);
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
		if (scene == THROUGH_RESULT)
			throughResult->Update();
	}
}

void ThroughMain::ContentView() {
	switch (scene)
	{
	case THROUGH_START:
		throughPause->View();
		break;
	case THROUGH_PLAY:
	case THROUGH_PAUSE:
	case THROUGH_SETTING:
		throughPlay->View();
		throughPause->View();
		break;
	case THROUGH_RESULT:
		throughResult->View();
		break;
	case THROUGH_DETAIL:
	case THROUGH_FINISH:
		throughDetail->View();
		break;
	}
	throughPlay->View();
	throughStart->View();
}

void ThroughMain::ContentDelete() {
	scene = THROUGH_START;
}

ThroughMain::~ThroughMain() {

}