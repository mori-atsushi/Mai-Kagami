#ifndef __PARTRESULT_H_INCLUDED__
#define __PARTRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "Songs.h"
#include "Scene.h"
#include "PartResultDefine.h"
#include "Touch.h"

class PartResult : public SubScene {
public:
	PartResult(Font *font, Songs *songs, Touch *touch);
	void Load();
	int Switch(const int scene);
	~PartResult();
private:
	void ContentUpdate();
	void ContentView();
	MyDrawTextLine *title; //採点結果画面タイトル
	Button *button; //次へボタン
	Song *song;
	Songs *songs;
};

#endif