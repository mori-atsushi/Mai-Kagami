#include "PartMain.h"

PartMain::PartMain(Font *font, Touch *touch, Songs *songs) {
	partStart = new PartStart(font);
}

void PartMain::ContentLoad() {
	scene = PART_START;
	partStart->Load();
}

MainScene PartMain::Switch(const MainScene scene) {
	return PART;
}

void PartMain::ContentUpdate() {
	if (nowScene == PART) {
		Load();
		partStart->Update(scene);
	}
}

void PartMain::ContentView() {
	partStart->View();
}

void PartMain::ContentDelete() {
	partStart->Delete();
}

PartMain::~PartMain() {
	delete partStart;
}