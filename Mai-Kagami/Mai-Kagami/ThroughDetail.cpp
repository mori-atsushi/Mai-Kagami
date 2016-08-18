#include "ThroughDetail.h"

ThroughFinish::ThroughFinish(Font *font, Touch *touch) {
	blackBox = new BlackBox();
	button[0] = new CircleButton(font, touch, "おすすめ練習", 0, WIDTH * 0.75, "White");
	button[1] = new CircleButton(font, touch, "練習方法選択", 1, WIDTH * 0.75, "White");
	button[2] = new CircleButton(font, touch, "曲選択画面", 2, WIDTH * 0.75, "White");
	button[3] = new CircleButton(font, touch, "終了", 3, WIDTH * 0.75, "White");
}

ThroughResultScene ThroughFinish::Switch(const ThroughResultScene scene) {
	if (button[2]->GetTouch() == 1)
		return THROUGH_RESULT_BACK_SONG_SELECT;
	if (button[3]->GetTouch() == 1)
		return THROUGH_BACK_TOP;
	return scene;
}

void ThroughFinish::ContentUpdate() {
	if (nowScene == THROUGH_RESULT_FINISH)
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

ThroughDetailScreen::ThroughDetailScreen(Font *font, Touch *touch) {
	title = new DrawTitle(font, "採点結果");
	timingBar = new TimingBar(font);
	expressionBar = new ExpressionBar(font);
	resultComment = new ResultComment(font);
	resultBody = new ResultBody(font);
	resultGraph = new ResultGraph(font);
	button = new CircleButton2(font, touch, "次へ", 4);
}

ThroughResultScene ThroughDetailScreen::Switch(const ThroughResultScene scene) {
	if (button->GetTouch() == 1)
		return THROUGH_RESULT_FINISH;
	return scene;
}

void ThroughDetailScreen::Load() {
	char *comment = "Bメロからサビに入ってからサビの終わりにかけてが苦手\nのように思います。そこを重点的に練習しましょう。";
	int point[] = { 1, 1, 2, 3 };
	timingBar->Load(4);
	expressionBar->Load(2);
	resultBody->Load(point);
	resultComment->Load(comment);
}

void ThroughDetailScreen::ContentUpdate() {
	if (nowScene == THROUGH_RESULT_DETAIL || nowScene == THROUGH_RESULT_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughDetailScreen::ContentView() {
	title->View();
	timingBar->View();
	expressionBar->View();
	resultComment->View();
	button->View();
	resultBody->View();
	resultGraph->View();
}

ThroughDetailScreen::~ThroughDetailScreen() {
	delete title;
	delete timingBar;
	delete expressionBar;
	delete resultComment;
	delete button;
	delete resultGraph;
}

ThroughDetail::ThroughDetail(Font *font, Touch *touch) {
	throughDetailScreen = new ThroughDetailScreen(font, touch);
	throughFinish = new ThroughFinish(font, touch);
}

ThroughResultScene ThroughDetail::Switch(const ThroughResultScene scene) {
	switch (scene)
	{
	case THROUGH_RESULT_DETAIL:
		return throughDetailScreen->Switch(scene);
	case THROUGH_RESULT_FINISH:
		return throughFinish->Switch(scene);
	}
	return scene;
}

void ThroughDetail::Load() {
	throughDetailScreen->Load();
	throughFinish->Load();
}

void ThroughDetail::ContentUpdate() {
	throughFinish->Update(nowScene);
	throughDetailScreen->Update(nowScene);
	if (nowScene == THROUGH_RESULT_DETAIL || nowScene == THROUGH_RESULT_FINISH)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

void ThroughDetail::ContentView() {
	throughDetailScreen->View();
	throughFinish->View();
}

ThroughDetail::~ThroughDetail() {
	delete throughDetailScreen;
	delete throughFinish;
}