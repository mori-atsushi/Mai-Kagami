#include "Top.h"

//トップロゴコンストラクタ
TopLogo::TopLogo() {
	logo = LoadGraph("img/logo.png"); // 画像のロード
}

//トップロゴ表示
void TopLogo::View() {
	DrawRotaGraph(WIDTH / 2, HEIGHT / 3, WIDTH / 1080.0, 0, logo, TRUE, FALSE); //ロゴの描画
}

//NFCタッチメッセージコンストラクタ
TopTouchMessage::TopTouchMessage() {
	char *str = "-カードをタッチしてください-"; //表示文字列
	myDrawText.Init(str, WIDTH / 2, HEIGHT / 2.35, 1, 50);
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
TopTouchButton::TopTouchButton() {
	char *str = "ここに\nタッチ！"; //表示文字列
	myDrawCircle.Init(WIDTH, NFC_POS, WIDTH / 12);
	myDrawText.Init(str, WIDTH * 0.9, NFC_POS - HEIGHT * 0.025, 2, 50);
}

//NFCタッチボタン表示
void TopTouchButton::View() {
	myDrawCircle.Draw();
	myDrawText.Draw(); //テキスト表示
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