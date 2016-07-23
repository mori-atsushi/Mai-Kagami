#include "Top.h"

//トップロゴ初期化
void TopLogo::Init() {
	myDrawGraph.Init(WIDTH / 2, HEIGHT / 3, "img/logo.png");
}

//トップロゴ表示
void TopLogo::View() {
	myDrawGraph.Draw();
}

//NFCタッチメッセージコンストラクタ
void TopTouchMessage::Init() {
	char *str = "-カードをタッチしてください-"; //表示文字列
	myDrawText.Init(str, WIDTH * 0.5, HEIGHT * 0.41, 1, 46);
}

//NFCタッチメッセージ計算
void TopTouchMessage::Update() {
	static int t = 0; //時間
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
	myDrawText.Draw(); //文字表示
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
}

//NFCタッチボタンコンストラクタ
void TopTouchButton::Init() {
	char *str = "ここに\nタッチ！"; //表示文字列
	myDrawCircle.Init(WIDTH, NFC_POS, WIDTH / 12);
	myDrawText.Init(str, WIDTH * 0.92, NFC_POS - HEIGHT * 0.028, 2, 40);
}

//NFCタッチボタン表示
void TopTouchButton::View() {
	myDrawCircle.Draw();
	myDrawText.Draw(); //テキスト表示
}

//トップ画面初期化
void Top::Load() {
	topLogo.Init(); //ロゴ初期化
	topTouchMessage.Init(); //NFCタッチメッセージ初期化
	topTouchButton.Init(); //NFCタッチボタン初期化
}

//トップ画面計算
int Top::Update() {
	topTouchMessage.Update(); //NFCタッチメッセージ計算
	if (nfc.GetId() != 0)
		return LOGIN;
	return TOP;
}

//トップ画面表示
void Top::View() {
	topLogo.View(); //ロゴ表示
	topTouchMessage.View(); //NFCタッチメッセージ表示
	topTouchButton.View(); //NFCタッチボタン表示
}