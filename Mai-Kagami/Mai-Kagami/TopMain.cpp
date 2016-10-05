#include "TopMain.h"

//トップ画面コンストラクタ
Top::Top(DecorationItem *decorationItem, User *user) {
	this->user = user;
	decoItem = decorationItem;
	topLogo = new TopLogo(HEIGHT / 3); //ロゴ初期化
	topTouchMessage = new TopTouchMessage(decoItem, HEIGHT * 0.42); //NFCタッチメッセージ初期化
	topTouchButton = new TopTouchButton(decoItem); //NFCタッチボタン初期化
}

//トップ画面初期化
void Top::ContentLoad() {
	topLogo->Load();
	topTouchMessage->Init();
	bgmHandle = LoadSoundMem("SE/bgm.wav");
	nfc.Init();
}

//場面の切り替え
MainScene Top::Switch(const MainScene scene) {
	char* id = nfc.GetId();
	if (id[0] != '\0') {
		user->SetUserId(id);
		nfc.reset_calledCont();
		Delete();
		return SONG_SELECT;
	}
	return TOP;
}

//トップ画面計算
void Top::ContentUpdate() {
	if (nowScene == TOP) {
		Load();
		topTouchMessage->Update(); //NFCタッチメッセージ計算
	}
}

//トップ画面表示
void Top::ContentView() {
	if (CheckSoundMem(bgmHandle) == 0)
		PlaySoundMem(bgmHandle, DX_PLAYTYPE_BACK);
	topLogo->View(); //ロゴ表示
	topTouchMessage->View(); //NFCタッチメッセージ表示
	topTouchButton->View(); //NFCタッチボタン表示
}

void Top::ContentDelete() {
	DeleteSoundMem(bgmHandle);
	topLogo->Release();
}

Top::~Top() {
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}