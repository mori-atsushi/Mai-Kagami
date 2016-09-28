#ifndef __SONG_H_INCLUDED__
#define __SONG_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include "DrawGraph.h"
#include "DrawText.h"
#include "Font.h"

// ����
class SongHistory {
public:
	void Set(const int history[2]); // �����Z�b�g
	void Get(int *history[2]); // �����擾
private:
	int history[2] = { -1, -1 }; // ��ID,
};

// �Ȗ��A�A�[�e�B�X�g���
class DrawSongTitle : public Pos {
public:
	DrawSongTitle(Font *font, const char *title, const char *artist);
	void ChangePos(const float x, const float y);
	void View();
	~DrawSongTitle();
private:
	MyDrawTextLine *songTitle; // �Ȗ��\��
	MyDrawText *songArtist; // �A�[�e�B�X�g�\��
};

// �p�[�g���
class SongPart {
public:
	void Set(const int flame, const char *name);
	int GetFlame(); // �t���[�����擾
	char *GetName(); // �p�[�g���擾
private:
	int flame;
	char name[256]; // ����
};

class Song {
public:
	Song(Font *font, const int id, const char *title, const char *artist, const char *folder);
	int GetSongId(); // ��ID���擾
	int GetNow(); // ���݂̈ʒuID���擾
	void SetNow(const int n); // �ʒuID���Z�b�g
	void ChangeSpeed(int num); // ����̍Đ����x�ύX
	void ChangeStart(int num); // ����̊J�n�ʒu�ύX
	void ChangeEnd(int num); // ����̏I���ʒu�ύX
	int StartPart();
	int EndPart();
	void LoadPart(); // �p�[�g��񃍁[�h
	SongPart *GetPart(int num); // �p�[�g���擾
	int GetPartNum(); // �p�[�g���擾
	char *GetFolder(); // �t�H���_�擾
	DrawSongTitle *drawSongTitle; // �Ȗ��A�A�[�e�B�X�g�\��
	MyDrawGraph *coverGraph; // �J�o�[�摜
	MyDrawGraph *coverWhite; // �J�o�[�摜�̔w�i�̔�
	MyDrawMovie *danceMovie; // ����
	SongHistory *songHistory;
protected:
	char music[256], folder[256]; // ���y�t�@�C���A�t�H���_
private:
	int id, *n, *songPartNum, *start, *end; // ID�A���݂̔ԍ�, �Ȑ��A�J�n�A�I��
	SongPart *songPart[256];
};

#endif