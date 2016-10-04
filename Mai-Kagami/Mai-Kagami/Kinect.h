#ifndef __KINECT_H_INCLUDED__
#define __KINECT_H_INCLUDED__


#include "stdafx.h"
#include <strsafe.h>
#include "DxLib.h"
#include "Main.h"
#include "KinectBody.h"
//#include "KinectColor.h"

class Kinect
{
public:
	Kinect(); //コンストラクタ
	void Update(); //更新
	~Kinect(); //デストラクタ

	KinectBody *kinectBody; //骨格情報
//	KinectColor *kinectColor; //色情報
private:
	// Current Kinect
	IKinectSensor *m_pKinectSensor;
};

#endif