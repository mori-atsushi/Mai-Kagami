#include "DrawText.h"

//テキスト初期化
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName)
	: Color(colorName) {
	s = str; //文字列
	p = pos; //位置情報
	f = font->Get(point); //フォント情報
	MyDrawText::x = x;
	MyDrawText::y = y;
	MyDrawText::point = point;
	CalcPos();
}

//テキスト表示
void MyDrawText::View() {
	DrawStringFToHandle(GetX(), GetY(), s.c_str(), Color::Get(), f); //文字表示
}

void MyDrawText::ChangePos(const float x, const float y) {
	MyDrawText::x = x;
	MyDrawText::y = y;
	CalcPos();
}

//テキスト変更
void MyDrawText::ChangeText(char *str) {
	s = str;
	CalcPos();
}

//テキストの縦取得
float MyDrawText::GetHeight() {
	int line = 1; //行数
	for (int i = 0; i < strlen(s.c_str()); i++) {
		if (s.c_str()[i] == '\n')
			line++;
	}

	return (float)point * (1 + 1 / 3) * line;
}

//テキストの幅取得
float MyDrawText::GetWidth() {
	return 	(float)GetDrawStringWidthToHandle(s.c_str(), (int)strlen(s.c_str()), f) * SIZE_RATE;
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

	Draw::ChangePos(a, b - GetHeight() / 2);
}

MyDrawTexts::MyDrawTexts(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineInterval, const char *colorName)
	: Color(colorName) {

	p = pos; //位置情報
	MyDrawTexts::x = x;
	MyDrawTexts::y = y;

	l = 0;
	char a[256];
	for (int i = 0, j = 0; i < strlen(str); i++) {
		a[j++] = str[i];
		if (str[i + 1] == '\n' || i == strlen(str) - 1) {
			a[j] = '\0';
			myDrawText[l] = new MyDrawText(font, a, 0, 0, 0, point, colorName);
			l++;
			i++;
			j = 0;
		}
	}

	CalcPos();
	float height = myDrawText[0]->GetHeight();
	float yy = GetY() * SIZE_RATE - (height + lineInterval) / 2 * (l - 1);
	for (int i = 0; i < l; i++) {
		myDrawText[i]->ChangePos(GetX() * SIZE_RATE, yy);
		yy += (height + lineInterval);
	}
}

void MyDrawTexts::View() {
	for (int i = 0; i < l; i++)
		myDrawText[i]->View();
}

float MyDrawTexts::GetWidth() {
	float max = 0;
	for (int i = 0; i < l; i++) {
		if (max < myDrawText[i]->GetWidth())
			max = myDrawText[i]->GetWidth();
	}
	return max;
}

MyDrawTexts::~MyDrawTexts() {
	for (int i = 0; i < l; i++)
		delete myDrawText;
}

//テキストの座標計算
void MyDrawTexts::CalcPos() {
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

	Draw::ChangePos(a, b);
}

MyDrawTextLine::MyDrawTextLine(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName)
	: MyDrawText(font, str, x, y, pos, point, colorName)  {
	w = lineWidth / SIZE_RATE;
	x1 = (x - lineLength / 2) / SIZE_RATE;
	x2 = (x + lineLength / 2) / SIZE_RATE;
	y1 = y2 = (y + MyDrawText::GetHeight() * 0.9) / SIZE_RATE;
}

void MyDrawTextLine::View() {
	MyDrawText::View();
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}