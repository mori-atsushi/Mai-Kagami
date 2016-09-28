#ifndef __PAUSESCREEN_H_INCLUDED__
#define __PAUSESCREEN_H_INCLUDED__

#include "DxLib.h"
#include "Button.h"
#include "Font.h"
#include "Songs.h"
#include "SeetingPop.h"
#include "Touch.h"
#include "Scene.h"

// �|�[�Y���
class PauseScreen : public SubScene {
public:
	PauseScreen(Font *font, Songs *songs, Touch *touch, const int pauseScene, const int startScene, const int songSelectScene, const int settingScene);
	void Load();
	int Switch(const int scene);
	void Delete();
	~PauseScreen();
private:
	void ContentUpdate();
	void ContentView();
	int pauseScene,  startScene, songSelectScene, settingScene;
	Songs *songs;
	BlackBox *blackBox; // �w�i���������̎l�p�`
	MyDrawText *title;
	CircleGraphTextButton *button[4];
};

#endif