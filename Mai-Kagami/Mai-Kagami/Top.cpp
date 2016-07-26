#include "Top.h"

//NFCタッチメッセージコンストラクタ
TopTouchMessage::TopTouchMessage(Font *font) {
	char *str = "-カードをタッチしてください-"; //表示文字列
	myDrawText = new MyDrawText(font, str, WIDTH * 0.5, HEIGHT * 0.41, 1, 46);
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
	myDrawText->Draw(); //文字表示
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
}

//NFCタッチメッセージデストラクタ
TopTouchMessage::~TopTouchMessage() {
	delete myDrawText;
}

//NFCタッチボタンコンストラクタ
TopTouchButton::TopTouchButton(Font *font) {
	char *str = "ここに\nタッチ！"; //表示文字列
	myDrawCircle = new MyDrawCircle(WIDTH, NFC_POS, WIDTH / 12);
	myDrawText = new MyDrawText(font, str, WIDTH * 0.92, NFC_POS - HEIGHT * 0.028, 2, 40);
}

//NFCタッチボタン表示
void TopTouchButton::View() {
	myDrawCircle->Draw(); //円表示
	myDrawText->Draw(); //テキスト表示
}

//NFCタッチメッセージデストラクタ
TopTouchButton::~TopTouchButton() {
	delete myDrawText;
}

Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
}

//トップ画面初期化
boolean Top::Load() {
	StopMusic();
	if (loadFlag == 0) {
		myDrawGraph = new MyDrawGraph(WIDTH / 2, HEIGHT / 3, "img/logo.png"); //ロゴ初期化
		nfc.Init();
		topTouchMessage = new TopTouchMessage(f); //NFCタッチメッセージ初期化
		topTouchButton = new TopTouchButton(f); //NFCタッチボタン初期化
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
		myDrawGraph->Draw(); //ロゴ表示
		topTouchMessage->View(); //NFCタッチメッセージ表示
		topTouchButton->View(); //NFCタッチボタン表示}
	}
}

void Top::Delete() {
	loadFlag = 0;
	delete myDrawGraph;
	delete topTouchButton;
	delete topTouchMessage;
}