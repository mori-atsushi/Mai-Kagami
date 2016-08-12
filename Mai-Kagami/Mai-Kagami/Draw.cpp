#include "Draw.h"

//色指定
Color::Color(const char *color) {
	ChangeColor(color);
}

//色取得
int Color::Get() {
	return c;
}

void Color::ChangeColor(const char *color) {
	if (!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //白色
	else if (!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //青色
	else if (!strcmp(color, "Black"))
		c = GetColor(0, 0, 0); //黒色
	else if (!strcmp(color, "Yellow"))
		c = GetColor(255, 255, 0); //黄色
}

//表示位置用クラスコンストラクタ
Pos::Pos() {
	a = 0; b = 0;
}

//表示位置用クラスコンストラクタ
Pos::Pos(const float x, const float y) {
	a = x / SIZE_RATE; b = y / SIZE_RATE;
}

//表示位置変更
void Pos::ChangePos(const float x, const float y) {
	a = x / SIZE_RATE; b = y / SIZE_RATE;
}

// アニメーション用パラメータセット Jaity
void Pos::SetPosAnimation(float _target_x, float _target_y, MyTime _duration, int _ease) {
	if (GetTime() != 0)
		return;
	default_x = GetX() * SIZE_RATE;
	default_y = GetY() * SIZE_RATE;
	target_x = _target_x;
	target_y = _target_y;
	SetRate(_duration, _ease);
	//printfDx("Set: %f %f\n", default_x, default_y);
	//printfDx("Set: %f %f\n", target_x, target_y);
}


// アニメーション更新 Jaity
void Pos::Update() {
	double r = UpdateRate();
	float nx = default_x + (target_x - default_x) * r;
	float ny = default_y + (target_y - default_y) * r;
	//printfDx("Update: %f %f \n", default_x, default_y);
	//printfDx("Update: %f %f\n", GetX(), GetY());
	ChangePos(nx, ny);
}

//x座標取得
float Pos::GetX() {
	return a;
}

//y座標取得
float Pos::GetY() {
	return b;
}

//描画用クラスコンストラクタ
Draw::Draw(){}

//描画用クラスコンストラクタ
Draw::Draw(const float x, const float y) : Pos(x, y) {}

Draw2::Draw2(const int pos) {
	p = pos;
}

Draw2::Draw2(const float x, const float y, const int pos) {
	p = pos;
	ChangePos(x, y);
}

void Draw2::ChangePos(const float x, const float y) {
	Draw2::x = x;
	Draw2::y = y;
	float a = 0;
	switch (p) {
	case 1:
		a -= GetWidth() / 2;
		break;
	case 2:
		a -= GetWidth();
		break;
	}

	Draw::ChangePos(Draw2::x + a, Draw2::y - GetHeight() / 2);
}