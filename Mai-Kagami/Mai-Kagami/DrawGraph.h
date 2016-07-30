#ifndef __DRAWGRAPH_H_INCLUDED__
#define __DRAWGRAPH_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include <string>

//画像関係
class MyDrawGraph : public Draw{
public:
	MyDrawGraph(const char *fileName); //初期化
	MyDrawGraph(const float x, const float y, const char *fileName, const double ExRate = 1.0); //初期化
	void View(); //表示
	void Load();
	void ChangeEx(const double ExRate); //倍率変更
	void Release();
protected:
	std::string fileName; //ファイル名
	int handle; //画像用ハンドル
	double ex; //表示倍率
};

//動画関係
class MyDrawMovie : public MyDrawGraph {
public:
	MyDrawMovie(const char *filename); //初期化
	MyDrawMovie(const float x, const float y, const char *filename, const double ExRate); //初期化
	void View(); //表示
	void Stop(); //停止
	void ChangeSpeed(double speed); //スピード変更
	~MyDrawMovie();
private:
};

#endif