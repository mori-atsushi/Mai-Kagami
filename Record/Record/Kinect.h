#ifndef __KINECT_H_INCLUDED__
#define __KINECT_H_INCLUDED__

#include "stdafx.h"
#include <strsafe.h>
#include "DxLib.h"
#include "KinectBody.h"
#include "KinectColor.h"

class Kinect
{
public:
	Kinect(); //コンストラクタ
	void Update(); //更新
	void View(); //描画
	~Kinect(); //デストラクタ
private:
	// Current Kinect
	IKinectSensor *m_pKinectSensor;

	KinectBody *kinectBody;
	KinectColor *kinectColor;
};

#endif