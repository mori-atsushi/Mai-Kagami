#include "Result.h"

Result::Result(Songs *songs, User *user) {
	this->songs = songs;
	this->user = user;
}

void Result::Calc() {
	total = 64;
	strcpy(comment, "Bメロからサビに入ってからサビの終わりにかけてが苦手のように思います。そこを重点的に練習しましょう。");
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
	//曲IDのリクエスト作成
	char songReq[126] = { 0 };
	sprintf_s(songReq, 126, "song=%d", song->GetSongId());
	//ユーザーIDのリクエスト作成
	char userReq[32] = { 0 };
	sprintf_s(userReq, 32, "user=%s", user->GetUserId());
	//現在時刻の取得
	int temp[5] = { 0 };
	GetNowTime(temp);
	//年月日のリクエスト作成
	char dateReq[32] = { 0 };
	sprintf_s(dateReq, 32, "date=%02d-%02d-%02d %02d-%02d", temp[0], temp[1], temp[2], temp[3], temp[4]);
	//総合得点のリクエスト作成
	char totalReq[16] = { 0 };
	sprintf_s(totalReq, 16, "total=%d", this->total);
	//区間別採点のリクエスト作成
	char partReq[1024] = { 0 };
	sprintf_s(partReq, 1024, "part=%s/%d", song->GetPart(0)->GetName(),score[0]);
	for (int i = 1, n = this->max; i < n; i++) {
		sprintf_s(partReq, 1024, "%s/%s/%d", partReq, song->GetPart(0)->GetName(), partScore[i]);
	}
	//体の部位採点のリクエスト作成
	char bodyPoint[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		switch (point[i]) {
		case 1:bodyPoint[i] = 'A';	break;
		case 2:bodyPoint[i] = 'B';	break;
		case 3:bodyPoint[i] = 'C';	break;
		}
	}
	char bodyReq[32] = { 0 };
	sprintf_s(bodyReq, 32, "body=%c/%c/%c/%c", bodyPoint[0], bodyPoint[1], bodyPoint[2], bodyPoint[3]);
	//タイミングのリクエスト作成
	char timingReq[16] = { 0 };
	sprintf_s(timingReq, 16, "timing=%d", timing);
	//表情のリクエスト作成
	char expressionReq[16] = { 0 };
	sprintf_s(expressionReq, 16, "expression=%d", expression);
	//コメントのリクエスト作成
	WCHAR w_comment[256] = { 0 };
	mbstowcs(w_comment, comment, 256);
	char commentReq[256] = { 0 };
	printfDx(comment);
	sprintf_s(commentReq, 256, "comment=%ls", w_comment);

	//urlを作成
	char url[512] = { 0 };
	sprintf_s(url, 512, "http://globalstudios.jp/mai-archive/api_add.php?%s&%s&%s&%s&%s&%s&%s&%s&%s", 
		songReq, userReq, dateReq, totalReq, partReq, bodyReq, timingReq, expressionReq, commentReq);
	Http http;
	if(!http.Send(url))	printfDx("httpエラー");
}

void Result::GetNowTime(int nowTime[]) {
	time_t now = time(NULL);
	struct tm *pnow = localtime(&now);
	nowTime[0] = pnow->tm_year + 1900;
	nowTime[1] = pnow->tm_mon + 1;
	nowTime[2] = pnow->tm_mday;
	nowTime[3] = pnow->tm_hour;
	nowTime[4] = pnow->tm_min;
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