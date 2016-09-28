#ifndef __SONGSELECT_H_INCLUDED__
#define __SONGSELECT_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"
#include "DrawObject.h"
#include "Drawtext.h"
#include "Button.h"
#include "Touch.h"
#include "Font.h"
#include "SeetingPop.h"
#include "Scene.h"
#include "SongSelectDefine.h"

// �ȑI����ʃ{�^���֌W
class SongSelectButton : public SubScene{
public:
	SongSelectButton(Font *font, Touch *touch); // ������
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView(); // �\��
	~SongSelectButton();
private:
	Button *button[4];
};

// �I���p�|�b�v�A�b�v
class SongSelectPop : public SubScene {
public:
	SongSelectPop(Font *font, Touch *touch);
	int Switch(const int scene);
	void ContentUpdate();
	void ContentView();
	~SongSelectPop();
private:
	Touch *touch;
	BlackBox *blackBox;
	MyDrawText *title;
	MyDrawText *message;
	Button *button[2];
};

#endif