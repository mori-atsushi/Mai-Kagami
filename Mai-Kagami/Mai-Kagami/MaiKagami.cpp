#include "MaiKagami.h"

MaiKagami::MaiKagami() {
	touch = new Touch();
	font = new Font();
	songs = new Songs(font); //曲一覧作成
	top = new Top(font);
	songSelect = new SongSelect(font, touch, songs);
	throughMain = new ThroughMain(font, touch, songs);
	throughResultMain = new ThroughResultMain(font, touch, songs);
	partMain = new PartMain(font, touch, songs);
	scene = TOP;
}

//全体の算計
void MaiKagami::Update() {
	touch->Check();
	switch (scene) {
	case TOP:
		scene = top->Switch(scene);
		break;
	case SONG_SELECT:
		scene = songSelect->Switch(scene);
		break;
	case THROUGH:
		scene = throughMain->Switch(scene);
		break;
	case THROUGH_RESULT:
		scene = throughResultMain->Switch(scene);
		break;
	case PART:
		scene = partMain->Switch(scene);
		break;
	}

	top->Update(scene); //トップ画面計算
	songSelect->Update(scene); //曲選択画面計算
	throughMain->Update(scene); //通し練習プレイ画面計算
	throughResultMain->Update(scene); //通し練習結果画面計算
	partMain->Update(scene); //部分練習プレイ画面計算
}

//全体の描画
void MaiKagami::View() {
	top->View(); //トップ画面表示
	songSelect->View(); //曲選択画面表示
	throughMain->View(); //通し練習プレイ画面表示
	throughResultMain->View(); //通し練習結果画面表示
	partMain->View(); //部分練習プレイ画面表示
}

//デストラクタ
MaiKagami::~MaiKagami() {
	delete top;
	delete songSelect;
	delete throughMain;
	delete throughResultMain;
	delete partMain;
}