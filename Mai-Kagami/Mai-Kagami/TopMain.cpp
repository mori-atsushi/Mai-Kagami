#include "TopMain.h"

//トップ画面コンストラクタ
Top::Top(DecorationItem *decorationItem, User *user) {
	this->user = user;
	this->decorationItem = decorationItem;
	topLogo = new TopLogo(HEIGHT / 3); //ロゴ初期化
	topTouchMessage = new TopTouchMessage(decorationItem, HEIGHT * 0.42); //NFCタッチメッセージ初期化
	topTouchButton = new TopTouchButton(decorationItem); //NFCタッチボタン初期化
}

//トップ画面初期化
void Top::ContentLoad() {
	StopMusic();
	topLogo->Load();
	topTouchMessage->Init();
	nfc.Init();
}

//場面の切り替え
MainScene Top::Switch(const MainScene scene) {
	char* id = nfc.GetId();
	if (id[0] != '\0') {
		user->SetUserId(id);
		nfc.reset_calledCont();
		decorationItem->PlaySoundEffect(SOUND_EFFECT_LOGIN);
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
	topLogo->View(); //ロゴ表示
	topTouchMessage->View(); //NFCタッチメッセージ表示
	topTouchButton->View(); //NFCタッチボタン表示
}

void Top::ContentDelete() {
	topLogo->Release();
}

Top::~Top() {
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}