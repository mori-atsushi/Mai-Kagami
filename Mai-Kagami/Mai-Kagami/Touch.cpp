#include "Touch.h"

void Touch::Check() {
	if (CheckHitKey(KEY_INPUT_1))
		key[0]++;
	else
		key[0] = 0;

	if (CheckHitKey(KEY_INPUT_2))
		key[1]++;
	else
		key[1] = 0;

	if (CheckHitKey(KEY_INPUT_3))
		key[2]++;
	else
		key[2] = 0;

	if (CheckHitKey(KEY_INPUT_4))
		key[3]++;
	else
		key[3] = 0;

	if (CheckHitKey(KEY_INPUT_5))
		key[4]++;
	else
		key[4] = 0;
}

int Touch::Get(int num) {
	return key[num];
}