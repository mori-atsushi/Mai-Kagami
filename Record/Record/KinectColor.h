#ifndef __KINECTCOLOR_H_INCLUDED__
#define __KINECTCOLOR_H_INCLUDED__

#include "Main.h"
#include <Kinect.h>
#include <opencv2/opencv.hpp>
#include "DxLib.h"
#include "stdafx.h"

class KinectColor
{
public:
	KinectColor(IKinectSensor *m_pKinectSensor); //コンストラクタ
	void Update(); //更新
	void View();
	~KinectColor(); //デストラクタ
private:
	int *width, *height; //映像の縦横ピクセル
	unsigned int *bufferSize; //映像サイズ
	cv::Mat *bufferMat;
	cv::Mat *colorMat;
	int handle; //グラフィックハンドル
	BASEIMAGE baseImage;
	IColorFrameReader* m_pColorFrameReader;
};

#endif