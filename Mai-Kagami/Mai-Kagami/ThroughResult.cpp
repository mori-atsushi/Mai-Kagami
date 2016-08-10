#include "ThroughResult.h"

ThroughResult::ThroughResult(Font *font) {
	title = new MyDrawTextLine(font, "採点結果", WIDTH * 0.5, HEIGHT * 0.15, 1, 60, WIDTH * 0.5, 4);
	circle = new MyDrawCircle(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, "WHITE");
	pointCircle = new MyDrawCircleGauge(WIDTH * 0.5, HEIGHT * 0.5, WIDTH * 0.3, 78, 6);
	pointCircle2 = new MyDrawCircle(pointCircle->GetEndX() * SIZE_RATE, pointCircle->GetEndY() * SIZE_RATE, 16);
	button = new CircleButton2(font, "次へ", 4);
	text = new MyDrawText(font, "総合得点", WIDTH * 0.5, HEIGHT * 0.4, 1, 46, "Black");
	point = new MyDrawText(font, "78", WIDTH * 0.46, HEIGHT * 0.5, 1, 100, "Blue");
	unit = new MyDrawText(font, "点", WIDTH * 0.54, HEIGHT * 0.51, 0, 46, "Black");
	last = new MyDrawText(font, "前回 --点", WIDTH * 0.5, HEIGHT * 0.6, 1, 36, "Black");
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
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 220); //透明度設定
	circle->View();
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
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