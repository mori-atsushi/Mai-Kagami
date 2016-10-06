#ifndef __RESULT_H_INCLUDED__
#define __RESULT_H_INCLUDED__

#include <time.h>

#include "DxLib.h"
#include "Songs.h"
#include "User.h"
#include "Grading.h"
#include "Http.h"
#include "Kinect.h"

class Result : public Grading {
public:
	Result(Songs *songs, User *user, Kinect *kinect);
	void Calc(); //得点計算
	void Send(); //送信
	float GetTotal(); //総合得点取得
	void GetPoint(int x[4]); //部位別得点取得
	char *GetComment(); //コメント取得
	int GetTiming(); //タイミング取得
	int GetExpression(); //表情取得
	int GetScore(int x[100]); //区間別得点取得
	int GetBadPart();
	int GetBadSpeed();
private:
	void GetNowTime(int nowTime[]);
	int CalcHappy(); //表情採点
	void CalcRecommend(); //オススメ練習算出
	int badPart, badSpeed;
	Songs *songs;
	Song *song;
	User *user;
	Kinect *kinect;
};

#endif