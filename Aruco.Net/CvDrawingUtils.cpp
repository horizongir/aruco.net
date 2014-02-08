#include "StdAfx.h"
#include "CvDrawingUtils.h"


Aruco::Net::CvDrawingUtils::CvDrawingUtils()
{
}

void Aruco::Net::CvDrawingUtils::Draw3dAxis(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::cvarrToMat(image->DangerousGetHandle().ToPointer());
	aruco::CvDrawingUtils::draw3dAxis(cvimage, *(marker->marker), *(parameters->parameters));
}

void Aruco::Net::CvDrawingUtils::Draw3dCube(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::cvarrToMat(image->DangerousGetHandle().ToPointer());
	aruco::CvDrawingUtils::draw3dCube(cvimage, *(marker->marker), *(parameters->parameters));
}
