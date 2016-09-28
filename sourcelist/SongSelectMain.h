#ifndef __SONGSELECTMAIN_H_INCLUDED__
#define __SONGSELECTMAIN_H_INCLUDED__

#include "DxLib.h"
#include "ModeSelect.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "Font.h"
#include "SongSelectCommon.h"
#include "SongSelect.h"
#include "SongSelectDefine.h"
#include "ThroughOption.h"
#include "PartOption.h"
#include "Scene.h"
#include "User.h"

// �ȑI����ʊ֌W
class SongSelect : public Scene{
public:
	SongSelect(Font *font, Touch *touch, Songs *songs, User *user);
	MainScene Switch(const MainScene scene);
	void SetScene(const int scene);
	~SongSelect();
private:
	SongSelectTitle *songSelectTitle; // �ȑI����ʃ^�C�g��
	SongInformation *songInformation; // �I�𒆂̋�
	SongSelectButton *songSelectButton; // �{�^���֌W
	SongSelectPop *songSelectPop; // �I���p�|�b�v�A�b�v
	ModeSelectButton *modeSelectButton; // ���[�h�I���{�^��
	ThroughOptionButton *throughOptionButton; // �ʂ����K�I�v�V�����{�^��
	PartOptionButton *partOptionButton; // �������K�I�v�V�����{�^��
	int scene = MAIN;;
	void ContentLoad();
	void ContentUpdate();
	void ContentView();
	void ContentDelete();
};

#endif