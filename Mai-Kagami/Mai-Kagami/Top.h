#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Nfc.h"
#include "Font.h"

//NFCタッチメッセージ関係
class TopTouchMessage {
public:
	TopTouchMessage(Font *font);
	void Update(); //計算
	void View(); //表示
	~TopTouchMessage();
private:
	MyDrawText *myDrawText;
	int alpha, t; //透明度, 時間
};

//NFCタッチボタン関係
class TopTouchButton {
public:
	TopTouchButton(Font *font);
	void View(); //表示
	~TopTouchButton();
private:
	MyDrawCircle *myDrawCircle;
	MyDrawText *myDrawText;
};

//トップ画面関係
class Top { 
public:
	Top(Font *font);
	int Update(); //計算
	void View(); //表示
private:
	Font *f;
	MyDrawGraph *myDrawGraph; //トップロゴ
	TopTouchMessage *topTouchMessage; //NFCタッチメッセージ
	TopTouchButton *topTouchButton; //NFCタッチボタン
	Nfc nfc; //NFC監視
	int loadFlag;
	boolean Load();
	void Delete();
};

#endif