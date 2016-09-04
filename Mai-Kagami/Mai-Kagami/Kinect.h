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
	Kinect(); //コンストラクタ
	HRESULT Connect(); //接続
	~Kinect(); //デストラクタ
private:
	double                  m_fFreq;

	// Current Kinect
	IKinectSensor*          m_pKinectSensor;
	ICoordinateMapper*      m_pCoordinateMapper;

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
};

#endif