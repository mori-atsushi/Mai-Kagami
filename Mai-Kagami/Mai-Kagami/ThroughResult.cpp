#include "ThroughResult.h"

ThroughResult::ThroughResult(Font *font) {
	title = new MyDrawTextLine(font, "Ì“_Œ‹‰Ê", WIDTH * 0.5, HEIGHT * 0.15, 1, 60, WIDTH * 0.5, 4);
	circle = new MyDrawCircle(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, "WHITE");
	button = new CircleButton2(font, "ŽŸ‚Ö", 4);
	point = new MyDrawText(font, "78", WIDTH * 0.49, HEIGHT * 0.5, 1, 100, "Blue");
}

void ThroughResult::Load(Song *song) {
	ThroughResult::song = song;
	song->coverGraph->Load();
}

void ThroughResult::Update() {
	song->coverGraph->ChangePos(WIDTH * 0.3, HEIGHT * 0.26);
	song->drawSongTitle->ChangePos(WIDTH * 0.6, HEIGHT * 0.24);
}

void ThroughResult::View() {
	title->View();
	song->coverGraph->View();
	song->drawSongTitle->View();
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //“§–¾“xÝ’è
	circle->View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //“§–¾“x‰ðœ
	point->View();
	button->View();
}

ThroughResult::~ThroughResult() {
	delete title;
	delete circle;
	delete button;
}