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
		switch (scene)
		{
		case THROUGH_START:
			if (touch->Get(0) == 1)
				scene = THROUGH_PLAY;
			break;
		case THROUGH_PLAY:
			throughPlay->Update();
		}
	}
	return THROUGH;
}

void ThroughMain::View() {
	if (loadFlag == 2) {
		switch (scene)
		{
		case THROUGH_START:
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