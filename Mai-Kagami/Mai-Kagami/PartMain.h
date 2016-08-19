#ifndef __PARTMAIN_H_INCLUDED__
#define __PARTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "Scene.h"
#include "Main.h"
#include "Font.h"
#include "Songs.h"
#include "Touch.h"

class PartMain : public Scene {
public:
	PartMain(Font *font, Touch *touch, Songs *songs);
	MainScene Switch(const MainScene scene);
	~PartMain();
private:
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
};

#endif