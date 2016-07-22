#include "Login.h"

//ログインメッセージコンストラクタ
void LoginMessage::Init() {
	char *str = "ログインしています"; //表示文字列
	myDrawText.Init(str, WIDTH / 2, HEIGHT * 0.46, 1, 50);
}

//ログインメッセージ表示
void LoginMessage::View() {
	myDrawText.Draw();
}

//ログインアニメーションコンストラクタ
void LoginAnimation::Init() {
	for(int i = 0; i < 3; i++)
		myDrawCircle[i].Init(WIDTH * 0.5 + (i - 1) * WIDTH * 0.12, HEIGHT * 0.4, WIDTH / 36);
}

//ログインアニメーション計算
void LoginAnimation::Update() {
	static int t = 0; //時間
	if (t < 60) {
		alpha[1] = 0; alpha[2] = 0;
		if (t < 30)
			alpha[0] = t * 255 / 30;
		else
			alpha[0] = 255;
	}
	else if (t < 120) {
		alpha[0] = 255; alpha[2] = 0;
		if (t < 90)
			alpha[1] = (t - 60) * 255 / 30;
		else
			alpha[1] = 255;
	}
	else if (t < 180) {
		alpha[0] = 255; alpha[1] = 255;
		if (t < 150)
			alpha[2] = (t - 120) * 255 / 30;
		else
			alpha[2] = 255;

	}
	else {
		if (t < 210) {
			alpha[0] = (210 - t) * 255 / 30;
			alpha[1] = (210 - t) * 255 / 30;
			alpha[2] = (210 - t) * 255 / 30;
		}
		else {
			alpha[0] = 0; alpha[1] = 0; alpha[2] = 0;
		}
	}
	t++;
	t %= 240;
}

//ログインアニメーション表示
void LoginAnimation::View() {
	for (int i = 0; i < 3; i++) {
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[i]); //透明度設定
		myDrawCircle[i].Draw();
	}
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
}

//ログイン画面ロード
void Login::Load() {
	loginMessage.Init();
	loginAnimation.Init();
}

//ログイン画面計算
void Login::Update() {
	loginAnimation.Update(); //ログインアニメーション計算
}

//ログイン画面表示
void Login::View() {
	loginMessage.View(); //ログインメッセージ表示
	loginAnimation.View(); //ログインアニメーション表示
}