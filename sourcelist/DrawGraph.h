#ifndef __DRAWGRAPH_H_INCLUDED__
#define __DRAWGRAPH_H_INCLUDED__

#include "DxLib.h"
#include "Draw.h"
#include <string>

// �摜�֌W
class MyDrawGraph : public Draw{
public:
	MyDrawGraph(const char *fileName); // ������
	MyDrawGraph(const float x, const float y, const char *fileName, const double ExRate = 1.0); // ������
	void ContentView(); // �\��
	void Load();
	void ChangeEx(const double ExRate); // �{���ύX
	double GetEx();
	void ChangeFile(const char *fileName);
	void SetExAnimation(double target_ex, Easing ease = LINER);
	void Update();
	void Release();
protected:
	std::string fileName; // �t�@�C����
	int handle; // �摜�p�n���h��
	double ex; // �\���{��
	double target_ex, default_ex;
	Easing ease_ex;
};

// ����֌W
class MyDrawMovie : public MyDrawGraph {
public:
	MyDrawMovie(const char *filename); // ������
	MyDrawMovie(const float x, const float y, const char *filename, const double ExRate); // ������
	void ContentView(); // �\��
	void Seek(const int flame = -1); // �w�肵���t���[���Ɉړ�
	void Start(); // �Đ�
	void Stop(); // ��~
	void ChangeSpeed(double speed); // �X�s�[�h�ύX
	void SetSpeed(); // �X�s�[�h�Z�b�g
	void SetPart(); // ��ԃZ�b�g
	double GetSpeed(); // �X�s�[�h�擾
	int GetStartFlame(); // �ŏ��̃t���[�����擾
	int GetEndFlame(); // �Ō�̃t���[�����擾
	int GetNowFlame(); // ���݂̃t���[�����擾
	int GetAllFlame(); // ����̃t���[���Y���擾
	void SetStartFlame(const int flame = 0); // �X�^�[�g�t���[���w��
	void SetEndFlame(const int flame = -1); // �G���h�t���[���w��
	~MyDrawMovie();
private:
	double speed, sp;
	int startFlame = 0, endFlame = -1, sf, ef;
};

#endif