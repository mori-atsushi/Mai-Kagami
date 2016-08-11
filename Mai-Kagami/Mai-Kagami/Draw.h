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
	void SetPosAnimation(float _target_x, float _target_y, MyTime _duration, int _ease = LINER);  // Jaity
	void Update();	// Jaity
protected:
	Pos();
	Pos(const float x, const float y); //初期化
	float GetX(); //x座標取得
	float GetY(); //y座標取得
private:
	float a, b;
	float target_x, target_y;	// アニメーション時の目標座標
	float default_x, default_y;	// アニメーション開始時の座標
};

//描画用クラス
class Draw : public Pos {
public:
	Draw();
	Draw(const float x, const float y);
	virtual void View() = 0; //表示メソッド
};

//描画用クラス（位置指定あり）
class Draw2 : public Draw {
public:
	Draw2(const int position);
	Draw2(const float x, const float y, const int pos);
	void ChangePos(const float x, const float y);
	virtual void View() = 0;
	virtual float GetWidth() = 0;
	virtual float GetHeight() = 0;
protected:
	float x, y; //座標
private :
	int p; //ポジション情報
};

#endif