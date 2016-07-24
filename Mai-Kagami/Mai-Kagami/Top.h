#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Nfc.h"

//NFCタッチメッセージ関係
class TopTouchMessage {
public:
	void Init();
	void Update(); //計算
	void View(); //表示
private:
	MyDrawText myDrawText;
	int alpha; //透明度
};

//NFCタッチボタン関係
class TopTouchButton {
public:
	void Init();
	void View(); //表示
private:
	MyDrawCircle myDrawCircle;
	MyDrawText myDrawText;
};

//トップ画面関係
class Top { 
public:
	void Load();
	int Update(); //計算
	void View(); //表示
private:
	MyDrawGraph myDrawGraph; //トップロゴ
	TopTouchMessage topTouchMessage; //NFCタッチメッセージ
	TopTouchButton topTouchButton; //NFCタッチボタン
	Nfc nfc; //NFC監視
};

#endif