#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs) {
	ThroughMain::songs = songs;
	throughStart = new ThroughStart(font);
	throughPlay = new ThroughPlay(font);
	throughPause = new ThroughPause(font, songs);
	throughResult = new ThroughResult(font);
	throughDetail = new ThroughDetail(font);
	scene = THROUGH_START;
	ThroughMain::touch = touch;
}

void ThroughMain::ContentLoad() {
	song = songs->GetSong(songs->GetNowSong());
	throughPlay->Load(song);
	throughPause->Load();
	throughResult->Load(song);
}

int ThroughMain::Switch(const int scene) {
	switch (this->scene)
	{
	case THROUGH_PAUSE:
		if (touch->Get(0) == 1)
			this->scene = THROUGH_START;
		if (touch->Get(1) == 1) {
			this->scene = THROUGH_START;
			song->danceMovie->Seek();
		}
		if (touch->Get(2) == 1) {
			Delete();
			return SONG_SELECT;
		}
		if (touch->Get(3) == 1) {
			this->scene = THROUGH_SETTING;
		}
		break;
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
		if (touch->Get(4) == 1)
			this->scene = THROUGH_PAUSE;
		throughPause->Check(touch);
		break;
	default:
		KinectDistance kinectDistance;
		if (kinectDistance.CheckDistance() == TRUE)
			this->scene = THROUGH_PLAY;
		else
			this->scene = THROUGH_START;
		if (touch->Get(0) == 1)
			this->scene = THROUGH_PAUSE;
		if (song->danceMovie->GetNowFlame() == 100)
			this->scene = THROUGH_RESULT;
	}
	return THROUGH;
}

void ThroughMain::ContentUpdate() {
	if (nowScene == THROUGH) {
		Load();
		throughPlay->Update(scene);
		throughStart->Update(scene);
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
		throughPlay->View();
		throughStart->View();
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
}

void ThroughMain::ContentDelete() {
	scene = THROUGH_START;
}

ThroughMain::~ThroughMain() {

}