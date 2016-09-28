#include "Scene.h"

// �v�Z
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

// �\��
void SubScene::View() {
	if (viewFlag)
		ContentView();
}

// �\�������ǂ����m�F����(TRUE:�\�����AFALSE�F��\����)
boolean SubScene::CheckView() {
	return viewFlag;
}

// ���[�h
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

// �폜
void Scene::Delete() {
	ContentDelete();
	viewFlag = FALSE;
	loadFlag = 0;
}