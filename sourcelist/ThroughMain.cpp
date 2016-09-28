#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs, Kinect *kinect) {
	throughStart = new ThroughStart(font);
	throughPlay = new ThroughPlay(font, songs, touch, kinect);
	throughPause = new ThroughPause(font, songs, touch);
}

void ThroughMain::ContentLoad() {
	scene = THROUGH_START;
	throughStart->Load();
	throughPlay->Load();
	throughPause->Load();
}

MainScene ThroughMain::Switch(const MainScene scene) {
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
	}

	switch (this->scene)
	{
	case THROUGH_NEXT:
		Delete();
		return THROUGH_RESULT;
	case THROUGH_BACK_SONG_SELECT:
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
	}
}

void ThroughMain::ContentView() {
	throughPlay->View();
	throughStart->View();
	throughPause->View();
}

void ThroughMain::ContentDelete() {
	throughStart->Delete();
	throughPlay->Delete();
	throughPause->Delete();
}

ThroughMain::~ThroughMain() {
	delete throughStart;
	delete throughPlay;
	delete throughPause;
}