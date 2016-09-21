#include "Main.h"
#include "Kinect.h"
#include "Movie.h"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	SetGraphMode(WIDTH, HEIGHT, 32); //ウィンドウサイズ設定
	SetBackgroundColor(0, 0, 0); //背景色設定
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定
	SetAlwaysRunFlag(TRUE); //バックグラウンドでも処理を実行

	Kinect *kinect = new Kinect();
	Movie *movie = new Movie(WIDTH / 2, HEIGHT / 2, "FILE/test.ogv");

	// while(裏画面を表画面に反映, メッセージ処理, 画面クリア)
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		movie->Start();
		kinect->Update();
//		kinect->View();
		movie->View();
		kinect->kinectBody->JointSave(movie->GetNowFlame()); //保存
	}

	DxLib_End(); // DXライブラリ終了処理

	return 0;
}