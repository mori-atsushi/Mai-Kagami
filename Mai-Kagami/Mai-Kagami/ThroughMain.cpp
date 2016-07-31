#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Songs *songs) {
	f = font;
	loadFlag = 0;
	throughStart = new ThroughStart(f);
}

void ThroughMain::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

int ThroughMain::Update() {
	Load();
	if (loadFlag == 2) {
	}
	return THROUGH;
}

void ThroughMain::View() {
	if (loadFlag == 2) {
		throughStart->View();
	}
}

void ThroughMain::Delete() {
	loadFlag = 0;
}

ThroughMain::~ThroughMain() {

}