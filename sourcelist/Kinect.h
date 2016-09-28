#ifndef __KINECT_H_INCLUDED__
#define __KINECT_H_INCLUDED__


#include "stdafx.h"
#include <strsafe.h>
#include "DxLib.h"
#include "Main.h"
#include "KinectBody.h"
// #include "KinectColor.h"

class Kinect
{
public:
	Kinect(); // �R���X�g���N�^
	void Update(); // �X�V
	~Kinect(); // �f�X�g���N�^

	KinectBody *kinectBody; // ���i���
// 	KinectColor *kinectColor; // �F���
private:
	// Current Kinect
	IKinectSensor *m_pKinectSensor;
};

#endif