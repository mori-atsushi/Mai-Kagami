#include "Kinect.h"

// �R���X�g���N�^
Kinect::Kinect() {
	if (KINECT_FLAG) {
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
// 				kinectColor = new KinectColor(m_pKinectSensor);
			}
		}

		if (!m_pKinectSensor || FAILED(hr))
			exit(-1);
	}
}

void Kinect::Update() {
	if (KINECT_FLAG) {
		static boolean updateFlag = TRUE; // �X�V�p�̃t���O�A2��Ɉ�񂵂����������Ȃ�
		if (updateFlag) {
			kinectBody->Update(); // ���i���update
// 			kinectColor->Update(); // �F���update

			updateFlag = FALSE;
		}
		else {
			updateFlag = TRUE;
		}
	}
}

// �f�X�g���N�^
Kinect::~Kinect()
{
	delete kinectBody;
// 	delete kinectColor;

	// close the Kinect Sensor
	if (m_pKinectSensor)
		m_pKinectSensor->Close();

	SafeRelease(m_pKinectSensor);
}