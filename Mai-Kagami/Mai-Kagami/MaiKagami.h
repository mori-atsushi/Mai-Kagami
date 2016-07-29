#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "DxLib.h"
#include "TopMain.h"
#include "SongSelectMain.h"

class MaiKagami
{
public:
	MaiKagami(); //コンストラクタ
	void Update();
	void View(); //表示
private:
	int scene; //シーン
	Font *font; //フォント
	Top *top; //トップ画面
	SongSelect *songSelect; //曲選択画面
};

#endif