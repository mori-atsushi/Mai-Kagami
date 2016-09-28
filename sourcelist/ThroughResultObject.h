#ifndef __THROUGHRESULTOBJECT_H_INCLUDED__
#define __THROUGHRESULTOBJECT_H_INCLUDED__

#include "Dxlib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "DrawGraph.h"
#include "Song.h"

// ���_�o�[
class ScoreBar : public Draw {
public:
	ScoreBar(Font *font, const float y, const char *title, const char *para1, const char *para2);
	void Load(const int p);
	~ScoreBar();
private:
	void ContentView();
	MyDrawTextLine *title;
	MyDrawText *para[2];
	MyDrawBox *box[8];
	MyDrawGraph *mark;
	MyDrawText *score;
};

// �^�C�~���O���_�o�[
class TimingBar : public ScoreBar {
public:
	TimingBar(Font *font);
};

// �\��_�o�[
class ExpressionBar : public ScoreBar {
public:
	ExpressionBar(Font *font);
};

// �R�����g�\��
class ResultComment : public Draw {
public:
	ResultComment(Font *font);
	void Load(const char *str);
	~ResultComment();
private:
	void ContentView();
	MyDrawTextLine *title;
	MyDrawTexts *comment;
};

// �̂̃p�[�c�ʍ̓_���ʕ\��
class ResultBody : public Draw {
public:
	ResultBody(Font *font);
	void Load(const int point[4]);
	void Delete();
	~ResultBody();
private:
	void ContentView();
	MyDrawGraph *body;
	MyDrawText *part[4];
	MyDrawText *point[4];
};

// ��ԕʍ̓_�O���t�\��
class ResultGraph : public Draw {
public:
	ResultGraph(Font *font);
	void Load(const int *ponit, const int num, Song *song);
	void Delete();
	~ResultGraph();
private:
	void ContentView();
	MyDrawBox *myDrawBox;
	MyDrawTexts *scale; // �ڐ���
	MyDrawCircle *dot[100]; // �_
	MyDrawLine *line[100]; // �_
	MyDrawLine *frame[2]; // �g��
	MyDrawTextV *part[64];
	Font *font;
	const float w = WIDTH * 0.6, h = HEIGHT * 0.13;
	int pointMax = 0, partMax = 0;
};

#endif