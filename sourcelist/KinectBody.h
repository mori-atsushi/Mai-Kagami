#ifndef __KINECTBODY_H_INCLUDED__
#define __KINECTBODY_H_INCLUDED__

#include <Kinect.h>
#include "DxLib.h"
#include "stdafx.h"
#include "Main.h"

class KinectBody
{
public:
	KinectBody(IKinectSensor *m_pKinectSensor); // �R���X�g���N�^
	void Update(); // �X�V
	boolean CheckDistance(); // �����𑪒�
	void StartSave(const char *fileName);
	void JointSave(const int flame); // �ۑ�
	void FinishSave();
	~KinectBody(); // �f�X�g���N�^
private:
	Joint userJoints[JointType_Count]; // �֐ߍ��W���
	boolean *userFlag; // ���[�U�[�̏��(TRUE:�F������Ă��� / FALSE:�F������Ă��Ȃ�)

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
	FILE *fp;
};

#endif