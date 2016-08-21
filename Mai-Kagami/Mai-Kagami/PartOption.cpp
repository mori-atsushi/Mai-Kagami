#include "PartOption.h"

PartOptionSpeedPop::PartOptionSpeedPop(Font *font, Songs *songs, Touch *touch)
	: SpeedPop(font, songs, touch) {}

int PartOptionSpeedPop::Switch(const int scene) {
	if (button->GetTouch() == 1) {
		song->danceMovie->SetSpeed();
		return OPTION2;
	}
	return scene;
}

void PartOptionSpeedPop::ContentUpdate() {
	static int lastScene = MAIN;
	if (nowScene == OPTION2_SPEED) {
		if(lastScene == nowScene)
			SpeedPop::ContentUpdate();
		viewFlag = TRUE;
	}
	else {
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

PartOptionPartPop::PartOptionPartPop(Font *font, Songs *songs, Touch *touch)
	: PartPop(font, songs, touch) {}

int PartOptionPartPop::Switch(const int scene) {
	if (button->GetTouch() == 1) {
		song->danceMovie->SetSpeed();
		return OPTION2;
	}
	return scene;
}

void PartOptionPartPop::ContentUpdate() {
	static int lastScene = MAIN;
	if (nowScene == OPTION2_PART) {
		if (lastScene == nowScene)
			PartPop::ContentUpdate();
		viewFlag = TRUE;
	}
	else {
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

PartOptionButton::PartOptionButton(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	button[0] = new CircleButton(font, touch, "区間：イントロ ～ Aパート１", 0, WIDTH * 0.75);
	button[1] = new CircleButton(font, touch, "速度：×0.6", 1, WIDTH * 0.75);
	button[2] = new CircleButton(font, touch, "スタート!", 2, WIDTH * 0.75);
	button[3] = new CircleButton2(font, touch, "戻る", 4);
	speedPop = new PartOptionSpeedPop(font, songs, touch);
	partPop = new PartOptionPartPop(font, songs, touch);
}

int PartOptionButton::Switch(const int scene) { 
	switch (scene)
	{
	case OPTION2:
		if (button[0]->GetTouch() == 1)
			return OPTION2_PART;
		if (button[1]->GetTouch() == 1)
			return OPTION2_SPEED;
		if (button[2]->GetTouch() == 1)
			return NEXT2;
		if (button[3]->GetTouch() == 1)
			return MODE;
		break;
	case OPTION2_PART:
		return partPop->Switch(scene);
	case OPTION2_SPEED:
		return speedPop->Switch(scene);
	}
	return scene;
}

void PartOptionButton::Load() {
	speedPop->Load();
	partPop->Load();
}

void PartOptionButton::Delete() {
	speedPop->Delete();
	partPop->Delete();
}

void PartOptionButton::ContentUpdate() {
	speedPop->Update(nowScene);
	partPop->Update(nowScene);
	Song *song = songs->GetSong(songs->GetNowSong());
	switch (nowScene)
	{
	case OPTION2:
		song->ChangeStart(0);
		song->ChangeEnd(0);
		for (int i = 0; i < 4; i++)
			button[i]->SetViewFlag(TRUE);
		viewFlag = TRUE;
		break;
	case OPTION2_PART:
	case OPTION2_SPEED:
		for (int i = 0; i < 4; i++)
			button[i]->SetViewFlag(FALSE);
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void PartOptionButton::ContentView() {
	for (int i = 0; i < 4; i++)
		button[i]->View();
	speedPop->View();
	partPop->View();
}

PartOptionButton::~PartOptionButton() {
	for (int i = 0; i < 4; i++)
		delete button[i];
	delete speedPop;
	delete partPop;
}