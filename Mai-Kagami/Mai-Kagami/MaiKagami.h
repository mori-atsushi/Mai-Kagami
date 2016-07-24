#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "DxLib.h"
#include "Top.h"
#include "Loading.h"
#include "SongSelect.h"

class MaiKagami
{
public:
	MaiKagami(); //コンストラクタ
	void Update();
	void View(); //表示
private:
	int scene; //シーン
	Top *top; //トップ画面
	Loading *loading; //ローディング画面
	SongSelect *songSelect; //曲選択画面
};

#endif