#ifndef __THROUGHRESULTMAIN_H_INCLUDED__
#define __THROUGHRESULTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "ThroughResult.h"
#include "ThroughDetail.h"
#include "ThroughResultDefine.h"

class ThroughResultMain : public Scene {
public:
	ThroughResultMain(Font *font, Touch *touch, Songs *songs);
	MainScene Switch(const MainScene scene);
	~ThroughResultMain();
private:
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
	ThroughResult *throughResult;
	ThroughDetail *throughDetail;
	ThroughResultScene scene;
};

#endif