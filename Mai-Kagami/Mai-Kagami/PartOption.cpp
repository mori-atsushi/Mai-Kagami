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
		if (lastScene == OPTION2)
			PartPop::Init();
		else if (lastScene == nowScene)
			PartPop::ContentUpdate();
		viewFlag = TRUE;
	}
	else {
		viewFlag = FALSE;
	}
	lastScene = nowScene;
}

PartOptionPreview::PartOptionPreview(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	button[0] = new CircleButton(font, touch, "区間", 0, WIDTH * 0.8);
	button[1] = new CircleButton(font, touch, "", 2, WIDTH * 0.8);
	button[2] = new CircleButton(font, touch, "スタート!", 3, WIDTH * 0.8);
	button[3] = new CircleButton2(font, touch, "戻る", 4);
	message = new MyDrawText(font, "変更したいものを選んでください", WIDTH * 0.75, HEIGHT * 0.45, 1, 30);
	caption[0] = new MyDrawText(font, "開始：", WIDTH * 0.8, HEIGHT * 0.53, 2, 30);
	caption[1] = new MyDrawText(font, "終了：", WIDTH * 0.8, HEIGHT * 0.555, 2, 30);
	caption[2] = new MyDrawText(font, "速度：", WIDTH * 0.8, HEIGHT * 0.6, 2, 30);
	para[0] = new MyDrawText(font, "", WIDTH * 0.81, HEIGHT * 0.53, 0, 30, "Yellow");
	para[1] = new MyDrawText(font, "", WIDTH * 0.81, HEIGHT * 0.555, 0, 30, "Yellow");
	para[2] = new MyDrawText(font, "", WIDTH * 0.81, HEIGHT * 0.6, 0, 30, "Yellow");
}

int PartOptionPreview::Switch(const int scene) {
	if (button[0]->GetTouch() == 1)
		return OPTION2_PART;
	if (button[1]->GetTouch() == 1)
		return OPTION2_SPEED;
	if (button[2]->GetTouch() == 1)
		return NEXT2;
	if (button[3]->GetTouch() == 1)
		return MODE;
	return scene;
}
void PartOptionPreview::ContentUpdate() {
	Song *song = songs->GetSong(songs->GetNowSong());
	switch (nowScene)
	{
	case OPTION2:
		char str[256];
		sprintf_s(str, sizeof(str), "×%1.1lf", song->danceMovie->GetSpeed());
		para[0]->ChangeText(song->GetPart(song->StartPart())->GetName());
		para[1]->ChangeText(song->GetPart(song->EndPart())->GetName());
		para[2]->ChangeText(str);
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void PartOptionPreview::ContentView() {
	for (int i = 0; i < 4; i++)
		button[i]->View();
	message->View();
	for (int i = 0; i < 3; i++) {
		caption[i]->View();
		para[i]->View();
	}
}

PartOptionPreview::~PartOptionPreview() {
	for (int i = 0; i < 4; i++)
		delete button[i];
	delete message;
	for (int i = 0; i < 3; i++) {
		delete caption[i];
		delete para[i];
	}
}

PartOptionButton::PartOptionButton(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	speedPop = new PartOptionSpeedPop(font, songs, touch);
	partPop = new PartOptionPartPop(font, songs, touch);
	partOptionPreview = new PartOptionPreview(font, songs, touch);
}

int PartOptionButton::Switch(const int scene) { 
	switch (scene)
	{
	case OPTION2:
		return partOptionPreview->Switch(scene);
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
	partOptionPreview->Load();
}

void PartOptionButton::Delete() {
	speedPop->Delete();
	partPop->Delete();
	partOptionPreview->Delete();
}

void PartOptionButton::ContentUpdate() {
	speedPop->Update(nowScene);
	partPop->Update(nowScene);
	partOptionPreview->Update(nowScene);
	Song *song = songs->GetSong(songs->GetNowSong());
	switch (nowScene)
	{
	case OPTION2:
		song->ChangeStart(0);
		song->ChangeEnd(0);
	case OPTION2_PART:
	case OPTION2_SPEED:
		viewFlag = TRUE;
		break;
	default:
		viewFlag = FALSE;
		break;
	}
}

void PartOptionButton::ContentView() {
	speedPop->View();
	partPop->View();
	partOptionPreview->View();
}

PartOptionButton::~PartOptionButton() {
	delete speedPop;
	delete partPop;
	delete partOptionPreview;
}