#include "StdAfx.h"
#include "Marker.h"


Aruco::Net::Marker::Marker(const aruco::Marker &marker):
marker(new aruco::Marker(marker))
{
}

Aruco::Net::Marker::~Marker()
{
	delete marker;
}

void Aruco::Net::Marker::Draw(OpenCV::Net::Arr ^in, OpenCV::Net::Scalar color, int lineWidth, bool writeId)
{
	IntPtr handle = in->DangerousGetHandle();
	cv::Mat cvinput = cv::cvarrToMat(handle.ToPointer());
	marker->draw(cvinput,*((cv::Scalar*)&color),lineWidth,writeId);
}

cli::array<double> ^ Aruco::Net::Marker::GetGLModelViewMatrix()
{
	cli::array<double> ^result = gcnew cli::array<double>(16);
	cli::pin_ptr<double> modelView = &result[0];
	marker->glGetModelViewMatrix(modelView);
	return result;
}