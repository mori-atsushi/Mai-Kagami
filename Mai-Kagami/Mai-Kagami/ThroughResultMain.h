#ifndef __THROUGHRESULTMAIN_H_INCLUDED__
#define __THROUGHRESULTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "ThroughResult.h"
#include "ThroughDetail.h"
#include "ThroughResultDefine.h"
#include "Result.h"
#include <thread>

class ThroughResultMain : public Scene {
public:
	ThroughResultMain(DecorationItem *decorationItem, Touch *touch, Songs *songs, User *user, Kinect *kinect);
	MainScene Switch(const MainScene scene);
	void Load();
	~ThroughResultMain();
private:
	void MarkThread();
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
	ThroughResult *throughResult;
	ThroughDetail *throughDetail;
	Result *result;
	ThroughResultScene scene;
};

#endif