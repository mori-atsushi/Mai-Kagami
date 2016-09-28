#ifndef __MAIKAGAMI_H_INCLUDED__
#define __MAIKAGAMI_H_INCLUDED__

#include "TopMain.h"
#include "SongSelectMain.h"
#include "Songs.h"
#include "ThroughMain.h"
#include "ThroughResultMain.h"
#include "PartMain.h"
#include "PartResultMain.h"
#include "Touch.h"
#include "User.h"
#include "Kinect.h"
#include "DxLib.h"

class MaiKagami
{
public:
	MaiKagami(); // �R���X�g���N�^
	void Update(); // �v�Z
	void View(); // �\��
	~MaiKagami(); // �f�X�g���N�^
private:
	MainScene scene; // �V�[��
	Font *font; // �t�H���g
	Top *top; // �g�b�v���
	SongSelect *songSelect; // �ȑI�����
	ThroughMain *throughMain; // �ʂ����K�v���C���
	ThroughResultMain *throughResultMain; // �ʂ����K���ʉ��
	PartMain *partMain; // �������K�v���C���
	PartResultMain *partResultMain; // �������K���ʉ��
	Songs *songs; // �Ȉꗗ
	Touch *touch;
	User *user; // ���[�U�[���
	Kinect *kinect; // �L�l�N�g�֌W
};

#endif