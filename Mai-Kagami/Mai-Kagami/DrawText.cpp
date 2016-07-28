#include "DrawText.h"

//テキスト初期化
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, char *colorName)
	: Draw(x, y), Color(colorName) {
	s = str; //文字列
	p = pos; //位置情報
	f = font->Get(point); //フォント情報
}

//テキスト表示
void MyDrawText::View() {
	float x = GetX();
	float y = GetY();
	switch (p) {
	case 1:
		x -= GetWidth() / 2;
		break;
	case 2:
		x -= GetWidth();
		break;
	}
	DrawStringToHandle(x, y, s.c_str(), Color::Get(), f); //文字表示
}

//テキスト変更
void MyDrawText::ChangeText(char *str) {
	s = str;
}

//テキストの幅取得
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(s.c_str(), (int)strlen(s.c_str()), f);
}