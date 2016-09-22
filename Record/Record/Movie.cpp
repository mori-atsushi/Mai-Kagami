#include "Movie.h"

//動画初期化
Movie::Movie(const float x, const float y, const char *filename) {
	this->x = x;
	this->y = y;
	handle = LoadGraph(filename); // 画像のロード
}

//動画表示
void Movie::View() {
	if (!CheckHandleASyncLoad(handle)) {
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		DrawRotaGraphF(x, y, 1, 0, handle, TRUE); //描画
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}

//再生
void Movie::Start() {
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && GetMovieStateToGraph(handle) == 0)
		PlayMovieToGraph(handle);
}

//現在のフレーム数取得
int Movie::GetNowFlame() {
	return TellMovieToGraphToFrame(handle);
}

Movie::~Movie() {
	DeleteGraph(handle);
}