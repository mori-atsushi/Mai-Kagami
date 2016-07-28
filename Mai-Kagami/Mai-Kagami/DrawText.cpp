#include "DrawText.h"

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

//テキスト変更
void MyDrawText::ChangeText(char *s) {
	str = s;
	viewPos->ChangeLenth(GetWidth() / SIZE_RATE);
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