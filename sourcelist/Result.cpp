#include "Result.h"

Result::Result(Songs *songs, User *user) {
	this->songs = songs;
	this->user = user;
}

void Result::Calc() {
	Song *song = songs->GetSong(songs->GetNowSong());
	char buf[256];
	sprintf(buf, "song/%s/model.txt", song->GetFolder());
	Mark(buf, "FILE/test.txt");
	strcpy(comment, "B��������T�r�ɓ����Ă���T�r�̏I���ɂ����Ă����\n�̂悤�Ɏv���܂��B�������d�_�I�ɗ��K���܂��傤�B");
	point[0] = 2;
	point[1] = 2;
	point[2] = 1;
	point[3] = 1;
	timing = 2;
	expression = 4;
}

// ���M
void Result::Send() {
	Song *song = songs->GetSong(songs->GetNowSong());
	// printfDx("%d\n", song->GetSongId()); // ��ID
	// printfDx("%s\n", user->GetUserId()); // ���[�U�[ID
}

float Result::GetTotal() {
	return total;
}

// ���ʕʓ��_�擾
void Result::GetPoint(int x[4]) {
	for (int i = 0; i < 4; i++)
		x[i] = point[i];
}

// �R�����g�擾
char *Result::GetComment() {
	return comment;
}

// �^�C�~���O�擾
int Result::GetTiming() {
	return timing;
}

// �\��擾
int Result::GetExpression() {
	return expression;
}

// ��ԕʓ��_�擾
int Result::GetScore(int x[100]) {
	for (int i = 0; i < max; i++)
		x[i] = score[i];
	return max;
}