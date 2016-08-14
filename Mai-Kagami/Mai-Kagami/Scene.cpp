#include "Scene.h"

int SubScene::Switch(const int scene) {
	return scene;
}

void SubScene::Update(const int scene) {
	nowScene = scene;
	ContentUpdate();
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

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//表示
void Scene::View() {
	if (loadFlag == 2)
		SubScene::View();
}

//削除
void Scene::Delete() {
	ContentDelete();
	loadFlag = 0;
}