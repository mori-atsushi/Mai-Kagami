#include "Login.h"

//ログインメッセージコンストラクタ
LoginMessage::LoginMessage() {
	int strLen; //文字の長さ
	str = "ログインしています"; //表示文字列
	font.Set(50); //フォントサイズセット
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	x = WIDTH / 2 - strLen / 2;
	y = HEIGHT * 0.46;
}

//ログインメッセージ表示
void LoginMessage::View() {
	Color color;
	DrawStringToHandle(x, y, str, color.White(), font.Get()); //文字表示
}

//ログインアニメーションコンストラクタ
LoginAnimation::LoginAnimation() {
	int strLen; //文字の長さ
	x = WIDTH * 0.5;
	y = HEIGHT * 0.4;
	r = WIDTH / 36;
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
	Color color;

	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[0]); //透明度設定
	DrawCircleAA(x - WIDTH * 0.12, y, r, 100, color.Blue(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[1]); //透明度設定
	DrawCircleAA(x, y, r, 100, color.Blue(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha[2]); //透明度設定
	DrawCircleAA(x + WIDTH * 0.12, y, r, 100, color.Blue(), TRUE);
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0); //透明度解除
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