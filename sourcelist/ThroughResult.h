#ifndef __THROUGHRESULT_H_INCLUDED__
#define __THROUGHRESULT_H_INCLUDED__

#include "DxLib.h"
#include "DrawText.h"
#include "DrawObject.h"
#include "Button.h"
#include "Songs.h"
#include "Scene.h"
#include "ThroughDefine.h"
#include "ThroughResultDefine.h"
#include "Touch.h"
#include "Result.h"

class ThroughResult : public SubScene {
public:
	ThroughResult(Font *font, Songs *songs, Touch *touch, Result *result);
	void Load();
	ThroughResultScene Switch(const ThroughResultScene scene);
	~ThroughResult();
private:
	void ContentUpdate();
	void ContentView();
	MyDrawTextLine		*title;			// �̓_���ʉ�ʃ^�C�g��
	MyDrawCircle		*circle;		// ���_��\������~(�����F)
	MyDrawCircleGauge	*pointCircle;	// ���_�������p�x�w��̉~
	MyDrawCircle		*pointCircle2;	// ���_�������~
	MyDrawText			*text;			// �e�L�X�g�i�������_�j
	MyDrawGraph			*point1, *point2, *point3;		// ���_
	MyDrawText			*unit;			// �P�ʁi�_�j
	MyDrawText			*last;			// �O��̓��_
	Button				*button;		// ���փ{�^��
	Song				*song;
	Songs				*songs;
	Result				*result;		// ���ʊ֌W
};

#endif