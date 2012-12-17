#include "StdAfx.h"
#include "CameraParameters.h"

using namespace System::Runtime::InteropServices;

Aruco::Net::CameraParameters::CameraParameters():
parameters(new aruco::CameraParameters())
{
}

void Aruco::Net::CameraParameters::CopyParameters(IntPtr cameraMatrix, IntPtr distortion)
{
	cv::Mat cameraMat = cv::Mat((CvMat*)cameraMatrix.ToPointer());
	cv::Mat distortionMat = cv::Mat((CvMat*)distortion.ToPointer());
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