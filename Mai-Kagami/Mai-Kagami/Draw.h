#ifndef __DRAW_H_INCLUDED__
#define __DRAW_H_INCLUDED__

#include <math.h>
#include "DxLib.h"
#include "Main.h"

//色関係
class Color {
public:
	Color(const char *color);
	int Get();
private:
	int c;
};

//表示位置関係
class ViewPos {
public :
	ViewPos(float a, float b, int pos = 0, float len = 0);
	void ChangePos(float a, float b);
	void ChangeLenth( float len);
	float GetX();
	float GetY();
private:
	float x, y;
	float xx, yy;
	int p;
};

//表示位置用クラス
class Pos {
public:
	void ChangePos(const float x, const float y); //座標変更
protected:
	Pos(const float x, const float y); //初期化
	float GetX(); //x座標取得
	float GetY(); //y座標取得
private:
	float a, b;
};

//描画用クラス
class Draw : public Pos{
public:
	Draw(const float x, const float y);
	virtual void View() = 0; //表示メソッド
};

#endif