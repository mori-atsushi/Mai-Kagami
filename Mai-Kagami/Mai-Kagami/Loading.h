#ifndef __LOGIN_H_INCLUDED__
#define __LOGIN_H_INCLUDED__

#include "Main.h"
#include "DxLib.h"
#include "Draw.h"
#include "DrawText.h"
#include "Font.h"

//ログイン画面関係
class Loading {
public:
	Loading(Font *font); //ロード
	void Update(); //計算
	void View(); //表示
	~Loading();
private:
	MyDrawText *myDrawText;
};

#endif