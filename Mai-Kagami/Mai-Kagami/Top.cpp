#include "Top.h"

TopLogo::TopLogo(const float y)
	: MyDrawGraph(WIDTH * 0.5, y, "img/logo.png") {
}

//NFCタッチメッセージコンストラクタ
TopTouchMessage::TopTouchMessage(Font *font, const float y)
	: MyDrawText(font, "-カードをタッチしてください-", WIDTH * 0.5, y, 1, 46) {
	Init();
}

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

Top::Top(Font *font) {
	f = font;
	loadFlag = 0;
	topLogo = new TopLogo(HEIGHT / 3); //ロゴ初期化
	topTouchMessage = new TopTouchMessage(f, HEIGHT * 0.42); //NFCタッチメッセージ初期化
	topTouchButton = new TopTouchButton(f, WIDTH / 12); //NFCタッチボタン初期化
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