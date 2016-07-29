#include "TopMain.h"

//トップ画面コンストラクタ
Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
	topLogo = new TopLogo(HEIGHT / 3); //ロゴ初期化
	topTouchMessage = new TopTouchMessage(f, HEIGHT * 0.42); //NFCタッチメッセージ初期化
	topTouchButton = new TopTouchButton(f); //NFCタッチボタン初期化
}

//トップ画面初期化
void Top::Load() {
	StopMusic();

	if (loadFlag == 2)
		return;

	if (loadFlag == 0) {
		topLogo->Load();
		topTouchMessage->Init();
		nfc.Init();
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;
}

//トップ画面計算
int Top::Update() {
	Load();
	if (loadFlag == 2) {
		topTouchMessage->Update(); //NFCタッチメッセージ計算
		if (nfc.GetId() != 0) {
			Delete();
			return SONG_SELECT;
		}
	}
	return TOP;
}

//トップ画面表示
void Top::View() {
	if (loadFlag == 2) {
		topLogo->View(); //ロゴ表示
		topTouchMessage->View(); //NFCタッチメッセージ表示
		topTouchButton->View(); //NFCタッチボタン表示}
	}
}

void Top::Delete() {
	loadFlag = 0;
	topLogo->Release();
}

Top::~Top() {
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}