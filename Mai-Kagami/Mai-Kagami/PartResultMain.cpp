#include "PartResultMain.h"

PartResultMain::PartResultMain(Font *font, Touch *touch, Songs *songs) {

}

void PartResultMain::ContentLoad() {
	scene = PART_RESULT_TOP;
}

MainScene PartResultMain::Switch(const MainScene scene) {
	return PART_RESULT;
}

void PartResultMain::ContentUpdate() {
	if (nowScene == PART_RESULT) {
		Load();
	}
}

void PartResultMain::ContentView() {

}

void PartResultMain::ContentDelete() {

}

PartResultMain::~PartResultMain() {

}