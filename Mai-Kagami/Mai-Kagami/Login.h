#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

#include "Main.h"
#include "DxLib.h"
#include "Draw.h"

//ログインメッセージ
class LoginMessage {
public:
	LoginMessage();
	void View(); //表示
private:
	Font font;
	char *str; //表示文字列
	int x, y; //表示位置
};

//ログインアニメーション
class LoginAnimation {
public:
	LoginAnimation();
	void Update();
	void View(); //表示
private:
	int alpha[3]; //透明度
	int x, y, r; //表示位置、半径
};

//ログイン画面関係
class Login {
public:
	void Update(); //計算
	void View(); //表示
private:
	LoginMessage loginMessage; //ログインメッセージ
	LoginAnimation loginAnimation; //ログインアニメーション
};

#endif