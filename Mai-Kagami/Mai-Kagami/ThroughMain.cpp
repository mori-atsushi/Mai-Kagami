#include "ThroughMain.h"

ThroughMain::ThroughMain(Font *font, Songs *songs) {
	f = font;
	loadFlag = 0;
	myDrawText = new MyDrawText(f, "’Ê‚µ—ûKƒ‚[ƒh", WIDTH / 2, HEIGHT / 2, 1, 40);
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
		myDrawText->View();
	}
}

void ThroughMain::Delete() {
	loadFlag = 0;
}

ThroughMain::~ThroughMain() {

}