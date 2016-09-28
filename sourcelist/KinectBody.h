#ifndef __KINECTBODY_H_INCLUDED__
#define __KINECTBODY_H_INCLUDED__

#include <Kinect.h>
#include "DxLib.h"
#include "stdafx.h"
#include "Main.h"

class KinectBody
{
public:
	KinectBody(IKinectSensor *m_pKinectSensor); // コンストラクタ
	void Update(); // 更新
	boolean CheckDistance(); // 距離を測定
	void StartSave(const char *fileName);
	void JointSave(const int flame); // 保存
	void FinishSave();
	~KinectBody(); // デストラクタ
private:
	Joint userJoints[JointType_Count]; // 関節座標情報
	boolean *userFlag; // ユーザーの状態(TRUE:認識されている / FALSE:認識されていない)

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;
	FILE *fp;
};

#endif