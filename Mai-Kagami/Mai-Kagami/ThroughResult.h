#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "Songs.h"
#include "Scene.h"
#include "ThroughDefine.h"
#include "Touch.h"

class ThroughResult : public SubScene {
public:
	ThroughResult(Font *font, Songs *songs, Touch *touch);
	void Load();
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~ThroughResult();
private:
	MyDrawTextLine *title; //採点結果画面タイトル
	MyDrawCircle *circle; //得点h表示部分の円
	MyDrawCircleGauge *pointCircle; //得点を示す角度指定の円
	MyDrawCircle *pointCircle2; //得点を示す円
	MyDrawText *text; //テキスト（総合得点）
	MyDrawText *point; //得点
	MyDrawText *unit; //単位（点）
	MyDrawText *last; //前回の得点
	Button *button; //次へボタン
	Song *song;
	Songs *songs;
	Touch *touch;
};

#endif