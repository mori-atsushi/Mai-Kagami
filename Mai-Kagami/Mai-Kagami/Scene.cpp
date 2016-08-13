#include "Scene.h"

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

//更新
int Scene::Update(const int scene) {
	Load();
	if (loadFlag == 2)
		return ContentUpdate();
	return scene;
}

//表示
void Scene::View() {
	if (loadFlag == 2)
		ContentView();
}

//削除
void Scene::Delete() {
	ContentDelete();
	loadFlag = 0;
}