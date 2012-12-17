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

void Aruco::Net::Marker::Draw(IntPtr in, double c0, double c1, double c2, int lineWidth, bool writeId)
{
	cv::Mat cvinput = cv::Mat((IplImage*)in.ToPointer());
	marker->draw(cvinput,cv::Scalar(c0,c1,c2),lineWidth,writeId);
}

cli::array<double> ^ Aruco::Net::Marker::GetGLModelViewMatrix()
{
	cli::array<double> ^result = gcnew cli::array<double>(16);
	cli::pin_ptr<double> modelView = &result[0];
	marker->glGetModelViewMatrix(modelView);
	return result;
}