#ifndef __USER_H_INCLUDED__
#define __USER_H_INCLUDED__

#include "DxLib.h"

class User {
public:
	void SetUserId(const char *userId); //ユーザーIDを格納
	char *GetUserId(); //ユーザーIDを収得
private:
	char userId[64];
};
#endif