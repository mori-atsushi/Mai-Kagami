#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include <thread>
#include <Windows.h>
#include "DxLib.h"
#include "Main.h"
#include "Draw.h"

//曲選択画面タイトル
class SongSelectTitle {
public:
	void Init(); //初期化
	void View(); //表示
private:
	int logo; //画像ID
	char *str; //文字
	int x, y; //表示位置
	Font font; //フォント
};

//曲選択画面関係
class SongSelect {
public:
	int Load();
	void Update();
	void View();
private:
	void LoadThread(); //ロードスレッド
	SongSelectTitle songSelectTitle; //曲選択画面タイトル
	int loadFlag;
};

#endif