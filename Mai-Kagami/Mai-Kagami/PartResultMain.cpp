#include "PartResultMain.h"

PartResultMain::PartResultMain(DecorationItem *decorationItem, Touch *touch, Songs *songs) {
	this->decorationItem = decorationItem;
	partResult = new PartResult(decorationItem, songs, touch);
	partFinish = new PartFinish(decorationItem, touch);
}

void PartResultMain::ContentLoad() {
	scene = PART_RESULT_TOP;
	partResult->Load();
	partFinish->Load();
}

MainScene PartResultMain::Switch(const MainScene scene) {
	switch (this->scene)
	{
	case PART_RESULT_TOP:
		this->scene = partResult->Switch(this->scene);
		break;
	case PART_RESULT_FINISH:
		this->scene = partFinish->Switch(this->scene);
		break;
	}
	if (this->scene == PART_RESULT_BACK_PLAY) {
		Delete();
		printfDx("0");
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return PART;
	}
	if (this->scene == PART_RESULT_BACK_SONG_SELECT) {
		Delete();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return SONG_SELECT;
	}
	if (this->scene == PART_RESULT_BACK_THROUGH_OPTION) {
		Delete();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return THROUGH_OPTION;
	}
	if (this->scene == PART_RESULT_BACK_PART_OPTION) {
		Delete();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_DECIDE);
		return PART_OPTION;
	}
	return PART_RESULT;
}

void PartResultMain::ContentUpdate() {
	if (nowScene == PART_RESULT) {
		Load();
		partResult->Update(scene);
		partFinish->Update(scene);
	}
}

void PartResultMain::ContentView() {
	partResult->View();
	partFinish->View();
}

void PartResultMain::ContentDelete() {
	partResult->Delete();
	partFinish->Delete();
}

PartResultMain::~PartResultMain() {
	delete partResult;
	delete partFinish;
}