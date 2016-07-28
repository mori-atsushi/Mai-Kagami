#include "DrawGraph.h"

//画像初期化
MyDrawGraph::MyDrawGraph(const float x, const float y, const char *filename, const double ExRate) : Draw(x, y) {
	handle = LoadGraph(filename); // 画像のロード
	ex = ExRate;
}

//画像表示
void MyDrawGraph::View() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(GetX(), GetY(), ex / SIZE_RATE, 0, handle, TRUE, FALSE); //描画
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

//大きさ変更
void MyDrawGraph::ChangeEx(const double ExRate) {
	ex = ExRate;
}

MyDrawGraph::~MyDrawGraph() {
	DeleteGraph(handle);
}

//動画初期化
MyDrawMovie::MyDrawMovie(const float x, const float y, const char *filename, const double ExRate)
	: MyDrawGraph(x, y, filename, ExRate) {
}

//動画表示
void MyDrawMovie::View() {
	if (!CheckHandleASyncLoad(handle)) {
		if (GetMovieStateToGraph(handle) == 0) {
			SetPlaySpeedRateMovieToGraph(handle, 1.0);
			SeekMovieToGraph(handle, 0);
			PlayMovieToGraph(handle);
		}
		MyDrawGraph::View();
	}
}

//再生停止
void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

//スピード変更
void MyDrawMovie::ChangeSpeed(double speed) {
	PauseMovieToGraph(handle);
	SetPlaySpeedRateMovieToGraph(handle, speed);
	SeekMovieToGraph(handle, 0);
	PlayMovieToGraph(handle);
}

MyDrawMovie::~MyDrawMovie() {
	DeleteGraph(handle);
}