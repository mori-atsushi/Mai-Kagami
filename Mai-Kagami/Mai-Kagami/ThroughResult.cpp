#include "ThroughResult.h"

ThroughResult::ThroughResult(Font *font) {
	title = new MyDrawTextLine(font, "Ì“_Œ‹‰Ê", WIDTH * 0.5, HEIGHT * 0.2, 1, 60, WIDTH * 0.5, 4);
}

void ThroughResult::Load(Song *song) {
	ThroughResult::song = song;
	song->coverGraph->Load();
}

void ThroughResult::Update() {
	song->coverGraph->ChangePos(WIDTH * 0.3, HEIGHT * 0.34);
	song->drawSongTitle->ChangePos(WIDTH * 0.6, HEIGHT * 0.32);
}

void ThroughResult::View() {
	title->View();
	song->coverGraph->View();
	song->drawSongTitle->View();
}

ThroughResult::~ThroughResult() {
	delete title;
}