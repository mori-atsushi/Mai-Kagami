#include "DrawGraph.h"


// �摜������(���W�w��Ȃ��A���Ƃ���w�肷��ꍇ)
// MyDrawGraph�i�t�@�C�����j
MyDrawGraph::MyDrawGraph(const char *fileName) {
	ex = 1.0;
	this->fileName = fileName;
}

// �摜������
// MyDrawGraph�ix���W�Ay���W�A�t�@�C�����A�g�嗦�j // �g�嗦�͏ȗ��\�A�ȗ������ꍇ���{
MyDrawGraph::MyDrawGraph(const float x, const float y, const char *fileName, const double ExRate) : Draw(x, y) {
	ex = ExRate;
	this->fileName = fileName;
}

// �t�@�C�����ύX
void MyDrawGraph::ChangeFile(const char *fileName) {
	this->fileName = fileName;
}

// �摜���[�h
void MyDrawGraph::Load() {
	handle = LoadGraph(fileName.c_str()); // �摜�̃��[�h
}

// �摜�\��
void MyDrawGraph::ContentView() {
	SetDrawMode(DX_DRAWMODE_BILINEAR);
	DrawRotaGraphF(x, y, ex / SIZE_RATE, 0, handle, TRUE, FALSE); // �`��
	SetDrawMode(DX_DRAWMODE_NEAREST);
}

// �摜�傫���ύX
void MyDrawGraph::ChangeEx(const double ExRate) {
	ex = ExRate;
}
// �摜�傫���擾
double MyDrawGraph::GetEx() {
	return ex;
}

void MyDrawGraph::SetExAnimation(double target_ex, Easing ease) {
	if (GetTime() != 0)
		return;
	default_ex = GetEx();
	this->target_ex = target_ex;
	ease_ex = ease;
}

void MyDrawGraph::Update() {
	double r = UpdateRate(ease_ex);
	float nex = default_ex + (target_ex - default_ex) * r;
	ChangeEx(nex);
	Draw::Update();
}

// �摜�����
void MyDrawGraph::Release() {
	DeleteGraph(handle);
}

// ���揉����
MyDrawMovie::MyDrawMovie(const char *filename) : MyDrawGraph(filename) {
	speed = sp = 1.0;
}

// ���揉����
MyDrawMovie::MyDrawMovie(const float x, const float y, const char *filename, const double ExRate)
	: MyDrawGraph(x, y, filename, ExRate) {
	speed = sp = 1.0;
}

// ����\��
void MyDrawMovie::ContentView() {
	if (!CheckHandleASyncLoad(handle)) {
		SetDrawMode(DX_DRAWMODE_BILINEAR);
		DrawRotaGraphF(x, y, ex / SIZE_RATE, 0, handle, TRUE, TRUE); // �`��
		SetDrawMode(DX_DRAWMODE_NEAREST);
	}
}

// �w�肵���t���[���Ɉړ�
void MyDrawMovie::Seek(const int flame) {
	Stop();
	if(flame == -1)
		SeekMovieToGraphToFrame(handle, startFlame);
	else
		SeekMovieToGraphToFrame(handle, flame);
}

// �Đ�
void MyDrawMovie::Start() {
	if (!CheckHandleASyncLoad(handle)) {
		SetSpeed();
		if (GetNowFlame() == GetEndFlame())
			Seek();
		if(GetMovieStateToGraph(handle) == 0)
			PlayMovieToGraph(handle);
	}
}

// �Đ���~
void MyDrawMovie::Stop() {
	PauseMovieToGraph(handle);
}

// �X�s�[�h�ύX
void MyDrawMovie::ChangeSpeed(double speed) {
	this->sp = speed;
}

// �X�s�[�h�Z�b�g
void MyDrawMovie::SetSpeed() {
	if (speed != sp) {
		Stop();
		Seek();
		speed = sp;
		SetPlaySpeedRateMovieToGraph(handle, speed);
	}
}

void MyDrawMovie::SetPart() {
	if (sf != startFlame || ef != endFlame) {
		startFlame = sf;
		endFlame = ef;
		Stop();
		Seek();
	}
}

// �X�s�[�h�擾
double MyDrawMovie::GetSpeed() {
	return sp;
}

// �ŏ��̃t���[�����擾
int MyDrawMovie::GetStartFlame() {
	return startFlame;
}

// �Ō�̃t���[�����擾
int MyDrawMovie::GetEndFlame() {
	if (endFlame == -1)
		return GetAllFlame();
	return endFlame;
}

// ���݂̃t���[�����擾
int MyDrawMovie::GetNowFlame() {
	return TellMovieToGraphToFrame(handle);
}

// ����̃t���[�����擾
int MyDrawMovie::GetAllFlame() {
	return GetMovieTotalFrameToGraph(handle) - 1;
}

// �X�^�[�g�t���[���w��
void MyDrawMovie::SetStartFlame(const int flame) {
	sf = flame;
}

// �G���h�t���[���w��
void MyDrawMovie::SetEndFlame(const int flame) {
	ef = flame;
}

MyDrawMovie::~MyDrawMovie() {
	DeleteGraph(handle);
}