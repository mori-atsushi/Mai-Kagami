#include "DxLib.h"

//動画関係
class Movie {
public:
	Movie(const float x, const float y, const char *filename); //初期化
	void View();
	void Start(); //再生
	int GetNowFlame(); //現在のフレーム数取得

	~Movie();
private:
	double speed, sp;
	float x, y;
	int handle; //画像用ハンドル
};