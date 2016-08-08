#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "DrawObject.h"
#include "Drawtext.h"
#include "Button.h"
#include "Touch.h"
#include "Font.h"

//曲選択画面ボタン関係
class SongSelectButton {
public:
	SongSelectButton(Font *font); //初期化
	void View(); //表示
	~SongSelectButton();
private:
	Button *button[4];
};

//ポップアップ関係
class SongSelectPop {
public:
	SongSelectPop(Font *font);
	void View();
	~SongSelectPop();
private:
	BlackBox *blackBox;
	MyDrawText *title;
	MyDrawText *message;
	Button *button[2];
};

#endif