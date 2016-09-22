#include "Result.h"

Result::Result(Songs *songs, User *user) {
	this->songs = songs;
	this->user = user;
}

void Result::Calc() {
	Song *song = songs->GetSong(songs->GetNowSong());
	Mark(song->GetFolder());
	strcpy(comment, "Bメロからサビに入ってからサビの終わりにかけてが苦手\nのように思います。そこを重点的に練習しましょう。");
	point[0] = 2;
	point[1] = 2;
	point[2] = 1;
	point[3] = 1;
	score[0] = 50;
	score[1] = 80;
	score[2] = 40;
	score[3] = 90;
	score[4] = 100;
	score[5] = 70;
	score[6] = 60;
	score[7] = 80;
	score[8] = 40;
	score[9] = 90;
	max = 10;
	timing = 2;
	expression = 4;
}

//送信
void Result::Send() {
	Song *song = songs->GetSong(songs->GetNowSong());
	//printfDx("%d\n", song->GetSongId()); //曲ID
	//printfDx("%s\n", user->GetUserId()); //ユーザーID
}

float Result::GetTotal() {
	return total;
}

//部位別得点取得
void Result::GetPoint(int x[4]) {
	for (int i = 0; i < 4; i++)
		x[i] = point[i];
}

//コメント取得
char *Result::GetComment() {
	return comment;
}

//タイミング取得
int Result::GetTiming() {
	return timing;
}

//表情取得
int Result::GetExpression() {
	return expression;
}

//区間別得点取得
int Result::GetScore(int x[100]) {
	for (int i = 0; i < max; i++)
		x[i] = score[i];
	return max;
}