#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "ModeSelect.h"
#include "Draw.h"
#include "Common.h"
#include "Touch.h"
#include "Loading.h"
#include "Song.h"
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
	MyDrawBox *myDrawBox;
	MyDrawText *title;
	MyDrawText *message;
	Button *button[2];
};

#endif