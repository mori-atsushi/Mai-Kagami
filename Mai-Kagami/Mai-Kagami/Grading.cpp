#include "Grading.h"

Grading::Grading() {
	bezier = new Bezier(1.1, 0, 0.6, 1.2);
}

void Grading::Mark(const char *songFolder) {
	FILE *userfp, *modelfp;
	if ((userfp = fopen("FILE/test.txt", "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	char buf[256];
	sprintf(buf, "song/%s/model.txt", songFolder);
	if ((modelfp = fopen(buf, "r")) == NULL) {
		printf("file open error!!\n");
		exit(EXIT_FAILURE);
	}

	const int MAX = 1024;
	char userline[MAX], modelline[MAX];
	int i = 0, j = 0;
	int modelflame = 0, userflame = 0;
	int sum = 0, count = 0;

	while (fgets(userline, MAX, userfp) != NULL) {
		float model[24][3], user[24][3];
		sscanf(userline, "%d:", &userflame);

		int num;
		if (userflame == 0)
			num = 1;
		else
			num = (int)log10((double)userflame) + 1;

		char *line = userline + num + 1;
		for (i = 0; i < 24; i++) {
			if (sscanf(line, "%f,%f,%f|", &user[i][0], &user[i][1], &user[i][2]) != 3)
				break;
			char str[256];
			line = line + sprintf(str, "%f,%f,%f|", user[i][0], user[i][1], user[i][2]);
		}
		if (i != 24)
			continue;

		while (j != 24 || userflame > modelflame) {
			sscanf(modelline, "%d:", &modelflame);
			if (fgets(modelline, MAX, modelfp) == NULL)
				break;

			int num;
			if (modelflame == 0)
				num = 1;
			else
				num = (int)log10((double)modelflame) + 1;

			char *line = modelline + num + 1;
			for (j = 0; j < 24; j++) {
				if (sscanf(line, "%f,%f,%f|", &model[j][0], &model[j][1], &model[j][2]) != 3)
					break;
				char str[256];
				line = line + sprintf(str, "%f,%f,%f|", model[j][0], model[j][1], model[j][2]);
			}
		}
		sum += (int)FlameMark(user, model);
		count++;
	}
	total = (int)(bezier->Calc((double)sum / count / 100) * 100);
	if (total > 100)
		total = 100;
	else if (total < 0)
		total = 0;
}

//2関節間の点数計算
float Grading::JointMark(float joints[24][3], float model[24][3], int x, int y) {
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
float Grading::FlameMark(float joints[24][3], float model[24][3]) {
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

Grading::~Grading() {
	delete bezier;
}