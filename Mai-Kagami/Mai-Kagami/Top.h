#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "Nfc.h"

//トップロゴ関係
class TopLogo {
public:
	TopLogo();
	void View(); //表示
private:
	int logo; //画像ID
};

//NFCタッチメッセージ関係
class TopTouchMessage {
public:
	TopTouchMessage();
	void Update(); //計算
	void View(); //表示
private:
	Font font;
	char *str; //表示文字列
	int x, y; //表示位置
	int alpha; //透明度
};

//NFCタッチボタン関係
class TopTouchButton {
public:
	TopTouchButton();
	void View(); //表示
private:
	Font font;
	int x, y; //表示位置
};

//トップ画面関係
class Top { 
public:
	int Update(); //計算
	void View(); //表示
private:
	TopLogo topLogo; //トップロゴクラス
	TopTouchMessage topTouchMessage; //NFCタッチメッセージ
	TopTouchButton topTouchButton; //NFCタッチボタン
	Nfc nfc; //NFC監視
};

#endif