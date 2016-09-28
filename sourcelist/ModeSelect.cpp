#include "ModeSelect.h"

// ���[�h�I��������
ModeSelectButton::ModeSelectButton(Font *font, Touch *touch) {
	char *through = "��Ȃ�ʂ��ė��K�ł��܂��B\n���Ȃ��ɂ������X�s�[�h�ŗ��K�ł��A\n���́E�̓_���s���܂��B";
	char *part = "���K��Ԃ�ݒ肵�ďW�����ė��K�ł�\n�܂��B���K�r���ł����Ă��A�X�s�[�h\n�̕ύX�⊪���߂������R�ɂł��܂��B";
	button[0] = new TriangleButton2(font, touch, "�ʂ����K���[�h", through, 2, 0, WIDTH * 0.57, "Blue");
	button[1] = new TriangleButton2(font, touch, "�������K���[�h", part, 2, 2, WIDTH * 0.57, "Yellow");
	button[2] = new CircleButton2(font, touch, "�߂�", 4);
}

int ModeSelectButton::Switch(const int scene) {
	if (button[0]->GetTouch() == 1)
		return OPTION1;
	if (button[1]->GetTouch() == 1)
		return OPTION2;
	if (button[2]->GetTouch() == 1)
		return MAIN;
	return scene;
}

// ���[�h�I���{�^���v�Z
void ModeSelectButton::ContentUpdate() {
	if (nowScene == MODE)
		viewFlag = TRUE;
	else
		viewFlag = FALSE;
}

// ���[�h�I���{�^���\��
void ModeSelectButton::ContentView() {
	for (int i = 0; i < 3; i++)
		button[i]->View();
}

// ���[�h�I���폜
ModeSelectButton::~ModeSelectButton() {
	for (int i = 0; i < 3; i++)
		delete button[i];
}