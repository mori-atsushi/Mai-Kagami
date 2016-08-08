#include "ThroughPause.h"

ThroughPause::ThroughPause(Font *font) {
	pauseButton = new CircleGraphButton(0, "img/pause.png");
}

void ThroughPause::Update(int scne) {

}

void ThroughPause::Load() {
	pauseButton->Load();
}

void ThroughPause::View() {
	pauseButton->View();
}

ThroughPause::~ThroughPause() {
	delete pauseButton;
}