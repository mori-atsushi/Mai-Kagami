#include "SeetingPop.h"

//ポップアップ用四角形（黒色半透明全画面）
BlackBox::BlackBox()
	: MyDrawBox(WIDTH / 2, HEIGHT / 2, WIDTH, HEIGHT, "Black") {
	MyDrawBox::SetAlpha(220);
}

//スピードオプション表示
SpeedOption::SpeedOption(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	button[0] = new TriangleButton(font, touch, "UP", 0, 0);
	button[1] = new TriangleButton(font, touch, "DOWN", 1, 1);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	speed[0] = new MyDrawText(font, "スピード", WIDTH * 0.72, height, 0, 30);
	speed[1] = new MyDrawText(font, "×1.0", WIDTH * 0.86, height, 0, 30, "Yellow");
}

void SpeedOption::Check() {
	Song *song = songs->GetSong(songs->GetNowSong());
	if (button[0]->GetTouch() == 1)
		song->ChangeSpeed(1);
	if (button[1]->GetTouch() == 1)
		song->ChangeSpeed(-1);
	char str[256];
	sprintf_s(str, sizeof(str), "×%1.1lf", song->danceMovie->GetSpeed());
	speed[1]->ChangeText(str);
}

void SpeedOption::View() {
	for (int i = 0; i < 2; i++) {
		button[i]->View();
		speed[i]->View();
	}
}

SpeedOption::~SpeedOption() {
	for (int i = 0; i < 2; i++) {
		delete button[i];
		delete speed[i];
	}
}

//区間設定オプション表示
PartOption::PartOption(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	button[0] = new TriangleButton(font, touch, "", 0, 0);
	button[1] = new TriangleButton(font, touch, "", 1, 1);
	button[2] = new TriangleButton(font, touch, "", 0, 2);
	button[3] = new TriangleButton(font, touch, "", 1, 3);
	float height = BUTTON_POS + BUTTON_INTERVAL / 2;
	part[0] = new MyDrawText(font, "始め：", WIDTH * 0.67, height, 0, 30);
	part[1] = new MyDrawText(font, "", WIDTH * 0.79, height, 0, 30, "Yellow");
	part[2] = new MyDrawText(font, "終わり：", WIDTH * 0.67, height + BUTTON_INTERVAL * 2, 0, 30);
	part[3] = new MyDrawText(font, "", WIDTH * 0.79, height + BUTTON_INTERVAL * 2, 0, 30, "Yellow");
	
	overallPartBar = new MyDrawBar(WIDTH * 0.5, HEIGHT * 0.6, 5, HEIGHT * 0.22);
	for (int i = 0; i < 10; i++) {
		partName[i] = new MyDrawText(font, "", 0, 0, 0, 24);
	}

	//0の部分はあとで設定
	startPoint = new MyDrawCircle(0, 0, 15);
	endPoint = new MyDrawCircle(0, 0, 15, "Yellow");
	selectedPartBar = new MyDrawBar(0, 0, 4, 0, "Blue");
	caution = new MyDrawText(font, "区間が正しく設定されていません!", WIDTH, HEIGHT * 0.75, ALIGNMENT_RIGHT, 30, "White");
}

void PartOption::Load() {
	song->LoadPart();
}

void PartOption::Init() {
	song = songs->GetSong(songs->GetNowSong());
	part[1]->ChangeText(song->GetPart(song->StartPart())->GetName());
	part[3]->ChangeText(song->GetPart(song->EndPart())->GetName());
}

void PartOption::Check() {
	song = songs->GetSong(songs->GetNowSong());
	if (button[0]->GetTouch() == 1)
		song->ChangeStart(1);
	if (button[1]->GetTouch() == 1)
		song->ChangeStart(-1);
	if (button[2]->GetTouch() == 1)
		song->ChangeEnd(1);
	if (button[3]->GetTouch() == 1)
		song->ChangeEnd(-1);
	part[1]->ChangeText(song->GetPart(song->StartPart())->GetName());
	part[3]->ChangeText(song->GetPart(song->EndPart())->GetName());
}

int flag = 0;
void PartOption::View() {
	int startNum = song->GetStartNum();
	int lastNum = song->GetEndNum();
	int partNum = song->GetPartNum();

	for (int i = 0, n = partNum; i < n; i++) {
		SongPart *songPart = song->GetPart(i);
		float y = overallPartBar->GetY() - overallPartBar->GetHeight() * 0.5 + overallPartBar->GetHeight() * i / partNum;
		
		partName[i]->ChangeText(songPart->GetName());
		partName[i]->ChangePos(WIDTH*0.55, overallPartBar->GetY() - overallPartBar->GetHeight() * 0.5 + overallPartBar->GetHeight() * i / partNum);
		partName[i]->ChangeColor("White");
		
		if (i == startNum) {
			startPoint->ChangePos(overallPartBar->GetX(), y);
			partName[i]->ChangeColor("Blue");
		}
		if (lastNum + 1 == i) {
			endPoint->ChangePos(overallPartBar->GetX(), y);
			partName[i]->ChangeColor("Yellow");
		} else if (lastNum == partNum - 1) {
			endPoint->ChangePos(overallPartBar->GetX(), overallPartBar->GetY() + overallPartBar->GetHeight() / 2);
		}
		partName[i]->View();
	}

	float h, y;
	if (startPoint->GetY() >= endPoint->GetY()) {
		h = startPoint->GetY() - endPoint->GetY();
		y = endPoint->GetY() + h / 2;
		selectedPartBar->ChangeColor("Red");
		caution->SetViewFlag(TRUE);
		this->mode = false;
	} else {
		h = endPoint->GetY() - startPoint->GetY();
		y = startPoint->GetY() + h / 2;
		selectedPartBar->ChangeColor("Blue");
		caution->SetViewFlag(FALSE);
		this->mode = true;
	}
	selectedPartBar->ChangeSize(overallPartBar->GetWidth(), h);
	selectedPartBar->ChangePos(overallPartBar->GetX(), y);
	for (int i = 0; i < 4; i++) {
		button[i]->View();
		part[i]->View();
	}
	caution->View();
	overallPartBar->View();
	selectedPartBar->View();
	startPoint->View();
	endPoint->View();
}

PartOption::~PartOption() {
	for (int i = 0; i < 4; i++) {
		delete button[i];
		delete part[i];
	}
	for (int i = 0, n = song->GetPartNum(); i < n; i++) {
		delete partName[i];
	}
	delete caution;
	delete overallPartBar;
	delete startPoint;
	delete endPoint;
	delete selectedPartBar;
}

//スピードオプションポップアップ
SpeedPop::SpeedPop(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	speedOption = new SpeedOption(font, songs, touch);
	blackBox = new BlackBox();
	button = new CircleButton2(font, touch, "決定", 4);
	text = new MyDrawText(font, "- 速度設定 -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40);
}

void SpeedPop::Load() {
	song = songs->GetSong(songs->GetNowSong());
}

void SpeedPop::ContentUpdate() {
	speedOption->Check();
}

void SpeedPop::ContentView() {
	blackBox->View();
	speedOption->View();
	button->View();
	text->View();
}

SpeedPop::~SpeedPop() {
	delete speedOption;
	delete blackBox;
	delete button;
	delete text;
}

//区間設定オプションポップアップ
PartPop::PartPop(Font *font, Songs *songs, Touch *touch) {
	this->songs = songs;
	blackBox = new BlackBox();
	partOption = new PartOption(font, songs, touch);
	button = new CircleButton2(font, touch, "決定", 4);
	text = new MyDrawText(font, "- 区間設定 -", WIDTH * 0.95, HEIGHT * 0.45, 2, 40);
}

void PartPop::Load() {
	song = songs->GetSong(songs->GetNowSong());
}

void PartPop::ContentUpdate() {
	partOption->Check();
}

void PartPop::SetButtonMode(bool mode) {
	button->SetMode(mode);
}

void PartPop::ContentView() {
	blackBox->View();
	partOption->View();
	button->SetMode(partOption->mode);
	button->View();
	text->View();
}

void PartPop::Init() {
	partOption->Init();
}

PartPop::~PartPop() {
	delete partOption;
	delete blackBox;
	delete button;
	delete text;
}