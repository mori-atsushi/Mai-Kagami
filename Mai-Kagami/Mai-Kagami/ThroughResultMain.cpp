#include "ThroughResultMain.h"

ThroughResultMain::ThroughResultMain(DecorationItem *decorationItem, Touch *touch, Songs *songs, User *user, Kinect *kinect) {
	result = new Result(songs, user, kinect);
	this->decorationItem = decorationItem;
	throughResult = new ThroughResult(decorationItem, songs, touch, result);
	throughDetail = new ThroughDetail(decorationItem, songs, touch, result);
}

void ThroughResultMain::Load() {
	if (loadFlag == 3)
		return;

	if (loadFlag == 0) {
		loadFlag = -1;
		auto thd = std::thread(&ThroughResultMain::MarkThread, this);
		thd.detach();
	}

	if (loadFlag == 1) {
		ContentLoad();
		loadFlag = 2;
	}

	if (loadFlag == 2 && GetASyncLoadNum() == 0) {
		viewFlag = TRUE;
		loadFlag = 3;
	}
};

void ThroughResultMain::MarkThread() {
	result->Calc();
	loadFlag = 1;
}

void ThroughResultMain::ContentLoad() {
	scene = THROUGH_RESULT_TOP;
	if(KINECT_FLAG)
		result->Send(); //‘—M
	bgmHandle = LoadSoundMem("SE/bgm.wav");
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

	if (this->scene == THROUGH_RESULT_BACK_PLAY) {
		Delete();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return THROUGH;
	}
	if (this->scene == THROUGH_RESULT_BACK_SONG_SELECT) {
		Delete();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return SONG_SELECT;
	}
	if (this->scene == THROUGH_RESULT_BACK_PART_OPTION) {
		Delete();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return PART_OPTION;
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
	if (CheckSoundMem(bgmHandle) == 0)
		PlaySoundMem(bgmHandle, DX_PLAYTYPE_BACK);
	throughResult->View();
	throughDetail->View();
}

void ThroughResultMain::ContentDelete() {
	DeleteSoundMem(bgmHandle);
	throughResult->Delete();
	throughDetail->Delete();
}

ThroughResultMain::~ThroughResultMain() {
	delete throughResult;
	delete throughDetail;
	delete result;
}