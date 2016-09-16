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
	~KinectBody(); //デストラクタ
private:
	int *userNum;
	boolean *userFlag; //ユーザーの状態(TRUE:認識されている / FALSE:認識されていない)

					   // Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
};

#endif