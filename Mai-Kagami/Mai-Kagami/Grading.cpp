#include "Grading.h"

FlameGrading::FlameGrading(std::map <int, flameData> modelData) {
	this->modelData = modelData;
	modelflame = 0, j = 0;
}

int FlameGrading::Mark(float joints[JointType_Count][3], const int userflame) {
	int x = 0, y;

	while (1) {
		if (modelData.count(userflame + x) != 0) {
			y = userflame + x;
			break;
		}
		if (modelData.count(userflame - x) != 0) {
			y = userflame - x;
			break;
		}
		x++;
	}
	return (int)FlameMark(joints, modelData[y]);
}

//2関節間の点数計算
float FlameGrading::JointMark(float joints[JointType_Count][3], float model[JointType_Count][3], int x, int y) {
	float userv, modelv;
	float inner = 0, userlen = 0, modellen = 0;
	for (int i = 0; i < 3; i++) {
		userv = joints[x][i] - joints[y][i];
		modelv = model[x][i] - model[y][i];
		inner += userv * modelv;
		userlen += pow(userv, 2);
		modellen += pow(modelv, 2);
	}
	userlen = (float)sqrt(userlen);
	modellen = (float)sqrt(modellen);
	float point = (inner / (userlen * modellen));
	if (point > 1)
		point = 100;
	else if (point > 0)
		point = (1 - acos(point) * 2 / DX_PI) * 100;
	else
		point = 0;
	return point * 1;
}

//1フレームあたりの点数計算
float FlameGrading::FlameMark(float joints[JointType_Count][3], float model[JointType_Count][3]) {
	const int MAX = 24;
	float sum = 0;
	int jointNum[MAX][2] = {
		{ JointType_SpineBase		, JointType_SpineMid },
		{ JointType_SpineBase		, JointType_HipLeft },
		{ JointType_SpineBase		, JointType_HipRight },
		{ JointType_SpineMid		, JointType_SpineShoulder },
		{ JointType_Neck			, JointType_SpineShoulder },
		{ JointType_Neck			, JointType_Head },
		{ JointType_ShoulderLeft	, JointType_ElbowLeft },
		{ JointType_ShoulderLeft	, JointType_SpineShoulder },
		{ JointType_ElbowLeft		, JointType_WristLeft },
		{ JointType_WristLeft		, JointType_HandLeft },
		{ JointType_HandLeft		, JointType_HandTipLeft },
		{ JointType_HandLeft		, JointType_ThumbLeft },
		{ JointType_ShoulderRight	, JointType_ElbowRight },
		{ JointType_ShoulderRight	, JointType_SpineShoulder },
		{ JointType_ElbowRight		, JointType_WristRight },
		{ JointType_WristRight		, JointType_HandRight },
		{ JointType_HandRight		, JointType_HandTipRight },
		{ JointType_HandRight		, JointType_ThumbRight },
		{ JointType_HipLeft			, JointType_KneeLeft },
		{ JointType_KneeLeft		, JointType_AnkleLeft },
		{ JointType_AnkleLeft		, JointType_FootLeft },
		{ JointType_HipRight		, JointType_KneeRight },
		{ JointType_KneeRight		, JointType_AnkleRight },
		{ JointType_AnkleRight		, JointType_FootRight } };
	for (int i = 0; i < MAX; i++)
		sum += JointMark(joints, model, jointNum[i][0], jointNum[i][1]);
	return  sum / MAX;
}

Grading::Grading() {
	bezier = new Bezier(1.2, 0, 0.5, 1);
}

void Grading::Mark(const char *model, const char *user) {
	const int SCORE_FLAME = 500; //一区切りあたりのフレーム

	const char BAR_NUM = 9; //タイミング、表情のバーの数
	FILE *userfp, *modelfp;
	FlameGrading *flameGrading[BAR_NUM];
	const int MAX = 1024;
	char userline[MAX], modelline[MAX];
	int i = 0, userflame = 0, modelflame = 0, sum = 0, count = 0, scoreCount = 0;
	int timingSum[BAR_NUM] = {};
	max = 0;

	if ((userfp = fopen(user, "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	if ((modelfp = fopen(model, "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	std::map <int, flameData> userData;
	std::map <int, flameData> modelData;

	while (fgets(userline, MAX, userfp) != NULL) {
		float user[JointType_Count][3];
		sscanf(userline, "%d:", &userflame);

		int num;
		if (userflame == 0)
			num = 1;
		else
			num = (int)log10((double)userflame) + 1;

		char *line = userline + num + 1;
		for (i = 0; i < JointType_Count; i++) {
			if (sscanf(line, "%f,%f,%f|", &user[i][0], &user[i][1], &user[i][2]) != 3)
				break;
			char str[256];
			line = line + sprintf(str, "%f,%f,%f|", user[i][0], user[i][1], user[i][2]);
		}
		if (i != JointType_Count)
			continue;
		else
			Copy(userData[userflame], user);
	}

	while (fgets(modelline, MAX, modelfp) != NULL) {
		float model[JointType_Count][3];
		sscanf(modelline, "%d:", &modelflame);

		int num;
		if (modelflame == 0)
			num = 1;
		else
			num = (int)log10((double)modelflame) + 1;

		char *line = modelline + num + 1;
		for (i = 0; i < JointType_Count; i++) {
			if (sscanf(line, "%f,%f,%f|", &model[i][0], &model[i][1], &model[i][2]) != 3)
				break;
			char str[256];
			line = line + sprintf(str, "%f,%f,%f|", model[i][0], model[i][1], model[i][2]);
		}
		if (i != JointType_Count)
			continue;
		else
			Copy(modelData[modelflame], model);
	}

	for (int i = 0; i < BAR_NUM; i++)
		flameGrading[i] = new FlameGrading(modelData);

	for (int i = 0; i <= userflame; i++) {
		if (userData.count(i) == 0)
			continue;

		int point = (int)flameGrading[0]->Mark(userData[i], i);
		for (int k = 0; k < BAR_NUM; k++) {
			int x = k - BAR_NUM / 2;
			int point = (int)flameGrading[k]->Mark(userData[i], i + x * 5);
			timingSum[k] += point;
			if (x == 0) {
				sum += point;
				score[max] += point;
				if (userflame >= SCORE_FLAME * (max + 1)) {
					score[max] = (int)(bezier->Calc((double)score[max] / (count - scoreCount) / 100) * 100);
					score[max] = Adjust(score[max]);
					scoreCount = count;
					max++;
				}
			}
		}
		count++;
	}


	score[max] = (int)(bezier->Calc((double)score[max] / (count - scoreCount) / 100) * 100);
	score[max] = Adjust(score[max]);
	max++;
	total = (int)(bezier->Calc((double)sum / count / 100) * 100);
	total = Adjust(total);
	timing = 0;
	for (int k = 1; k < BAR_NUM; k++) {
		if (timingSum[timing] < timingSum[k])
			timing = k;
	}
}

int Grading::Adjust(int point) {
	if (point > 100)
		return 100;
	else if (point < 0)
		return 0;
	return point;
}

void Grading::Copy(float dst[JointType_Count][3], float source[JointType_Count][3]) {
	for (int i = 0; i < JointType_Count; i++) {
		for (int j = 0; j < 3; j++)
			dst[i][j] = source[i][j];
	}
}


Grading::~Grading() {
	delete bezier;
}