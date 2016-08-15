#include "ThroughCountDown.h"


//カウントダウン画面再生三角形
PlayTriangle::PlayTriangle(const float x, const float y)
	: MyDrawTriangle("Yellow") {
	const float w = 100, ex = 12;
	float x1 = x - w + ex, x2 = x - w + ex, x3 = x + w + ex;
	float y1 = y + w, y2 = y - w, y3 = y;
	ChangePos(x1, y1, x2, y2, x3, y3);
}

//カウントダウン画面
ThroughCountDown::ThroughCountDown(Font *font) {
	const float x = WIDTH * 0.5; //円の中心（x座標）
	const float y = HEIGHT * 0.5; //円の中心（y座標）
	const float r = WIDTH * 0.2; //円の半径
	blackBox = new BlackBox();
	text = new MyDrawText(font, "準備をしてください", x, y + r + 80, 1, 40);
	circle = new MyDrawCircle(x, y, r, "White");
	circle->SetAlpha(220);
	countCircle1 = new MyDrawCircleGauge(x, y, r, 0, 4, "Yellow");
	countCircle2 = new MyDrawCircle(0, 0, 12, "Yellow");
	playTriangle = new PlayTriangle(x, y);
}

int ThroughCountDown::Switch(const int scene) {
	if (++count == max)
		return THROUGH_PLAY;
	return scene;
}

void ThroughCountDown::ContentUpdate() {
	static int lastScene = -100;
	if (nowScene == THROUGH_COUNTDOWN) {
		viewFlag = TRUE;
		countCircle1->ChangeDegree((double)count / max * 100);
		countCircle2->ChangePos(countCircle1->GetEndX() * SIZE_RATE, countCircle1->GetEndY() * SIZE_RATE);
	}
	else {
		count = 0;
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

void ThroughCountDown::ContentView() {
	blackBox->View();
	text->View();
	circle->View();
	countCircle1->View();
	countCircle2->View();
	playTriangle->View();
}

ThroughCountDown::~ThroughCountDown() {
	delete blackBox;
	delete text;
	delete circle;
	delete countCircle1;
	delete countCircle2;
	delete playTriangle;
}
