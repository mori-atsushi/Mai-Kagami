#ifndef __PARTOPTION_H_INCLUDED__
#define __PARTOPTION_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "Font.h"
#include "Songs.h"
#include "Song.h"
#include "Touch.h"
#include "SongSelectDefine.h"
#include "SeetingPop.h"
#include "Button.h"

//区間変更用ポップアップ
class PartOptionSpeedPop : public SpeedPop {
public:
	PartOptionSpeedPop(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
private:
	void ContentUpdate();
};

//スピード変更用ポップアップ
class PartOptionPartPop : public PartPop {
public:
	PartOptionPartPop(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
private:
	void ContentUpdate();
};

//オプション画面の動画とボタン
class PartOptionPreview : public SubScene {
public:
	PartOptionPreview(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
	~PartOptionPreview();
private:
	Songs *songs;
	void ContentUpdate();
	void ContentView();
	Button *button[4];
	MyDrawText *message, *caption[3], *para[3];
};

class PartOptionButton : public SubScene {
public:
	PartOptionButton(Font *font, Songs *songs, Touch *touch);
	int Switch(const int scene);
	void Load();
	void Delete();
	~PartOptionButton();
private:
	Songs *songs;
	void ContentUpdate();
	void ContentView();
	PartOptionSpeedPop *speedPop;
	PartOptionPartPop *partPop;
	PartOptionPreview *partOptionPreview;
};


#endif