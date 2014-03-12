#include "StdAfx.h"
#include "DrawingUtils.h"


Aruco::Net::DrawingUtils::DrawingUtils()
{
}

void Aruco::Net::DrawingUtils::Draw3dAxis(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::cvarrToMat(image->DangerousGetHandle().ToPointer());
	aruco::CvDrawingUtils::draw3dAxis(cvimage, *(marker->marker), *(parameters->parameters));
}

void Aruco::Net::DrawingUtils::Draw3dAxis(OpenCV::Net::Arr ^image, Board ^board, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::cvarrToMat(image->DangerousGetHandle().ToPointer());
	aruco::CvDrawingUtils::draw3dAxis(cvimage, *(board->board), *(parameters->parameters));
}

void Aruco::Net::DrawingUtils::Draw3dCube(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::cvarrToMat(image->DangerousGetHandle().ToPointer());
	aruco::CvDrawingUtils::draw3dCube(cvimage, *(marker->marker), *(parameters->parameters));
}

void Aruco::Net::DrawingUtils::Draw3dCube(OpenCV::Net::Arr ^image, Board ^board, CameraParameters ^parameters)
{
	cv::Mat cvimage = cv::cvarrToMat(image->DangerousGetHandle().ToPointer());
	aruco::CvDrawingUtils::draw3dCube(cvimage, *(board->board), *(parameters->parameters));
}
