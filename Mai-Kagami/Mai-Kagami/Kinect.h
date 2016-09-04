#ifndef __KINECT_H_INCLUDED__
#define __KINECT_H_INCLUDED__


#include "stdafx.h"
#include <strsafe.h>
#include "resource.h"
#include "DxLib.h"

class Kinect
{
	static const int        cDepthWidth = 512;
	static const int        cDepthHeight = 424;

public:
	//コンストラクタ
	Kinect();

	//デストラクタ
	~Kinect();
};

#endif