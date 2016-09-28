#include "User.h"

// ユーザーIDを格納
void User::SetUserId(const char *userId) {
	strcpy_s(this->userId, sizeof(this->userId), userId);
}

// ユーザーIDを収得
char *User::GetUserId() {
	return userId;
}