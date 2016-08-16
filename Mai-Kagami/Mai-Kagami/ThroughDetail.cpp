#include "ThroughDetail.h"

ThroughFinish::ThroughFinish(Font *font, Touch *touch) {
	blackBox = new BlackBox();
	button[0] = new CircleButton(font, touch, "おすすめ練習", 0, WIDTH * 0.75, "White");
	button[1] = new CircleButton(font, touch, "練習方法選択", 1, WIDTH * 0.75, "White");
	button[2] = new CircleButton(font, touch, "曲選択画面", 2, WIDTH * 0.75, "White");
	button[3] = new CircleButton(font, touch, "終了", 3, WIDTH * 0.75, "White");
}

ThroughScene ThroughFinish::Switch(const ThroughScene scene) {
	if (button[2]->GetTouch() == 1)
		return THROUGH_BACK_SONG_SELECT;
	if (button[3]->GetTouch() == 1)
		return THROUGH_BACK_TOP;
}

void ThroughFinish::ContentUpdate() {
	if (nowScene == THROUGH_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughFinish::ContentView() {
	blackBox->View();
	for (int i = 0; i < 4; i++)
		button[i]->View();
}

ThroughFinish::~ThroughFinish() {
	delete blackBox;
	for (int i = 0; i < 4; i++)
		delete button[i];
}

ThroughDetail::ThroughDetail(Font *font, Touch *touch) {
	title = new DrawTitle(font, "採点結果");
	button = new CircleButton2(font, touch, "次へ", 4);
	throughFinish = new ThroughFinish(font, touch);
}

ThroughScene ThroughDetail::Switch(const ThroughScene scene) {
	switch (scene)
	{
	case THROUGH_DETAIL:
		if (button->GetTouch() == 1)
			return THROUGH_FINISH;
	case THROUGH_FINISH:
		return throughFinish->Switch(scene);
	}
	return scene;
}

void ThroughDetail::ContentUpdate() {
	throughFinish->Update(nowScene);
	if (nowScene == THROUGH_DETAIL || nowScene == THROUGH_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughDetail::ContentView() {
	title->View();
	button->View();
	throughFinish->View();
}

ThroughDetail::~ThroughDetail() {
	delete title;
	delete button;
	delete throughFinish;
}