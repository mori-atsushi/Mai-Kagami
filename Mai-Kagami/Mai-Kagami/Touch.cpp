#include "Touch.h"

Touch::Touch() {
	if (TOUCH_FLAG)
		serial = new Serial();
	for (int i = 0; i < 5; i++)
		key[i] = 0;
}

//Šm”F
void Touch::Check() {
	if (TOUCH_FLAG) {
		static int t = 100;
		char *data = serial->GetData();
		int temp[5] = {}, count = 0;

		if (t > 0) {
			t--;
		}
		else {
			while (*data != '\0') {
				if (*data != '\n' && *data != '\r') {
					int num;
					if (*data <= '9')
						num = *data - '0';
					else
						num = *data - 'A' + 10;
					for (int i = 0; i < 5; i++) {
						if (num % 2 == 1)
							temp[i]++;
						num /= 2;
					}
					count++;
				}
				data++;
			}
			int k = KEY_INPUT_1;
			for (int i = 0; i < 5; i++) {
				if (temp[i] / count > 0.5 || CheckHitKey(++k))
					key[i]++;
				else
					key[i] = 0;
			}
		}
	}
	else {
		int k = KEY_INPUT_1;
		for (int i = 0; i < 5; i++) {
			if (CheckHitKey(k++))
				key[i]++;
			else
				key[i] = 0;
		}
	}
}

//Žæ“¾
int Touch::Get(int num) {
	return key[num];
}

boolean Touch::Input(int num, int wait, int duration) {
	int key = Get(num);
	return key == 1 || wait <= key && !((key - wait) % duration);
}

boolean Touch::Input2(int num, int wait1, int duration1, int wait2, int duration2) {
	int key = Get(num);
	return key == 1
		|| wait1 <= key && key < wait2 && !((key - wait1) % duration1)
		|| wait2 + (wait2 - wait1) % duration1 <= key && !((key - wait2 - (wait2 - wait1) % duration1) % duration2);
}

Touch::~Touch() {
	if(TOUCH_FLAG)
		delete serial;
}