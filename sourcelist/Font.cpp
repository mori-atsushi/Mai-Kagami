#include "Font.h"

// �t�H���g�w��
Font::Font() {
	for(int i = 0; i < FONT_NUM; i++)
		id[p[i]] = CreateFontToHandle("M+ 1c", p[i] / SIZE_RATE, 1, DX_FONTTYPE_ANTIALIASING);
}

// �t�H���g�擾
int Font::Get(int point) {
	return id[point];
}

// �t�H���g�f�X�g���N�^
Font::~Font() {
	for (int i = 0; i < FONT_NUM; i++)
		DeleteFontToHandle(id[p[i]]); // �t�H���g�f�[�^���폜
}