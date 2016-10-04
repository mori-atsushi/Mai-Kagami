#ifndef __KINECTBODY_H_INCLUDED__
#define __KINECTBODY_H_INCLUDED__

#include "DxLib.h"
#include "stdafx.h"
#include "Main.h"
#include "Grading.h"
#include <map>

class KinectBody
{
public:
	KinectBody(IKinectSensor *m_pKinectSensor); //コンストラクタ
	void Update(); //更新
	boolean CheckDistance(); //距離を測定
	void JointSave(const int flame); //保存
	void DeleteSave(const int flame = 0); //指定したflameまでのデータを削除
	std::map <int, flameData> GetSave();
	int GetHappy();
	int GetNow();
	~KinectBody(); //デストラクタ
private:
	std::map <int, flameData> userData;
	Joint userJoints[JointType_Count]; //関節座標情報
	boolean *userFlag; //ユーザーの状態(TRUE:認識されている / FALSE:認識されていない)
	int happyFace, happySum, happyNum;
	int now = 0;

	// Body reader
	IBodyFrameReader*       m_pBodyFrameReader;

	// Face readers
	IFaceFrameReader*	   m_pFaceFrameReaders[BODY_COUNT];
	// Face sources
	IFaceFrameSource*	   m_pFaceFrameSources[BODY_COUNT];
};

#endif