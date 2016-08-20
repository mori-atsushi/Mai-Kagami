#include "DrawGraph.h"


//画像初期化
MyDrawGraph::MyDrawGraph(const char *fileName) {
	ex = 1.0;
	MyDrawGraph::fileName = fileName;
}
//画像初期化
MyDrawGraph::MyDrawGraph(const float x, const float y, const char *fileName, const double ExRate) : Draw(x, y) {
	ex = ExRate;
	MyDrawGraph::fileName = fileName;
}

void MyDrawGraph::Load() {
	handle = LoadGraph(fileName.c_str()); // 画像のロード
}

//画像表示
void MyDrawGraph::ContentView() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(x, y, ex / SIZE_RATE, 0, handle, TRUE, FALSE); //描画
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

//大きさ変更
void MyDrawGraph::ChangeEx(const double ExRate) {
	ex = ExRate;
}

//画像を解放
void MyDrawGraph::Release() {
	DeleteGraph(handle);
}

//動画初期化
MyDrawMovie::MyDrawMovie(const char *filename) : MyDrawGraph(filename) {
	speed = sp = 1.0;
}

//動画初期化
MyDrawMovie::MyDrawMovie(const float x, const float y, const char *filename, const double ExRate)
	: MyDrawGraph(x, y, filename, ExRate) {
	speed = sp = 1.0;
}

//動画表示
void MyDrawMovie::ContentView() {
	if (!CheckHandleASyncLoad(handle)) {
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		DrawRotaGraphF(x, y, ex / SIZE_RATE, 0, handle, TRUE, TRUE); //描画
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}

//指定したフレームに移動
void MyDrawMovie::Seek(const int flame) {
	Stop();
	SeekMovieToGraphToFrame(handle, flame);
}

//再生
void MyDrawMovie::Start() {
	if (!CheckHandleASyncLoad(handle)) {
		SetSpeed();
		if (GetNowFlame() == GetAllFlame())
			Seek();
		if(GetMovieStateToGraph(handle) == 0)
			PlayMovieToGraph(handle);
	}
}

//再生停止
void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

//スピード変更
void MyDrawMovie::ChangeSpeed(double speed) {
	MyDrawMovie::sp = speed;
}

//スピードセット
void MyDrawMovie::SetSpeed() {
	if (speed != sp) {
		Stop();
		Seek();
		speed = sp;
		SetPlaySpeedRateMovieToGraph(handle, speed);
	}
}

//スピード取得
double MyDrawMovie::GetSpeed() {
	return sp;
}

int MyDrawMovie::GetNowFlame() {
	return TellMovieToGraphToFrame(handle);
}

int MyDrawMovie::GetAllFlame() {
	return GetMovieTotalFrameToGraph(handle) - 1;
}

MyDrawMovie::~MyDrawMovie() {
	DeleteGraph(handle);
}