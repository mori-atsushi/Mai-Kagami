#ifndef __DRAWGRAPH_H_INCLUDED__
#define __DRAWGRAPH_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"

//画像関係
class MyDrawGraph {
public:
	MyDrawGraph(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	~MyDrawGraph();
private:
	ViewPos *viewPos;
	int handle;
	double ex;
};

//動画関係
class MyDrawMovie {
public:
	MyDrawMovie(float a, float b, char *filename, double ExRate = 1.0);
	void Draw();
	void Stop();
	void ChangePos(float a, float b);
	void ChangeEx(double ExRate);
	void ChangeSpeed(double speed);
	~MyDrawMovie();
private:
	ViewPos *viewPos;
	int handle; //動画のハンドル
	double ex; //動画のサイズ
};

#endif