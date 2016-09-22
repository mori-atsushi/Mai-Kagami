#ifndef __GRADING_H_INCLUDED__
#define __GRADING_H_INCLUDED__

#include "DxLib.h"
#include <Kinect.h>
#include "Bezier.h"

class Grading {
public:
	Grading();
	void Mark(const char *songFolder);
	~Grading();
protected:
	int total; //総合得点
	char comment[1024]; //コメント
	int point[4]; //部位別得点
	int score[100]; //区間別得点
	int max; //区間別得点の点の数
	int timing; //タイミング
	int expression; //表情
private:
	float JointMark(float joints[24][3], float model[24][3], int x, int y); //2関節間の点数計算
	float FlameMark(float joints[24][3], float model[24][3]); //1フレームあたりの点数計算
	Bezier *bezier;
};

#endif