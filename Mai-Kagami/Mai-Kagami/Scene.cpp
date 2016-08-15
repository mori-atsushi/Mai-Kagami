#include "Scene.h"

//計算
void SubScene::Update(const int scene) {
	nowScene = scene;
	ContentUpdate();
}

void SubScene::Load() {
	viewFlag = TRUE;
}

void SubScene::Delete() {
	viewFlag = FALSE;
}

//表示
void SubScene::View() {
	if (viewFlag)
		ContentView();
}

//表示中かどうか確認する(TRUE:表示中、FALSE：非表示中)
boolean SubScene::CheckView() {
	return viewFlag;
}

//ロード
void Scene::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		ContentLoad();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0) {
		viewFlag = TRUE;
		loadFlag = 2;
	}
}

//削除
void Scene::Delete() {
	ContentDelete();
	viewFlag = FALSE;
	loadFlag = 0;
}