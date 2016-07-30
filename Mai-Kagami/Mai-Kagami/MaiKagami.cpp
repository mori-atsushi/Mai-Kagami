#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	scene = START; //シーン初期化
	font = new Font();
	songs = new Songs(); //曲一覧作成
	top = new Top(font);
	songSelect = new SongSelect(font, songs);
	throughMain = new ThroughMain(font, songs);
}

//全体の算計
void MaiKagami::Update() {
	int now;

	do {
		now = scene;
		switch (scene) {
		case TOP:
			scene = top->Update(); //トップ画面計算
			break;
		case SONG_SELECT:
			scene = songSelect->Update();
			break;
		case THROUGH:
			scene = throughMain->Update();
			break;
		}
	} while (now != scene);
}

//全体の描画
void MaiKagami::View() {
	switch (scene) {
	case TOP:
		top->View(); //トップ画面表示
		break;
	case SONG_SELECT:
		songSelect->View();
		break;
	case THROUGH:
		throughMain->View();
		break;
	}
}