#include "StdAfx.h"
#include "CameraParameters.h"

using namespace System::Runtime::InteropServices;

Aruco::Net::CameraParameters::CameraParameters():
parameters(new aruco::CameraParameters())
{
}

void Aruco::Net::CameraParameters::CopyParameters(OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion)
{
	cv::Mat cameraMat = cv::cvarrToMat(cameraMatrix->DangerousGetHandle().ToPointer());
	cv::Mat distortionMat = cv::cvarrToMat(distortion->DangerousGetHandle().ToPointer());
	(parameters->CameraMatrix).copyTo(cameraMat);
	(parameters->Distorsion).copyTo(distortionMat);
}

void Aruco::Net::CameraParameters::ReadFromXmlFile(String ^fileName)
{
	IntPtr hFileName = Marshal::StringToHGlobalAnsi(fileName);
	std::string filePath((char *)hFileName.ToPointer());
	parameters->readFromXMLFile(filePath);
	Marshal::FreeHGlobal(hFileName);
}