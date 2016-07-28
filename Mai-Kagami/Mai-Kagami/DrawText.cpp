#include "DrawText.h"

//テキスト初期化
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName)
	: Color(colorName) {
	s = str; //文字列
	p = pos; //位置情報
	f = font->Get(point); //フォント情報
	MyDrawText::x = x;
	MyDrawText::y = y;
	CalcPos();
}

//テキスト表示
void MyDrawText::View() {
	DrawStringToHandle(GetX(), GetY(), s.c_str(), Color::Get(), f); //文字表示
}

//テキスト変更
void MyDrawText::ChangeText(char *str) {
	s = str;
	CalcPos();
}

//テキストの幅取得
int MyDrawText::GetWidth() {
	return 	GetDrawStringWidthToHandle(s.c_str(), (int)strlen(s.c_str()), f) * SIZE_RATE;
}

//テキストの座標計算
void MyDrawText::CalcPos() {
	float a = x;
	float b = y;
	switch (p) {
	case 1:
		a -= GetWidth() / 2;
		break;
	case 2:
		a -= GetWidth();
		break;
	}

	int line = 1; //行数
	for (int i = 0; i < strlen(s.c_str()); i++) {
		if (s[i] == '\n')
			line++;
	}

	ChangePos(a, b - p * (1 + 1 / 3) * line / 2);
}