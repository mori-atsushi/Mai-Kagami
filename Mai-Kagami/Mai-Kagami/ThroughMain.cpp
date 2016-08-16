#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Touch *touch, Songs *songs) {
	throughStart = new ThroughStart(font);
	throughPlay = new ThroughPlay(font, songs, touch);
	throughPause = new ThroughPause(font, songs, touch);
	throughResult = new ThroughResult(font, songs, touch);
	throughDetail = new ThroughDetail(font, touch);
}

void ThroughMain::ContentLoad() {
	scene = THROUGH_START;
	throughStart->Load();
	throughPlay->Load();
	throughPause->Load();
	throughResult->Load();
	throughDetail->Load();
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
	case THROUGH_RESULT:
		this->scene = throughResult->Switch(this->scene);
		break;
	case THROUGH_DETAIL:
	case THROUGH_FINISH:
		this->scene = throughDetail->Switch(this->scene);
		break;
	}
	if (this->scene == THROUGH_BACK_TOP) {
		Delete();
		return TOP;
	}
	if (this->scene == THROUGH_BACK_SONG_SELECT) {
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
		throughResult->Update(scene);
		throughDetail->Update(scene);
	}
}

void ThroughMain::ContentView() {
	throughPlay->View();
	throughStart->View();
	throughPause->View();
	throughResult->View();
	throughDetail->View();
}

void ThroughMain::ContentDelete() {
	throughStart->Delete();
	throughPlay->Delete();
	throughPause->Delete();
	throughResult->Delete();
	throughDetail->Delete();
}

ThroughMain::~ThroughMain() {
	delete throughStart;
	delete throughPlay;
	delete throughPause;
	delete throughResult;
	delete throughDetail;
}