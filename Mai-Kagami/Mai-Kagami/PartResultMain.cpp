#include "PartResultMain.h"

PartResultMain::PartResultMain(Font *font, Touch *touch, Songs *songs) {
	partResult = new PartResult(font, songs, touch);
}

void PartResultMain::ContentLoad() {
	scene = PART_RESULT_TOP;
	partResult->Load();
}

MainScene PartResultMain::Switch(const MainScene scene) {
	switch (this->scene)
	{
	case PART_RESULT_TOP:
		this->scene = partResult->Switch(this->scene);
		break;
	}
	return PART_RESULT;
}

void PartResultMain::ContentUpdate() {
	if (nowScene == PART_RESULT) {
		Load();
		partResult->Update(scene);
	}
}

void PartResultMain::ContentView() {
	partResult->View();
}

void PartResultMain::ContentDelete() {
	partResult->Delete();
}

PartResultMain::~PartResultMain() {
	delete partResult;
}