#include "CommonText.h"

//タイトル表示用
DrawTitle::DrawTitle(DecorationItem *decorationItem, const char *str) 
	: MyDrawTextLine(decorationItem, str, WIDTH * 0.65, HEIGHT * 0.21, 1, 50, WIDTH * 0.4, 3) {}

//サブタイトル表示用
DrawSubtitle::DrawSubtitle(DecorationItem *decorationItem, const char *str)
	: MyDrawText(decorationItem, str, WIDTH * 0.65, HEIGHT * 0.25, 1, 30) {}