#include "Scene.h"

//場面の切り替え
int SubScene::Switch(const int scene) {
	return scene;
}

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

//表示
void Scene::View() {
	if (loadFlag == 2)
		SubScene::View();
}

//削除
void Scene::Delete() {
	ContentDelete();
	viewFlag = FALSE;
	loadFlag = 0;
}