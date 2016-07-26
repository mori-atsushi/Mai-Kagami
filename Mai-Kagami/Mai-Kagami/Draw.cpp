#include "Draw.h"

//色指定
Color::Color(char *color) {
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

//ポジション指定(右寄せ/中央寄せ/左寄せ)
ViewPos::ViewPos(float a, float b, int pos, float len) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
	switch (pos) {
	case 1:
		x = x - len / 2;
		break;
	case 2:
		x = x - len;
		break;
	}
}

void ViewPos::ChangePos(float a, float b) {
	x = a / SIZE_RATE; y = b / SIZE_RATE;
}

//x座標取得
float ViewPos::GetX() {
	return x;
}

//y座標取得
float ViewPos::GetY() {
	return y;
}

//テキスト初期化
MyDrawText::MyDrawText(Font *font, char *s, int a, int b, int pos, int point, char *colorName) {
	str = s;
	f = font->Get(point);
	color = new Color(colorName);
	viewPos = new ViewPos(a, b, pos, GetWidth() / SIZE_RATE);
}

//テキスト表示
void MyDrawText::Draw() {
	DrawStringToHandle(viewPos->GetX(), viewPos->GetY(), str.c_str(), color->Get(), f); //文字表示
}

void MyDrawText::ChangeText(char *s) {
	str = s;
}

//テキストの幅取得
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(str.c_str(), (int)strlen(str.c_str()), f) * SIZE_RATE;
}

//テキストデストラクタ
MyDrawText::~MyDrawText() {
	delete viewPos;
	delete color;
}

//線初期化
MyDrawLine::MyDrawLine(int a, int b, int pos, int length, int width) {
	color = new Color("White");
	len = length / SIZE_RATE;
	viewPos = new ViewPos(a, b, pos, len);
	w = width / SIZE_RATE;
}

//線表示
void MyDrawLine::Draw() {
	DrawLine(viewPos->GetX(), viewPos->GetY(), viewPos->GetX() + len, viewPos->GetY(), color->Get(), w);
}

//線デストラクタ
MyDrawLine::~MyDrawLine() {
	delete color;
	delete viewPos;
}

//円初期化
MyDrawCircle::MyDrawCircle(int a, int b, int radius, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	r = radius / SIZE_RATE;
	w = 0;
}

//円初期化2
MyDrawCircle::MyDrawCircle(int a, int b, int radius, float width, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	r = radius / SIZE_RATE;
	w = width / SIZE_RATE;
}

//円表示
void  MyDrawCircle::Draw() {
	boolean flag = TRUE;
	if (w != 0)
		flag = FALSE;
	DrawCircleAA(viewPos->GetX(), viewPos->GetY(), r, 100, color->Get(), flag, w);
}

MyDrawCircle::~MyDrawCircle() {
	delete color;
	delete viewPos;
}

//三角形初期化
MyDrawTriangle::MyDrawTriangle(int a, int b, int width, int direction, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	w = width / SIZE_RATE;
	d = direction;
}

//三角形表示
void  MyDrawTriangle::Draw() {
	float x1 = viewPos->GetX();	float y1 = viewPos->GetY();
	float x2 = viewPos->GetX();	float y2 = viewPos->GetY();
	float x3 = viewPos->GetX();	float y3 = viewPos->GetY();
	float a = w * sqrt(3) / 4;

	switch (d)
	{
	case 0:
		x2 -= w / 2; x3 += w / 2;
		y1 -= a; y2 += a; y3 += a;
		break;
	case 1:
		x2 -= w / 2; x3 += w / 2;
		y1 += a; y2 -= a; y3 -= a;
		break;
	case 2:
		y2 -= w / 2; y3 += w / 2;
		x1 += a; x2 -= a; x3 -= a;
		break;
	}

	DrawTriangleAA(x1, y1, x2, y2, x3, y3, color->Get(), TRUE);
}

MyDrawTriangle::~MyDrawTriangle() {
	delete color;
	delete viewPos;
}

//四角形初期化
MyDrawBox::MyDrawBox(int a, int b, int width, int height, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = 0;
}

//四角形初期化2
MyDrawBox::MyDrawBox(int a, int b, int width, int height, float line, char *colorName) {
	viewPos = new ViewPos(a, b);
	color = new Color(colorName);
	w = width / SIZE_RATE;
	h = height / SIZE_RATE;
	l = line / SIZE_RATE;
}

//四角形表示
void  MyDrawBox::Draw() {
	boolean flag = TRUE;
	if (l != 0)
		flag = FALSE;
	float x1 = viewPos->GetX() - w / 2 + 1;
	float y1 = viewPos->GetY() - h / 2 + 1;
	float x2 = viewPos->GetX() + w / 2;
	float y2 = viewPos->GetY() + h / 2;

	DrawBoxAA(x1, y1, x2, y2, color->Get(), flag, l);
}

MyDrawBox::~MyDrawBox() {
	delete color;
	delete viewPos;
}

//画像初期化
MyDrawGraph::MyDrawGraph(float a, float b, char *filename, double ExRate) {
	viewPos = new ViewPos(a, b);
	handle = LoadGraph(filename); // 画像のロード
	ex = ExRate;
}

//画像表示
void MyDrawGraph::Draw() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(viewPos->GetX(), viewPos->GetY(), ex / SIZE_RATE, 0, handle, TRUE, FALSE); //描画
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

void MyDrawGraph::ChangePos(float a, float b) {
	viewPos->ChangePos(a, b);
}

void MyDrawGraph::ChangeEx(double ExRate) {
	ex = ExRate;
}

MyDrawGraph::~MyDrawGraph() {
	delete viewPos;
	DeleteGraph(handle);
}