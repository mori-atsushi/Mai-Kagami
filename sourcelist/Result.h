#ifndef __RESULT_H_INCLUDED__
#define __RESULT_H_INCLUDED__

#include "DxLib.h"
#include "Songs.h"
#include "User.h"
#include "Grading.h"

class Result : public Grading {
public:
	Result(Songs *songs, User *user);
	void Calc(); // ���_�v�Z
	void Send(); // ���M
	float GetTotal(); // �������_�擾
	void GetPoint(int x[4]); // ���ʕʓ��_�擾
	char *GetComment(); // �R�����g�擾
	int GetTiming(); // �^�C�~���O�擾
	int GetExpression(); // �\��擾
	int GetScore(int x[100]); // ��ԕʓ��_�擾
private:
	Songs *songs;
	User *user;
};

#endif