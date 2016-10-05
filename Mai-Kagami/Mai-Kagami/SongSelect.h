#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "DrawObject.h"
#include "Drawtext.h"
#include "Button.h"
#include "Touch.h"
#include "DecorationItem.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "SongSelectDefine.h"

//曲選択画面ボタン関係
class SongSelectButton : public SubScene{
public:
	SongSelectButton(DecorationItem *decorationItem, Touch *touch); //初期化
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView(); //表示
	~SongSelectButton();
private:
	DecorationItem *decorationItem;
	Button *button[4];
};

//終了用ポップアップ
class SongSelectPop : public SubScene {
public:
	SongSelectPop(DecorationItem *decorationItem, Touch *touch);
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~SongSelectPop();
private:
	DecorationItem *decorationItem;
	Touch *touch;
	BlackBox *blackBox;
	MyDrawText *title;
	MyDrawText *message;
	Button *button[2];
};

#endif