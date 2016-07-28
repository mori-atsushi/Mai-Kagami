#include "Draw.h"

//色指定
Color::Color(const char *color) {
	if(!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //白色
	else if(!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //青色
	else if(!strcmp(color, "Black"))
		c = GetColor(0, 0, 0); //黒色
	else if (!strcmp(color, "Yellow"))
		c = GetColor(255, 255, 0); //黄色
}

//色取得
int Color::Get() {
	return c;
}

//表示位置用クラスコンストラクタ
Pos::Pos(const float x, const float y) {
	a = x / SIZE_RATE; b = y / SIZE_RATE;
}

//表示位置変更
void Pos::ChangePos(const float x, const float y) {
	a = x / SIZE_RATE; b = y / SIZE_RATE;
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
Draw::Draw() :Pos(0, 0) {
}

//描画用クラスコンストラクタ
Draw::Draw(const float x, const float y) :Pos(x, y) {
}