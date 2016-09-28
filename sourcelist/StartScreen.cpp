#include "StartScreen.h"

StartSceen::StartSceen(Font *f, const int startScene, const int playScene) {
	this->startScene = startScene;
	this->playScene = playScene;
	blackBox = new BlackBox();
	myDrawGraph = new MyDrawGraph(WIDTH * 0.5, HEIGHT * 0.45, "img/start.png");
	myDrawGraph->Load();
	wait = new MyDrawText(f, "", WIDTH * 0.5, HEIGHT * 0.3, 1, 40);
	caution = new MyDrawText(f, "�{�̂���2���[�g���ȏ㗣��Ă�������", WIDTH * 0.5, HEIGHT * 0.67, 1, 46, "Blue");
	annotation = new MyDrawTexts(f, "��2���[�g���ȓ��ɓ����\n�����I�ɋȂ��ꎞ��~���܂�", WIDTH * 0.5, HEIGHT * 0.75, 1, 36, 20);
}

void StartSceen::Load() {
	wait->ChangeText("�������c");
	annotation->SetViewFlag(TRUE);
}

void StartSceen::ContentUpdate() {
	if (nowScene == startScene) {
		viewFlag = TRUE;
	}
	else {
		viewFlag = FALSE;
		if (nowScene = playScene) {
			wait->ChangeText("�ꎞ��~��");
			annotation->SetViewFlag(FALSE);
		}
	}
}

void StartSceen::ContentView() {
	blackBox->View();
	myDrawGraph->View();
	wait->View();
	caution->View();
	annotation->View();
}

StartSceen::~StartSceen() {
	delete myDrawGraph;
	delete wait;
	delete caution;
	delete annotation;
	delete blackBox;
}