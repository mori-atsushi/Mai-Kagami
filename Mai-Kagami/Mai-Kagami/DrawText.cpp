#include "DrawText.h"

//テキスト初期化
MyDrawText::MyDrawText(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName)
	: Color(colorName) , Draw2(pos) {
	s = str; //文字列
	ChangeFont(font, point);
	MyDrawText::point = point;
	ChangePos(x, y);
}

//テキスト表示
void MyDrawText::View() {
	DrawStringFToHandle(GetX(), GetY(), s.c_str(), Color::Get(), f); //文字表示
}

//テキスト変更
void MyDrawText::ChangeText(char *str) {
	s = str;
	ChangePos(Draw2::x, Draw2::y);
}

//フォントサイズ変更
void MyDrawText::ChangeFont(Font *font, const int point) {
	f = font->Get(point); //フォント情報
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

//テキスト初期化
MyDrawTextV::MyDrawTextV(Font *font, const char *str, const float x, const float y, const int pos, const int point, const char *colorName)
	: MyDrawText(font, str, x, y, pos, point, colorName) {}

void MyDrawTextV::View() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaStringToHandle(GetX(), GetY(), 1, 1, 0, GetHeight() / SIZE_RATE / 2, - 2.0 / 6.0 * 3.141592, Color::Get(), f, -1, FALSE, s.c_str());
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

//複数行のテキスト
MyDrawTexts::MyDrawTexts(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineInterval, const char *colorName)
	: Color(colorName) , Draw2(pos) {

	p = pos; //位置情報
	inter = lineInterval; //間隔

	l = 0;
	char a[256];
	for (int i = 0, j = 0; i < strlen(str); i++) {
		a[j++] = str[i];
		if (str[i + 1] == '\n' || i == strlen(str) - 1) {
			a[j] = '\0';
			myDrawText[l] = new MyDrawText(font, a, 0, 0, 0, point, colorName);
			l++; i++; j = 0;
		}
	}
	ChangePos(x, y);
}

void MyDrawTexts::View() {
	for (int i = 0; i < l; i++)
		myDrawText[i]->View();
}

void MyDrawTexts::ChangePos(const float x, const float y) {
	Draw2::ChangePos(x, y);
	float height = myDrawText[0]->GetHeight();
	float yy = y - (height + inter) / 2 * (l - 1);
	for (int i = 0; i < l; i++) {
		myDrawText[i]->ChangePos(GetX() * SIZE_RATE, yy);
		yy += height + inter;
	}
}

float MyDrawTexts::GetWidth() {
	float max = 0;
	for (int i = 0; i < l; i++) {
		if (max < myDrawText[i]->GetWidth())
			max = myDrawText[i]->GetWidth();
	}
	return max;
}

float MyDrawTexts::GetHeight() {
	return 	myDrawText[0]->GetHeight() * l;
}

MyDrawTexts::~MyDrawTexts() {
	for (int i = 0; i < l; i++)
		delete myDrawText;
}

//アンダーライン付きテキスト
MyDrawTextLine::MyDrawTextLine(Font *font, const char *str, const float x, const float y, const int pos, const int point, const float lineLength, const float lineWidth, const char *colorName)
	: MyDrawText(font, str, x, y, pos, point, colorName)  {
	w = lineWidth / SIZE_RATE;
	x1 = (x - lineLength / 2) / SIZE_RATE;
	x2 = (x + lineLength / 2) / SIZE_RATE;
	y1 = y2 = (y + MyDrawText::GetHeight() * 0.9) / SIZE_RATE;
}

//アンダーライン付きテキスト描画
void MyDrawTextLine::View() {
	MyDrawText::View();
	DrawLineAA(x1, y1, x2, y2, Color::Get(), w);
}