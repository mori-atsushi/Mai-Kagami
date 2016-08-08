#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs) {
	f = font;
	ThroughMain::songs = songs;
	loadFlag = 0;
	throughStart = new ThroughStart(f);
	throughPlay = new ThroughPlay(f);
	scene = THROUGH_START;
	ThroughMain::touch = touch;
}

void ThroughMain::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0 && GetASyncLoadNum() == 0) {
		throughPlay->Load(songs->GetSong(songs->GetNowSong()));
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

int ThroughMain::Update() {
	Load();

	if (loadFlag == 2) {
		KinectDistance kinectDistance;
		if (kinectDistance.CheckDistance() == TRUE)
			scene = THROUGH_PLAY;
		else
			scene = THROUGH_START;
		throughPlay->Update(scene);
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
			break;
		case THROUGH_PLAY:
			throughPlay->View();
			break;
		}
	}
}

void ThroughMain::Delete() {
	loadFlag = 0;
}

ThroughMain::~ThroughMain() {

}