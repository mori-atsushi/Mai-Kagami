#include "ModeSelect.h"

//モード選択初期化
ModeSelectButton::ModeSelectButton(Font *font) {
	char *through = "一曲を通して練習できます。\nあなたにあったスピードで練習でき、\n分析・採点が行われます。";
	char *part = "練習区間を設定して集中して練習でき\nます。練習途中であっても、スピード\nの変更や巻き戻しが自由にできます。";
	button[0] = new Button(font, "通し練習モード", through, 0, "Blue");
	button[1] = new Button(font, "部分練習モード", part, 2, "Yellow");
	button[2] = new Button(font, "戻る", 3, 4);
}

//モード選択ボタン表示
void ModeSelectButton::View() {
	for (int i = 0; i < 3; i++)
		button[i]->Draw();
}

//モード選択削除
ModeSelectButton::~ModeSelectButton() {
	for (int i = 0; i < 3; i++)
		delete button[i];
}