#include "Draw.h"

//色指定
void Color::Set(char *color) {
	if(!strcmp(color, "White"))
		c = GetColor(255, 255, 255); //白色
	else if(!strcmp(color, "Blue"))
		c = GetColor(127, 210, 234); //青色
}

//色取得
int Color::Get() {
	return c;
}

//フォント指定
void Font::Set(int p) {
	ID = CreateFontToHandle("M+ 1c", p / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
}

//フォント取得
int Font::Get() {
	return ID;
}

//ポジション指定(右寄せ/中央寄せ/左寄せ)
void ViewPos::Init(int a, int b, int pos = 0, int len = 0) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
	switch (pos) {
	case 1:
		x = x - len / 2;;
		break;
	case 2:
		x = x - len;
		break;
	}
}

//x座標取得
int ViewPos::GetX() {
	return x;
}

//y座標取得
int ViewPos::GetY() {
	return y;
}

//テキスト初期化
void MyDrawText::Init(char *s, int a, int b, int pos, int point) {
	str = s;
	font.Set(point);
	color.Set("White");
	strLen = GetDrawStringWidthToHandle(str, (int)strlen(str), font.Get());
	viewPos.Init(a, b, pos, strLen);
}

//テキスト表示
void MyDrawText::Draw() {
	DrawStringToHandle(viewPos.GetX(), viewPos.GetY(), str, color.Get(), font.Get()); //文字表示
}

//テキストの幅取得
int MyDrawText::GetWidth() {
	return strLen;
}

//線初期化
void MyDrawLine::Init(int a, int b, int pos, int length, int width) {
	color.Set("White");
	viewPos.Init(a, b, pos, length);
	w = width / SIZE_RATE;
	len = length;
}

//線表示
void MyDrawLine::Draw() {
	DrawLine(viewPos.GetX(), viewPos.GetY(), viewPos.GetX() + len, viewPos.GetY(), color.Get(), 2);
}

//円初期化
void MyDrawCircle::Init(int a, int b, int radius) {
	viewPos.Init(a, b);
	color.Set("Blue");
	r = radius / SIZE_RATE;
}

//円表示
void  MyDrawCircle::Draw() {
	DrawCircleAA(viewPos.GetX(), viewPos.GetY(), r, 100, color.Get(), TRUE);
}

//リング初期化
void MyDrawRing::Init(int a, int b, int radius, float width) {
	viewPos.Init(a, b);
	color.Set("Blue");
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//リング表示
void  MyDrawRing::Draw() {
	DrawCircleAA(viewPos.GetX(), viewPos.GetY(), r, 100, color.Get(), FALSE, w);
}

//リング初期化
void MyDrawTriangle::Init(int a, int b, int width, int direction) {
	viewPos.Init(a, b);
	color.Set("Blue");
	w = width / SIZE_RATE;
	d = direction;
}

//リング表示
void  MyDrawTriangle::Draw() {
	float x1 = viewPos.GetX();
	float y1 = viewPos.GetY();
	float x2 = viewPos.GetX() - w / 2;
	float y2 = viewPos.GetY();
	float x3 = viewPos.GetX() + w / 2;
	float y3 = viewPos.GetY();
	float a = w * sqrt(3) / 4;
	if (d == 0) {
		y1 -= a;
		y2 += a;
		y3 += a;
	}
	else {
		y1 += a;
		y2 -= a;
		y3 -= a;
	}
	DrawTriangleAA(x1, y1, x2, y2, x3, y3, color.Get(), TRUE);
}

//画像初期化
void MyDrawGraph::Init(int a, int b, char *filename) {
	viewPos.Init(a, b);
	handle = LoadGraph(filename); // 画像のロード
}

//画像表示
void MyDrawGraph::Draw() {
	DrawRotaGraph(viewPos.GetX(), viewPos.GetY(), 1.0 / SIZE_RATE, 0, handle, TRUE, FALSE); //描画
}