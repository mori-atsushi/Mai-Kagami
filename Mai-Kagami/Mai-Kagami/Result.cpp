#include "Result.h"

Result::Result(Songs *songs, User *user, Kinect *kinect) {
	this->songs = songs;
	this->user = user;
	this->kinect = kinect;
}

void Result::Calc() {
	song = songs->GetSong(songs->GetNowSong());
	if (KINECT_FLAG) {
		char buf[256];
		sprintf(buf, "song/%s/model.txt", song->GetFolder());
		Mark(buf, kinect->kinectBody->GetSave(), kinect->kinectBody->GetNow());
		expression = CalcHappy();
		kinect->kinectBody->DeleteSave();
	}
	else {
		total = 80;
		expression = 6;
		timing = 4;
		point[0] = 2;
		point[1] = 3;
		point[2] = 1;
		point[3] = 1;
		max = 10;
		score[0] = 80;
		score[1] = 60;
		score[2] = 75;
		score[3] = 80;
		score[4] = 90;
		score[5] = 50;
		score[6] = 70;
		score[7] = 60;
		score[8] = 70;
		score[9] = 80;
		partScore[0] = 80;
		partScore[1] = 60;
		partScore[2] = 75;
		partScore[3] = 80;
		partScore[4] = 90;
		partScore[5] = 50;
		partScore[6] = 70;
		partScore[7] = 60;
		partScore[8] = 70;
		partScore[9] = 80;
	}
	CalcRecommend();
	CalcComment();
}

int Result::CalcHappy() {
	int p = kinect->kinectBody->GetHappy();
	for (int i = 0; i < 8; i++) {
		if(p < 20 + i * 10)
			return i;
	}
	return 8;
}

void Result::CalcRecommend() {
	badPart = 0;
	for (int i = 1; i < song->GetPartNum(); i++) {
		if (partScore[i] < partScore[badPart])
			badPart = i;
	}
	if (partScore[badPart] < 20)
		badSpeed = 4;
	else if (partScore[badPart] < 40)
		badSpeed = 3;
	else if (partScore[badPart] < 60)
		badSpeed = 2;
	else if (partScore[badPart] < 80)
		badSpeed = 1;
	else if (partScore[badPart] < 100)
		badSpeed = 0;
}

void Result::CalcComment() {
	char buf[1024] = "";
	if(expression > 5)
		strcat_s(buf, sizeof(buf), "いい笑顔で踊れています。");

	if(total > 90)
		strcat_s(buf, sizeof(buf), "素晴らしい！ほぼ完璧でしょう。");
	else if(total > 70)
		strcat_s(buf, sizeof(buf), "だいぶ上達してきました。");
	else if (total > 50)
		strcat_s(buf, sizeof(buf), "まだ覚えてない箇所がありそうですね。");
	else
		strcat_s(buf, sizeof(buf), "まだまだですね。ゆっくりからやり直そう。");

	if (badSpeed > 0) {
		if (badSpeed > 2)
			strcat_s(buf, sizeof(buf), "特に");
		else
			strcat_s(buf, sizeof(buf), "若干");

		char b[256];
		sprintf_s(b, sizeof(b), "「%s」が苦手のようです。", song->GetPart(badPart)->GetName());
		strcat_s(buf, sizeof(buf), b);
	}
	strcpy_s(comment, sizeof(comment), buf);
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
	for (int i = 1, n = song->GetPartNum(); i < n; i++) {
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

int Result::GetBadPart() {
	return badPart;
}
int Result::GetBadSpeed() {
	return badSpeed;
}