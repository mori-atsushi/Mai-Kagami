#ifndef __PAUSESCREEN_H_INCLUDED__
#define __PAUSESCREEN_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "DecorationItem.h"
#include "Songs.h"
#include "SeetingPop.h"
#include "Touch.h"
#include "Scene.h"

//É|Å[ÉYâÊñ 
class PauseScreen : public SubScene {
public:
	PauseScreen(DecorationItem *decorationItem, Songs *songs, Touch *touch, const int pauseScene, const int startScene, const int songSelectScene, const int settingScene);
	void Load();
	int Switch(const int scene);
	void Delete();
	~PauseScreen();
private:
	void ContentUpdate();
	void ContentView();
	int pauseScene,  startScene, songSelectScene, settingScene;
	DecorationItem *decorationItem;
	Songs *songs;
	BlackBox *blackBox; //îwåiîºìßñæçïÇÃéläpå`
	MyDrawText *title;
	CircleGraphTextButton *button[4];
};

#endif