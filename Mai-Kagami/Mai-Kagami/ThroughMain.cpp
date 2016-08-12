#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs) {
	ThroughMain::songs = songs;
	loadFlag = 0;
	throughStart = new ThroughStart(font);
	throughPlay = new ThroughPlay(font);
	throughPause = new ThroughPause(font, songs);
	throughResult = new ThroughResult(font);
	throughDetail = new ThroughDetail(font);
	scene = THROUGH_START;
	ThroughMain::touch = touch;
}

void ThroughMain::Load() {
	song = songs->GetSong(songs->GetNowSong());
	if (loadFlag == 2)
		return;

	if (loadFlag == 0 && GetASyncLoadNum() == 0) {
		throughPlay->Load(song);
		throughPause->Load();
		throughResult->Load(song);
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

int ThroughMain::Update() {
	Load();

	if (loadFlag == 2) {
		switch (scene)
		{
		case THROUGH_PAUSE:
			if (touch->Get(0) == 1)
				scene = THROUGH_START;
			if (touch->Get(1) == 1) {
				scene = THROUGH_START;
				song->danceMovie->Seek();
			}
			if (touch->Get(2) == 1) {
				Delete();
				scene = THROUGH_START;
				return SONG_SELECT;
			}
			if (touch->Get(3) == 1) {
				scene = THROUGH_SETTING;
			}
			break;
		case THROUGH_RESULT:
			if (touch->Get(4) == 1)
				scene = THROUGH_DETAIL;
			break;
		case THROUGH_DETAIL:
			if (touch->Get(4) == 1)
				scene = THROUGH_FINISH;
			break;
		case THROUGH_FINISH:
			break;
		case THROUGH_SETTING:
			if (touch->Get(4) == 1) 
				scene = THROUGH_PAUSE;
			throughPause->Check(touch);
			break;
		default:
			KinectDistance kinectDistance;
			if (kinectDistance.CheckDistance() == TRUE)
				scene = THROUGH_PLAY;
			else
				scene = THROUGH_START;
			if (touch->Get(0) == 1)
				scene = THROUGH_PAUSE;
			if (song->danceMovie->GetNowFlame() == 100)
				scene = THROUGH_RESULT;
		}
		throughPlay->Update(scene);
		throughStart->Update(scene);
		throughPause->Update(scene);
		throughDetail->Update(scene);
		if(scene == THROUGH_RESULT)
			throughResult->Update();
	}
	return THROUGH;
}

void ThroughMain::View() {
	if (loadFlag == 2) {
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
}

void ThroughMain::Delete() {
	loadFlag = 0;
}

ThroughMain::~ThroughMain() {

}