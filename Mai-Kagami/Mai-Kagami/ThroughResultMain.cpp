#include "ThroughResultMain.h"

ThroughResultMain::ThroughResultMain(Font *font, Touch *touch, Songs *songs) {
	throughResult = new ThroughResult(font, songs, touch);
	throughDetail = new ThroughDetail(font, touch);
}

void ThroughResultMain::ContentLoad() {
	scene = THROUGH_RESULT_TOP;
	throughResult->Load();
	throughDetail->Load();
}

MainScene ThroughResultMain::Switch(const MainScene scene) {
	switch (this->scene)
	{
	case THROUGH_RESULT_TOP:
		this->scene = throughResult->Switch(this->scene);
		break;
	case THROUGH_RESULT_DETAIL:
	case THROUGH_RESULT_FINISH:
		this->scene = throughDetail->Switch(this->scene);
		break;
	}
	if (this->scene == THROUGH_BACK_TOP) {
		Delete();
		return TOP;
	}
	if (this->scene == THROUGH_RESULT_BACK_SONG_SELECT) {
		Delete();
		return SONG_SELECT;
	}
	return THROUGH_RESULT;
}

void ThroughResultMain::ContentUpdate() {
	if (nowScene == THROUGH_RESULT) {
		Load();
		throughResult->Update(scene);
		throughDetail->Update(scene);
	}
}

void ThroughResultMain::ContentView() {
	throughResult->View();
	throughDetail->View();
}

void ThroughResultMain::ContentDelete() {
	throughResult->Delete();
	throughDetail->Delete();
}

ThroughResultMain::~ThroughResultMain() {
	delete throughResult;
	delete throughDetail;
}