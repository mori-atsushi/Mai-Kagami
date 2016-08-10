#ifndef __TOPMAIN_H_INCLUDED__
#define __TOPMAIN_H_INCLUDED__

#include "Nfc.h"
#include "DxLib.h"
#include "Main.h"
#include "Font.h"
#include "Top.h"

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