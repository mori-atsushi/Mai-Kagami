#include "Top.h"

//トップロゴ
TopLogo::TopLogo(const float y)
	: MyDrawGraph(WIDTH * 0.5, y, "img/logo.png") {
}

//NFCタッチメッセージコンストラクタ
TopTouchMessage::TopTouchMessage(Font *font, const float y)
	: MyDrawText(font, "-カードをタッチしてください-", WIDTH * 0.5, y, 1, 46) {
	Init(); //初期化
}


//NFCタッチメッセージ初期化
void TopTouchMessage::Init() {
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