#include "Loading.h"

//ログイン画面ロード
Loading::Loading() {
	char *str = "ローディング中"; //表示文字列
	myDrawText = new MyDrawText(str, WIDTH / 2, HEIGHT * 0.46, 1, 50);
}

//ログイン画面計算
void Loading::Update() {
}

//ログイン画面表示
void Loading::View() {
	myDrawText->Draw();
}

Loading::~Loading() {
	delete myDrawText;
}