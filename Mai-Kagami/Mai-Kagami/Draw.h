#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#include "Main.h"
#include "Animation.h"

//色関係
class Color {
public:
	Color(const char *color);
	int Get();
	void ChangeColor(const char *color);
private:
	int c;
};

//表示位置用クラス
class Pos : public Animation {
public:
	void ChangePos(const float x, const float y); //座標変更
	void SetPosAnimation(float target_x, float target_y, MyTime duration, int ease = LINER);  // Jaity
	void Update();	// Jaity
	float GetX(); //x座標取得
	float GetY(); //y座標取得
protected:
	Pos();
	Pos(const float x, const float y); //初期化
	float x, y;
private:
	float target_x, target_y;	// アニメーション時の目標座標
	float default_x, default_y;	// アニメーション開始時の座標
};

//描画用クラス
class Draw : public Pos {
public:
	Draw();
	Draw(const float x, const float y);
	void View();
	void SetAlpha(const int alpha = 255); //透明度指定
	void SetViewFlag(const boolean viewFlag);
private:
	virtual void ContentView() = 0; //表示メソッド
	int alpha = 255; //透明度
	boolean viewFlag = TRUE;
};

//描画用クラス（位置指定あり）
class Draw2 : public Draw {
public:
	Draw2(const int position);
	Draw2(const float x, const float y, const int pos);
	void ChangePos();
	void ChangePos(const float x, const float y);
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
private :
	float xx, yy; //座標
	int p; //ポジション情報
};

#endif