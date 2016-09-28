#ifndef __GRADING_H_INCLUDED__
#define __GRADING_H_INCLUDED__

#include "DxLib.h"
#include <Kinect.h>
#include "Bezier.h"

class FlameGrading {
public:
	FlameGrading(FILE *modelfp);
	int Mark(float joints[JointType_Count][3], const int userflmae);
private:
	float JointMark(float joints[JointType_Count][3], float model[JointType_Count][3], int x, int y); // 2�֐ߊԂ̓_���v�Z
	float FlameMark(float joints[JointType_Count][3], float model[JointType_Count][3]); // 1�t���[��������̓_���v�Z
	FILE *modelfp;
	int modelflame, j;
	float model[JointType_Count][3];
};

class Grading {
public:
	Grading();
	void Mark(const char *model, const char *user);
	~Grading();
protected:
	int total; // �������_
	char comment[1024]; // �R�����g
	int point[4]; // ���ʕʓ��_
	int score[100] = {}; // ��ԕʓ��_
	int max; // ��ԕʓ��_�̓_�̐�
	int timing; // �^�C�~���O
	int expression; // �\��
private:
	int Adjust(int point); // �_����0~100�͈̔͂ɂȂ�悤�ɒ���
	Bezier *bezier;
};

#endif