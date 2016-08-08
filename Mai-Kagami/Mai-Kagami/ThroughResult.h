#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "Font.h"
#include "Song.h"

class ThroughResult {
public:
	ThroughResult(Font *font);
	void Update();
	void Load(Song *song);
	void View();
	~ThroughResult();
private:
	MyDrawTextLine *title; //採点結果画面タイトル
	MyDrawCircle *circle; //得点の円
	MyDrawText *text; //テキスト（総合得点）
	MyDrawText *point; //得点
	MyDrawText *unit; //単位（点）
	MyDrawText *last; //前回の得点
	Button *button; //次へボタン
	Song *song;
};

#endif