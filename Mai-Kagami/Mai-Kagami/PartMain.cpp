#include "PartMain.h"

PartMain::PartMain(Font *font, Touch *touch, Songs *songs) {

}

void PartMain::ContentLoad() {
}

MainScene PartMain::Switch(const MainScene scene) {
	return scene;
}

void PartMain::ContentUpdate() {
	if (nowScene == PART) {
		Load();
	}
}

void PartMain::ContentView() {
}

void PartMain::ContentDelete() {
}

PartMain::~PartMain() {
}