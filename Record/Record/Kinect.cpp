#include "Kinect.h"

//コンストラクタ
Kinect::Kinect() {
	HRESULT hr;

	hr = GetDefaultKinectSensor(&m_pKinectSensor);
	if (FAILED(hr))
		exit(-1);

	if (m_pKinectSensor)
	{
		hr = m_pKinectSensor->Open();

		if (SUCCEEDED(hr))
		{
			kinectBody = new KinectBody(m_pKinectSensor);
			kinectColor = new KinectColor(m_pKinectSensor);
		}
	}

	if (!m_pKinectSensor || FAILED(hr))
		exit(-1);
}

void Kinect::Update() {
	static boolean updateFlag = TRUE; //更新用のフラグ、2回に一回しか処理をしない
	if (updateFlag) {
		kinectBody->Update(); //骨格情報update
		kinectColor->Update(); //色情報update

		updateFlag = FALSE;
	}
	else {
		updateFlag = TRUE;
	}
}

void Kinect::View() {
	kinectColor->View();
}

//デストラクタ
Kinect::~Kinect()
{
	delete kinectBody;
	delete kinectColor;

	// close the Kinect Sensor
	if (m_pKinectSensor)
		m_pKinectSensor->Close();

	SafeRelease(m_pKinectSensor);
}