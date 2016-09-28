#ifndef __SONGSELECTCOMMON_H_INCLUDED__
#define __SONGSELECTCOMMON_H_INCLUDED__

#include "DxLib.h"
#include "DrawGraph.h"
#include "CommonText.h"
#include "Touch.h"
#include "SongSelectCover.h"
#include "Songs.h"
#include "SongSelectDefine.h"
#include "Scene.h"
#include "User.h"

// �ȑI����ʃ^�C�g��
class SongSelectTitle : public SubScene {
public:
	SongSelectTitle(Font *font); // ������
	void ContentUpdate(); // �v�Z
	void ContentView(); // �\��
	~SongSelectTitle();
private:
	DrawTitle *title;
	DrawSubtitle *subTitle;
};

// �ȑI����ʃJ�o�[�֌W
class SongInformation : public SubScene {
public:
	SongInformation(Font *font, Songs *songs, Touch *touch, User *user); // ������
	void Load();
	void ContentView(); // �\��
	void ContentUpdate();
	void Delete();
	~SongInformation();
private:
	int n, now;
	User *user;
	Touch *touch;
	SongSelectCover *songCover[256];
	Songs *songs;
	SongSelectCover *nowSong;
	MyDrawGraph *grad[2]; // �J�o�[�摜
// 	MyDrawGraph *box; // �J�o�[�摜
	MyDrawBox *myDrawBox;
	MyDrawText *songLast[2];
};

#endif