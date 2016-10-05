#ifndef __TOPMAIN_H_INCLUDED__
#define __TOPMAIN_H_INCLUDED__

#include "Nfc.h"
#include "DxLib.h"
#include "Main.h"
#include "DecorationItem.h"
#include "Top.h"
#include "Scene.h"
#include "User.h"

//トップ画面関係
class Top : public Scene {
public:
	Top(DecorationItem *decorationItem, User *user);
	MainScene Switch(const MainScene scene);
	~Top();
private:
	DecorationItem *decoItem;	//フォント&効果音
	TopLogo *topLogo; //トップロゴ
	TopTouchMessage *topTouchMessage; //NFCタッチメッセージ
	TopTouchButton *topTouchButton; //NFCタッチボタン
	Nfc nfc; //NFC監視
	User *user;
	int bgmHandle; //bgm
	void ContentUpdate(); //計算
	void ContentView(); //表示
	void ContentLoad();
	void ContentDelete();
};

#endif