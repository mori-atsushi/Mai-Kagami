#ifndef __GRADING_H_INCLUDED__
#define __GRADING_H_INCLUDED__

#include "DxLib.h"
#include <Kinect.h>
#include "Bezier.h"
#include <map>

typedef float flameData[JointType_Count][3];

class FlameGrading {
public:
	FlameGrading(std::map <int, flameData> modelData);
	int Mark(float joints[JointType_Count][3], const int userflmae);
private:
	float JointMark(float joints[JointType_Count][3], float model[JointType_Count][3], int x, int y); //2関節間の点数計算
	float FlameMark(float joints[JointType_Count][3], float model[JointType_Count][3]); //1フレームあたりの点数計算
	std::map <int, flameData> modelData;
	int modelflame, j;
	float model[JointType_Count][3];
};

class Grading {
public:
	Grading();
	void Mark(const char *model, const char *user);
	~Grading();
protected:
	int total; //総合得点
	char comment[1024]; //コメント
	int point[4]; //部位別得点
	int score[100] = {}; //区間別得点
	int max; //区間別得点の点の数
	int timing; //タイミング
	int expression; //表情
private:
	int Adjust(int point); //点数が0~100の範囲になるように調整
	void Copy(float dst[JointType_Count][3], float source[JointType_Count][3]);
	Bezier *bezier;
};

#endif