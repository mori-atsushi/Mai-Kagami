#ifndef __FONT_H_INCLUDED__
#define __FONT_H_INCLUDED__

#include <map>
#include "DxLib.h"
#include "Main.h"

#define FONT_NUM 10

// �t�H���g�֌W
class Font {
public:
	Font(); // �|�C���g���Z�b�g
	int Get(int point); // �t�H���gID���o��
	~Font();
private:
	std::map <int, int> id;
	int p[FONT_NUM] = {16, 20, 24, 30, 36, 40, 46, 50 , 60, 100};
};

#endif