#ifndef __KINECT_H_INCLUDED__
#define __KINECT_H_INCLUDED__


#include "stdafx.h"
#include <strsafe.h>
#include "DxLib.h"
#include "Main.h"

class Kinect
{
public:
	Kinect(); //コンストラクタ
	void Update(); //更新
	boolean CheckDistance(); //距離を測定
	~Kinect(); //デストラクタ
private:
	const float min = 1.0; //最短距離
	Joint userJoints[JointType_Count]; //関節座標情報
	boolean *userFlag; //ユーザーの状態(TRUE:認識されている / FALSE:認識されていない)
	int x;

	// Current Kinect
	IKinectSensor*          m_pKinectSensor;
	ICoordinateMapper*      m_pCoordinateMapper;

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
};

#endif