#ifndef __SCENE_H_INCLUDED__
#define __SCENE_H_INCLUDED__

#include "DxLib.h"
#include "Main.h"

// �T�u��ʒ�`
class SubScene {
public:
	void Update(const int scene); // �X�V
	void View(); // �\��
	void Load(); // ���[�h
	void Delete(); // �폜
	boolean CheckView(); // �\�������ǂ����m�F����(TRUE:�\�����AFALSE�F��\����)
protected:
	int nowScene;
	boolean viewFlag = FALSE; // �\���p�t���O(TRUE:�\���AFALSE�F��\��)
	virtual void ContentView() = 0; // �\���ڍ�
	virtual void ContentUpdate() = 0; // �X�V�ڍ�
};

// ��ʒ�`
class Scene : public SubScene {
protected:
	void Load(); // ���[�h
	void Delete(); // �폜
private:
	virtual void ContentLoad() = 0; // ���[�h�ڍ�
	virtual void ContentDelete() = 0; // �폜�ڍ�
	int loadFlag = 0; // ���[�h�m�F�p�i0�F�����[�h�A1�F���[�h���A2�F���[�h�����j
};

#endif