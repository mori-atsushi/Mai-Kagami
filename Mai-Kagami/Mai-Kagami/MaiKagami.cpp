#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //シーン初期化
//	login.Load();
	top = new Top();
}

//全体の計算と描画
void MaiKagami::View() {
	switch (scene) {
	case TOP:
		scene = top->Update(); //トップ画面計算
		top->View(); //トップ画面表示
		break;
/*	case LOGIN:
		login.Update();
		scene = songSelect.Load();
		login.View();
		break;
	case SONG_SELECT:
		scene = songSelect.Update();
		songSelect.View();*/
	}
}