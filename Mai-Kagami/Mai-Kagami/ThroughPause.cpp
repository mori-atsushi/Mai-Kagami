#include "ThroughPause.h"

ThroughPause::ThroughPause(Font *font) {
	pauseButton = new CircleGraphButton(0, "img/pause.png");
	blackBox = new BlackBox();
	flag = FALSE;
}

void ThroughPause::Update(int scene) {
	if (scene == THROUGH_PAUSE)
		flag = TRUE;
	else
		flag = FALSE;
}

void ThroughPause::Load() {
	pauseButton->Load();
}

void ThroughPause::View() {
	if (flag) {
		blackBox->View();
	}
	else {
		pauseButton->View();
	}
}

ThroughPause::~ThroughPause() {
	delete pauseButton;
	delete blackBox;
}