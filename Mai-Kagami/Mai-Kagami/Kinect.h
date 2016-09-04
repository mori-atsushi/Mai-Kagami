#ifndef __KINECT_H_INCLUDED__
#define __KINECT_H_INCLUDED__


#include "stdafx.h"
#include <strsafe.h>
#include "DxLib.h"
#include "Main.h"

class Kinect
{
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;

public:
	Kinect(); //コンストラクタ
	void Update(); //更新
	~Kinect(); //デストラクタ
private:
	Joint userJoints[JointType_Count]; //関節座標情報
	boolean userFlag; //ユーザーの状態(TRUE:認識されている / FALSE:認識されていない)

	// Current Kinect
	IKinectSensor*          m_pKinectSensor;
	ICoordinateMapper*      m_pCoordinateMapper;

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
};

#endif