#include "Top.h"

TopLogo::TopLogo(const float y)
	: MyDrawGraph(WIDTH * 0.5, y, "img/logo.png") {
}

//NFCタッチメッセージコンストラクタ
TopTouchMessage::TopTouchMessage(Font *font, const float y)
	: MyDrawText(font, "-カードをタッチしてください-", WIDTH * 0.5, y, 1, 46) {
	t = 0;
}

//NFCタッチメッセージ計算
void TopTouchMessage::Update() {
	if (t > 180)
		alpha = 0;
	else if (t > 120)
		alpha = (180 - t) * 255 / 60;
	else if (t > 60)
		alpha = 255;
	else
		alpha = t * 255 / 60;
	t++;
	t %= 240;
}

//NFCタッチメッセージ表示
void TopTouchMessage::View() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha); //透明度設定
	MyDrawText::View(); //文字表示
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
}

//NFCタッチボタンコンストラクタ
TopTouchButton::TopTouchButton(Font *font, const float r)
	: MyDrawText(font, "ここに\nタッチ！", WIDTH - r, NFC_POS, 2, 40)
	, MyDrawCircle(WIDTH, NFC_POS, r){
}

//NFCタッチボタン表示
void TopTouchButton::View() {
	MyDrawCircle::View(); //円表示
	MyDrawText::View(); //テキスト表示
}

Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
}

//トップ画面初期化
boolean Top::Load() {
	StopMusic();
	if (loadFlag == 0) {
		topLogo = new TopLogo(HEIGHT / 3); //ロゴ初期化
		nfc.Init();
		topTouchMessage = new TopTouchMessage(f, HEIGHT * 0.42); //NFCタッチメッセージ初期化
		topTouchButton = new TopTouchButton(f, WIDTH / 12); //NFCタッチボタン初期化
		loadFlag = 1;
	}

	if (loadFlag == 1 && GetASyncLoadNum() == 0)
		loadFlag = 2;

	if (loadFlag == 2)
		return TRUE;
	return FALSE;
}

//トップ画面計算
int Top::Update() {
	if (Load()) {
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
	delete topLogo;
	delete topTouchButton;
	delete topTouchMessage;
}