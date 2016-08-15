#include "ThroughResult.h"

ThroughResult::ThroughResult(Font *font, Songs *songs, Touch *touch) {
	this->touch = touch;
	this->songs = songs;
	title = new MyDrawTextLine(font, "採点結果", WIDTH * 0.5, HEIGHT * 0.15, 1, 60, WIDTH * 0.5, 4);
	circle = new MyDrawCircle(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, "WHITE");
	circle->SetAlpha(220);
	pointCircle = new MyDrawCircleGauge(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, 78, 6);
	pointCircle2 = new MyDrawCircle(pointCircle->GetEndX() * SIZE_RATE, pointCircle->GetEndY() * SIZE_RATE, 16);
	button = new CircleButton2(font, "次へ", 4);
	text = new MyDrawText(font, "総合得点", WIDTH * 0.5, HEIGHT * 0.4, 1, 46, "Black");
	point = new MyDrawText(font, "78", WIDTH * 0.46, HEIGHT * 0.5, 1, 100, "Blue");
	unit = new MyDrawText(font, "点", WIDTH * 0.54, HEIGHT * 0.51, 0, 46, "Black");
	last = new MyDrawText(font, "前回 --点", WIDTH * 0.5, HEIGHT * 0.6, 1, 36, "Black");
}

void ThroughResult::Load() {
	song = songs->GetSong(songs->GetNowSong());
	song->coverGraph->Load();
}

ThroughScene ThroughResult::Switch(const ThroughScene scene) {
	if (touch->Get(4) == 1)
		return THROUGH_DETAIL;
	return scene;
}

void ThroughResult::ContentUpdate() {
	if (nowScene == THROUGH_RESULT) {
		song->coverGraph->ChangePos(WIDTH * 0.3, HEIGHT * 0.26);
		song->drawSongTitle->ChangePos(WIDTH * 0.6, HEIGHT * 0.24);
		viewFlag = TRUE;
	}
	else {
		viewFlag = FALSE;
	}
}

void ThroughResult::ContentView() {
	title->View();
	song->coverGraph->View();
	song->drawSongTitle->View();
	circle->View();
	pointCircle->View();
	pointCircle2->View();
	text->View();
	point->View();
	unit->View();
	last->View();
	button->View();
}

ThroughResult::~ThroughResult() {
	delete title;
	delete circle;
	delete pointCircle;
	delete pointCircle2;
	delete button;
	delete text;
	delete unit;
	delete last;
}