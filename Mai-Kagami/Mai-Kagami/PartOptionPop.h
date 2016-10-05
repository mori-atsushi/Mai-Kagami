#ifndef __PARTOPTIONPOP_H_INCLUDED__
#define __PARTOPTIONPOP_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "DecorationItem.h"
#include "Songs.h"
#include "Song.h"
#include "Touch.h"
#include "SeetingPop.h"
#include "Button.h"

//スピード変更用ポップアップ
class PartOptionSpeedPop : public SpeedPop {
public:
	PartOptionSpeedPop(DecorationItem *decorationItem, Songs *songs, Touch *touch, const int mainScene, const int speedScene);
	int Switch(const int scene);
private:
	void ContentUpdate();
	int mainScene, speedScene;
};

//区間変更用ポップアップ
class PartOptionPartPop : public PartPop {
public:
	PartOptionPartPop(DecorationItem *decorationItem, Songs *songs, Touch *touch, const int mainScene, const int partScene);
	int Switch(const int scene);
private:
	DecorationItem *decorationItem;
	void ContentUpdate();
	int mainScene, partScene;
};

//オプション画面の動画とボタン
class PartOptionPreview : public SubScene {
public:
	PartOptionPreview(DecorationItem *decorationItem, Songs *songs, Touch *touch, const int mainScene, const int partScene, const int speedScene);
	virtual int Switch(const int scene);
	~PartOptionPreview();
protected:
	Songs *songs;
	void ContentUpdate();
	void ContentView();
	Button *button[2];
	MyDrawText *message, *caption[3], *para[3];
	int mainScene, partScene, speedScene;
private:
	DecorationItem *decorationItem;
};

class PartOptionPop : public SubScene {
public:
	PartOptionPop(DecorationItem *decorationItem, Songs *songs, Touch *touch, const int mainScene, const int partScene, const int speedScene, PartOptionPreview *partOptionPreview);
	int Switch(const int scene);
	void Load();
	void Delete();
	~PartOptionPop();
private:
	Songs *songs;
	void ContentUpdate();
	void ContentView();
	int mainScene, partScene, speedScene;
	PartOptionSpeedPop *speedPop;
	PartOptionPartPop *partPop;
	PartOptionPreview *partOptionPreview;
};


#endif