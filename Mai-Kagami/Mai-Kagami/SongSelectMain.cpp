#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Songs *songs) {
	f = font;
	loadFlag = 0;
	songSelectTitle = new SongSelectTitle(f, WIDTH * 0.65, HEIGHT * 0.23); //曲選択画面タイトル初期化
	songSelectButton = new SongSelectButton(f);
	songInformation = new SongInformation(f, songs); //選択中の曲初期化
	songSelectPop = new SongSelectPop(f);
	modeSelectButton = new ModeSelectButton(f); //モード選択ボタン初期化
	throughOptionButton = new ThroughOptionButton(f, songs); //通し練習オプションボタン初期化
	touch = new Touch();
}

//曲選択画面ロード
void SongSelect::Load() {
	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		songInformation->Load(); //カバー表示
		loadFlag = 1;
		scene = MAIN;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//曲選択画面計算
int SongSelect::Update() {
	Load();
	if (loadFlag == 2) {
		touch->Check();
		songInformation->Update(touch, scene);
		switch (scene)
		{
		case BACK:
			if (touch->Get(1) == 1)
				scene = BACK_TOP;
			if (touch->Get(2) == 1)
				scene = MAIN;
			break;
		case MAIN:
			if (touch->Get(1) == 1)
				scene = MODE;
			if (touch->Get(4) == 1)
				scene = BACK;
			break;
		case MODE:
			if (touch->Get(0) == 1)
				scene = OPTION1;
			if (touch->Get(4) == 1)
				scene = MAIN;
			break;
		case OPTION1:
			if (touch->Get(2) == 1)
				scene = NEXT;
			if (touch->Get(4) == 1)
				scene = MODE;
		}

		if (scene == BACK_TOP) {
			Delete();
			return TOP;
		}
		
		if (scene == NEXT)
			return THROUGH;

		throughOptionButton->Update(touch, scene);
		songSelectTitle->Update(scene);
	}
	return SONG_SELECT;
}

//曲選択画面表示
void SongSelect::View() {
	if (loadFlag == 2) {
		songInformation->View(scene); //カバー表示
		songSelectTitle->View(); //タイトル表示

		switch (scene)
		{
		case BACK:
			songSelectPop->View();
			break;
		case MAIN:
			songSelectButton->View(); //曲選択ボタン表示
			break;
		case MODE:
			modeSelectButton->View(); //モード選択ボタン表示
			break;
		case OPTION1:
			throughOptionButton->View();
			break;
		}
	}
}

void SongSelect::Delete() {
	loadFlag = 0;
	songInformation->Release();
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
	delete touch;
}