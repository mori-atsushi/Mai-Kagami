#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "DxLib.h"
#include "Top.h"
//#include "Login.h"
//#include "SongSelect.h"

class MaiKagami
{
public:
	MaiKagami(); //コンストラクタ
	void View(); //表示
private:
	int scene; //シーン
	Top *top; //トップ画面
//	Login login; //ログイン画面
//	SongSelect songSelect; //曲選択画面
};

#endif