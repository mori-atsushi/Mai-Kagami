#include "User.h"

// ���[�U�[ID���i�[
void User::SetUserId(const char *userId) {
	strcpy_s(this->userId, sizeof(this->userId), userId);
}

// ���[�U�[ID������
char *User::GetUserId() {
	return userId;
}