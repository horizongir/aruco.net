#include "StdAfx.h"
#include "Marker.h"

static Aruco::Net::Marker::Marker()
{
	Aruco::Net::Marker::Empty = gcnew Aruco::Net::Marker(new aruco::Marker());
}

Aruco::Net::Marker::Marker(aruco::Marker *marker):
marker(marker)
{
}

Aruco::Net::Marker::Marker(const aruco::Marker &marker):
marker(new aruco::Marker(marker))
{
}

Aruco::Net::Marker::!Marker()
{
	delete marker;
}

void Aruco::Net::Marker::Draw(OpenCV::Net::Arr ^image, OpenCV::Net::Scalar color)
{
	Draw(image, color, 1, true);
}

void Aruco::Net::Marker::Draw(OpenCV::Net::Arr ^image, OpenCV::Net::Scalar color, int lineWidth)
{
	Draw(image, color, lineWidth, true);
}

void Aruco::Net::Marker::Draw(OpenCV::Net::Arr ^image, OpenCV::Net::Scalar color, int lineWidth, bool writeId)
{
	IntPtr handle = image->DangerousGetHandle();
	cv::Mat cvinput = cv::cvarrToMat(handle.ToPointer());
	marker->draw(cvinput,*((cv::Scalar*)&color),lineWidth,writeId);
}

cli::array<double> ^ Aruco::Net::Marker::GetGLModelViewMatrix()
{
	cli::array<double> ^result = gcnew cli::array<double>(16);
	if (marker->isValid())
	{
		cli::pin_ptr<double> modelView = &result[0];
		marker->glGetModelViewMatrix(modelView);
	}
	return result;
}