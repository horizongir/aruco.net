#include "StdAfx.h"
#include "CvDrawingUtils.h"


Aruco::Net::CvDrawingUtils::CvDrawingUtils()
{
}

void Aruco::Net::CvDrawingUtils::Draw3dAxis(IntPtr image, Marker ^marker, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::Mat((IplImage*)image.ToPointer());
	aruco::CvDrawingUtils::draw3dAxis(cvimage, *(marker->marker), *(parameters->parameters));
}

void Aruco::Net::CvDrawingUtils::Draw3dCube(IntPtr image, Marker ^marker, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::Mat((IplImage*)image.ToPointer());
	aruco::CvDrawingUtils::draw3dCube(cvimage, *(marker->marker), *(parameters->parameters));
}
