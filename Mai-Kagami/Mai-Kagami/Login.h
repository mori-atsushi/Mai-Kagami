#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

#include "Main.h"
#include "DxLib.h"
#include "Draw.h"

//ログインメッセージ
class LoginMessage {
public:
	void Init();
	void View(); //表示
private:
	MyDrawText myDrawText;
};

//ログインアニメーション
class LoginAnimation {
public:
	void Init();
	void Update();
	void View(); //表示
private:
	MyDrawCircle myDrawCircle[3];
	int alpha[3]; //透明度
	int x, y, r; //表示位置、半径
};

//ログイン画面関係
class Login {
public:
	void Load(); //ロード
	void Update(); //計算
	void View(); //表示
private:
	LoginMessage loginMessage; //ログインメッセージ
	LoginAnimation loginAnimation; //ログインアニメーション
};

#endif