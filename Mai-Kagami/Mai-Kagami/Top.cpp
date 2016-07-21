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
	int strLen; //文字列の長さ

	str = "-カードをタッチしてください-"; //表示文字列
	font.Set(50); //フォントサイズセット
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	x = WIDTH / 2 - strLen / 2;
	y = HEIGHT / 2.35;
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
	Color color;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha); //透明度設定
	DrawStringToHandle(x, y, str, color.White(), font.Get()); //文字表示
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
}

//NFCタッチボタンコンストラクタ
TopTouchButton::TopTouchButton() {
	font.Set(50); //フォントサイズセット
	x = WIDTH;
	y = NFC_POS;
}

//NFCタッチボタン表示
void TopTouchButton::View() {
	Color color;

	DrawCircleAA(x, y, WIDTH / 12, 100, color.Blue(), TRUE);
	DrawStringToHandle(x - WIDTH * 0.3, y - HEIGHT * 0.025 , "ここに\nタッチ！", color.White(), font.Get());
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