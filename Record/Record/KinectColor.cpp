#include "KinectColor.h"

KinectColor::KinectColor(IKinectSensor *m_pKinectSensor) {
	width = new int();
	height = new int();
	bufferSize = new unsigned int();

	HRESULT hr;
	IColorFrameSource* pColorFrameSource = NULL;

	hr = m_pKinectSensor->get_ColorFrameSource(&pColorFrameSource);

	if (SUCCEEDED(hr))
	{
		hr = pColorFrameSource->OpenReader(&m_pColorFrameReader);
	}

	IFrameDescription* pDescription;
	hr = pColorFrameSource->get_FrameDescription(&pDescription);

	if (SUCCEEDED(hr))
	{
		pDescription->get_Width(width);
		pDescription->get_Height(height);
		*bufferSize = *width * *height * 4 * sizeof(unsigned char);

		bufferMat = new cv::Mat(*height, *width, CV_8UC4);
		colorMat = new cv::Mat(HEIGHT, WIDTH, CV_8UC4);

		memset(&baseImage, 0, sizeof(BASEIMAGE));
		CreateXRGB8ColorData(&baseImage.ColorData);
		baseImage.MipMapCount = 0;
		handle = -1;
	}

	SafeRelease(pColorFrameSource);
}

void KinectColor::Update() {
	IColorFrame *pColorFrame = NULL;
	HRESULT hr = m_pColorFrameReader->AcquireLatestFrame(&pColorFrame);
	if (SUCCEEDED(hr))
	{
		hr = pColorFrame->CopyConvertedFrameDataToArray(*bufferSize, reinterpret_cast<BYTE*>(bufferMat->data), ColorImageFormat::ColorImageFormat_Bgra);
		if (SUCCEEDED(hr))
		{
			cv::resize(*bufferMat, *colorMat, cv::Size(), (double)WIDTH / *width, (double)HEIGHT / *height);
			baseImage.GraphData = colorMat->data;
			baseImage.Width = colorMat->cols;
			baseImage.Height = colorMat->rows;
			baseImage.Pitch = colorMat->step;

			if (handle == -1) {
				handle = CreateGraphFromBaseImage(&baseImage);
			}
			else {
				ReCreateGraphFromBaseImage(&baseImage, handle);
			}
		}
	}
	SafeRelease(pColorFrame);
}

void KinectColor::View() {
	DrawGraph(0, 0, handle, FALSE);
}

KinectColor::~KinectColor() {
	SafeRelease(m_pColorFrameReader);
}