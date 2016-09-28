#ifndef __TOPMAIN_H_INCLUDED__
#define __TOPMAIN_H_INCLUDED__

#include "Nfc.h"
#include "DxLib.h"
#include "Main.h"
#include "Font.h"
#include "Top.h"
#include "Scene.h"
#include "User.h"

// �g�b�v��ʊ֌W
class Top : public Scene {
public:
	Top(Font *font, User *user);
	MainScene Switch(const MainScene scene);
	~Top();
private:
	Font *f;
	TopLogo *topLogo; // �g�b�v���S
	TopTouchMessage *topTouchMessage; // NFC�^�b�`���b�Z�[�W
	TopTouchButton *topTouchButton; // NFC�^�b�`�{�^��
	Nfc nfc; // NFC�Ď�
	User *user;
	void ContentUpdate(); // �v�Z
	void ContentView(); // �\��
	void ContentLoad();
	void ContentDelete();
};

#endif