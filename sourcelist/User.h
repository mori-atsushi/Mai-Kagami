#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__

#include "DxLib.h"

class User {
public:
	void SetUserId(const char *userId); // ���[�U�[ID���i�[
	char *GetUserId(); // ���[�U�[ID������
private:
	char userId[64];
};
#endif