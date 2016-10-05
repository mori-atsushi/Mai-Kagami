#ifndef __GRADING_H_INCLUDED__
#define __GRADING_H_INCLUDED__

#include "DxLib.h"
#include <Kinect.h>
#include <map>
#include "Bezier.h"
#include "Main.h"

typedef float flameData[JointType_Count][3];

class FlameGrading {
public:
	FlameGrading(std::map <int, flameData> modelData);
	int Mark(float joints[JointType_Count][3], const int userflame);
	int *MarkPoint(float joints[JointType_Count][3], const int userflame);
private:
	float JointMark(float joints[JointType_Count][3], float model[JointType_Count][3], int x, int y); //2関節間の点数計算
	float FlameMark(float joints[JointType_Count][3], float model[JointType_Count][3]); //1フレームあたりの点数計算
	float LeftHandMark(float joints[JointType_Count][3], float model[JointType_Count][3]); //1フレームあたりの左手点数計算
	float RightHandMark(float joints[JointType_Count][3], float model[JointType_Count][3]); //1フレームあたりの右手点数計算
	float LeftFootMark(float joints[JointType_Count][3], float model[JointType_Count][3]); //1フレームあたりの左足点数計算
	float RightFootMark(float joints[JointType_Count][3], float model[JointType_Count][3]); //1フレームあたりの右足点数計算
	std::map <int, flameData> modelData;
	int modelflame, j;
	float model[JointType_Count][3];
};

class Grading {
public:
	Grading();
	void Mark(const char *model, std::map <int, flameData> userData, const int userflame);
	~Grading();
protected:
	int total; //総合得点
	char comment[1024]; //コメント
	int point[4] = {}; //部位別得点
	int score[100] = {}; //区間別得点
	int max = 0; //区間別得点の点の数
	int timing = 0; //タイミング
	int expression = 0; //表情
	int partScore[100];	//区間別得点
private:
	int Adjust(int point); //点数が0~100の範囲になるように調整
	void Copy(float dst[JointType_Count][3], float source[JointType_Count][3]);
	Bezier *bezier;
};

#endif