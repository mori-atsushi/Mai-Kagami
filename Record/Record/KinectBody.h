#ifndef __KINECTBODY_H_INCLUDED__
#define __KINECTBODY_H_INCLUDED__

#include <Kinect.h>
#include "DxLib.h"
#include "stdafx.h"

class KinectBody
{
public:
	KinectBody(IKinectSensor *m_pKinectSensor); //コンストラクタ
	void Update(); //更新
	void JointSave(const int flame); //保存
	~KinectBody(); //デストラクタ
private:
	boolean *userFlag; //ユーザーの状態(TRUE:認識されている / FALSE:認識されていない)
	Joint userJoints[JointType_Count];

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;

	FILE *fp;
};

#endif