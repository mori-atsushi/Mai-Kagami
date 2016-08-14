#include "SongSelectMain.h"

SongSelect::SongSelect(Font *font, Touch *touch, Songs *songs) {
	songSelectTitle = new SongSelectTitle(font); //曲選択画面タイトル初期化
	songSelectButton = new SongSelectButton(font);
	songInformation = new SongInformation(font, songs); //選択中の曲初期化
	songSelectPop = new SongSelectPop(font);
	modeSelectButton = new ModeSelectButton(font); //モード選択ボタン初期化
	throughOptionButton = new ThroughOptionButton(font, songs); //通し練習オプションボタン初期化
	SongSelect::touch = touch;
}

//曲選択画面ロード
void SongSelect::ContentLoad() {
	songInformation->Load(); //カバー画像ロード
	scene = MAIN;
}

//曲選択画面場面切り替え
int SongSelect::Switch() {
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
		throughOptionButton->Check(touch);
	}

	if (scene == BACK_TOP) {
		Delete();
		return TOP;
	}

	if (scene == NEXT) {
		Delete();
		scene = MAIN;
		return THROUGH;
	}
	return SONG_SELECT;
}

//曲選択画面計算
void SongSelect::ContentUpdate() {
	songSelectTitle->Update(scene);
}

//曲選択画面表示
void SongSelect::ContentView() {
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

void SongSelect::ContentDelete() {
	songInformation->Release();
}

SongSelect::~SongSelect() {
	delete songInformation;
	delete songSelectButton;
	delete songSelectTitle;
	delete songSelectPop;
	delete throughOptionButton;
}