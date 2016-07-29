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
TopTouchButton::TopTouchButton(Font *font)
	: Draw(WIDTH, NFC_POS) {
	float r = WIDTH / 12;
	text = new MyDrawText(font, "ここに\nタッチ！", GetX() * SIZE_RATE - r, GetY() * SIZE_RATE, 2, 40);
	circle = new MyDrawCircle(GetX() * SIZE_RATE, GetY() * SIZE_RATE, r);
}

//NFCタッチボタン表示
void TopTouchButton::View() {
	text->View(); //円表示
	circle->View(); //テキスト表示
}

TopTouchButton::~TopTouchButton() {
	delete text;
	delete circle;
}