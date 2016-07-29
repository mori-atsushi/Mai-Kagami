#ifndef __TOP_H_INCLUDED__
#define __TOP_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "Draw.h"
#include "DrawText.h"
#include "DrawGraph.h"
#include "DrawObject.h"
#include "Nfc.h"
#include "Font.h"

class TopLogo : public MyDrawGraph {
public:
	TopLogo( const float y);
};

//NFCタッチメッセージ関係
class TopTouchMessage : public MyDrawText {
public:
	TopTouchMessage(Font *font, const float y);
	void Init(); //初期化
	void Update(); //計算
	void View(); //表示
private:
	int alpha, t; //透明度, 時間
};

//NFCタッチボタン関係
class TopTouchButton : public MyDrawText, public MyDrawCircle {
public:
	TopTouchButton(Font *font, const float r);
	void View(); //表示
};

//トップ画面関係
class Top { 
public:
	Top(Font *font);
	int Update(); //計算
	void View(); //表示
	~Top();
private:
	Font *f;
	TopLogo *topLogo; //トップロゴ
	TopTouchMessage *topTouchMessage; //NFCタッチメッセージ
	TopTouchButton *topTouchButton; //NFCタッチボタン
	Nfc nfc; //NFC監視
	int loadFlag;
	void Load();
	void Delete();
};

#endif