#include "KinectBody.h"

static const DWORD c_FaceFrameFeatures = FaceFrameFeatures::FaceFrameFeatures_Happy;

//コンストラクタ
KinectBody::KinectBody(IKinectSensor *m_pKinectSensor) {
	userFlag = new boolean();
	HRESULT hr;

	IBodyFrameSource* pBodyFrameSource = NULL;

	for (int i = 0; i < BODY_COUNT; i++)
	{
		m_pFaceFrameSources[i] = nullptr;
		m_pFaceFrameReaders[i] = nullptr;
	}

	hr = m_pKinectSensor->get_BodyFrameSource(&pBodyFrameSource);

	if (SUCCEEDED(hr))
	{
		hr = pBodyFrameSource->OpenReader(&m_pBodyFrameReader);
	}


	if (SUCCEEDED(hr))
	{
		// create a face frame source + reader to track each body in the fov
		for (int i = 0; i < BODY_COUNT; i++)
		{
			if (SUCCEEDED(hr))
			{
				// create the face frame source by specifying the required face frame features
				hr = CreateFaceFrameSource(m_pKinectSensor, 0, c_FaceFrameFeatures, &m_pFaceFrameSources[i]);
			}
			if (SUCCEEDED(hr))
			{
				// open the corresponding reader
				hr = m_pFaceFrameSources[i]->OpenReader(&m_pFaceFrameReaders[i]);
			}
		}
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
			int bodyid = -1;
			//座標の取得
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
								bodyid = i;
								*userFlag = TRUE;
								for (int i = 0; i < JointType_Count; i++)
									userJoints[i] = joints[i];
							}
						}
					}
				}
			}
			//表情の取得
			if (bodyid != -1) {
				IFaceFrame* pFaceFrame = nullptr;
				hr = m_pFaceFrameReaders[bodyid]->AcquireLatestFrame(&pFaceFrame);
				BOOLEAN bFaceTracked = false;
				if (SUCCEEDED(hr) && nullptr != pFaceFrame)
				{
					hr = pFaceFrame->get_IsTrackingIdValid(&bFaceTracked);
				}

				if (SUCCEEDED(hr)) {
					IBody* pBody = ppBodies[bodyid];
					if (pBody != nullptr)
					{
						BOOLEAN bTracked = false;
						hr = pBody->get_IsTracked(&bTracked);

						UINT64 bodyTId;
						if (SUCCEEDED(hr) && bTracked)
						{
							// get the tracking ID of this body
							hr = pBody->get_TrackingId(&bodyTId);
							
							if (SUCCEEDED(hr))
							{
								// update the face frame source with the tracking ID
								m_pFaceFrameSources[bodyid]->put_TrackingId(bodyTId);
							}

							if (SUCCEEDED(hr))
							{
								hr = pFaceFrame->get_IsTrackingIdValid(&bFaceTracked);
								if (SUCCEEDED(hr) && bFaceTracked) {
									IFaceFrameResult* pFaceFrameResult = nullptr;
									DetectionResult faceProperties[FaceProperty::FaceProperty_Count];
									hr = pFaceFrame->get_FaceFrameResult(&pFaceFrameResult);
									if (SUCCEEDED(hr) && pFaceFrameResult != nullptr) {
										hr = pFaceFrameResult->GetFaceProperties(FaceProperty::FaceProperty_Count, faceProperties);
										happyFace = faceProperties[FaceProperty::FaceProperty_Happy];
									}
								}
							}
						}
					}
					SafeRelease(pFaceFrame);
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
		if (happyFace > 0)
			happyNum++;
		if (happyFace == DetectionResult::DetectionResult_Yes)
			happySum++;
	}
}

//指定したflameまでのデータを削除
void KinectBody::DeleteSave(const int flame) {
	if (flame == 0) {
		userData.clear();
		happyNum = 0;
		happySum = 0;
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

int KinectBody::GetHappy() {
	return happySum * 100 / happyNum;
}

int KinectBody::GetNow() {
	return now;
}

KinectBody::~KinectBody() {
	SafeRelease(m_pBodyFrameReader);
}