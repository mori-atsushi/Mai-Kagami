#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "TopMain.h"
#include "SongSelectMain.h"
#include "Songs.h"
#include "ThroughMain.h"
#include "Touch.h"
#include "DxLib.h"

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
	ThroughMain *throughMain; //通し練習
	Songs *songs; //曲一覧
	Touch *touch;
};

#endif