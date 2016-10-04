#include "KinectBody.h"

//コンストラクタ
KinectBody::KinectBody(IKinectSensor *m_pKinectSensor) {
	userFlag = new boolean();
	HRESULT hr;

	IBodyFrameSource* pBodyFrameSource = NULL;

	hr = m_pKinectSensor->get_BodyFrameSource(&pBodyFrameSource);

	if (SUCCEEDED(hr))
	{
		hr = pBodyFrameSource->OpenReader(&m_pBodyFrameReader);
	}

	SafeRelease(pBodyFrameSource);
}

void KinectBody::Update() {
	*userFlag = FALSE;
	userJoints[0].Position.Z = 100;

	if (!m_pBodyFrameReader)
	{
		return;
	}

	IBodyFrame* pBodyFrame = NULL;

	HRESULT hr = m_pBodyFrameReader->AcquireLatestFrame(&pBodyFrame);

	if (SUCCEEDED(hr))
	{

		INT64 nTime = 0;

		hr = pBodyFrame->get_RelativeTime(&nTime);

		IBody* ppBodies[BODY_COUNT] = { 0 };

		if (SUCCEEDED(hr))
		{
			hr = pBodyFrame->GetAndRefreshBodyData(_countof(ppBodies), ppBodies);
		}
		if (SUCCEEDED(hr))
		{
			hr = pBodyFrame->GetAndRefreshBodyData(_countof(ppBodies), ppBodies);
		}

		if (SUCCEEDED(hr))
		{
			for (int i = 0; i < BODY_COUNT; ++i) {
				IBody* pBody = ppBodies[i];
				if (pBody)
				{
					BOOLEAN bTracked = false;
					hr = pBody->get_IsTracked(&bTracked);

					if (SUCCEEDED(hr) && bTracked) {
						Joint joints[JointType_Count];
						hr = pBody->GetJoints(_countof(joints), joints);
						if (SUCCEEDED(hr))
						{
							if (joints[0].Position.Z < userJoints[0].Position.Z) {
								*userFlag = TRUE;
								for (int i = 0; i < JointType_Count; i++)
									userJoints[i] = joints[i];
							}
						}
					}
				}
			}
		}

		for (int i = 0; i < _countof(ppBodies); ++i)
		{
			SafeRelease(ppBodies[i]);
		}
	}
	SafeRelease(pBodyFrame);
}

//距離を測定
boolean KinectBody::CheckDistance() {
	const int maxMis = 60;
	static int miss = maxMis;
	if (KINECT_FLAG) {
		if (*userFlag) {
			if (miss == 0 && userJoints[0].Position.Z >= 1.5)
				miss = 0;
			else if (miss != 0 && userJoints[0].Position.Z >= 2.0)
				miss = 0;
			else
				miss = maxMis;
		}
		else {
			miss++;
		}
	}
	else {
		if (CheckHitKey(KEY_INPUT_N) == 1)
			miss = 0;
		else
			miss = maxMis;
	}
	if (miss < maxMis)
		return TRUE;
	else
		return FALSE;
}

//保存
void KinectBody::JointSave(const int flame) {
	now = flame;
	if (KINECT_FLAG) {
		for (int i = 0; i < JointType_Count; i++) {
			userData[flame][i][0] = userJoints[i].Position.X;
			userData[flame][i][1] = userJoints[i].Position.Y;
			userData[flame][i][2] = userJoints[i].Position.Z;
		}
	}
}

//指定したflameまでのデータを削除
void KinectBody::DeleteSave(const int flame) {
	if (flame == 0) {
		userData.clear();
	}
	else {
		for (int i = flame; i <= now; i++) {
			if (userData.count(i) == 0)
				continue;
			userData.erase(i);
		}
	}
	now = flame;
}

std::map <int, flameData> KinectBody::GetSave() {
	return userData;
}

int KinectBody::GetNow() {
	return now;
}

KinectBody::~KinectBody() {
	SafeRelease(m_pBodyFrameReader);
}