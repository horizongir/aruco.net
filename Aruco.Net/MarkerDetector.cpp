// This is the main DLL file.

#include "stdafx.h"
#include <vector>
#include "MarkerDetector.h"

using namespace Aruco::Net;

Aruco::Net::MarkerDetector::MarkerDetector():
detector(new aruco::MarkerDetector())
{
}

Aruco::Net::MarkerDetector::~MarkerDetector()
{
	delete detector;
}

void Aruco::Net::MarkerDetector::CopyThresholdedImage(OpenCV::Net::Arr ^image)
{
	IntPtr handle = image->DangerousGetHandle();
	cv::Mat cvimage = cv::cvarrToMat(handle.ToPointer());
	detector->getThresholdedImage().copyTo(cvimage);
}

IList<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(OpenCV::Net::Arr ^input, CameraParameters ^parameters)
{
	return Detect(input, parameters, -1, true);
}

IList<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(OpenCV::Net::Arr ^input, CameraParameters ^parameters, float markerSizeMeters)
{
	return Detect(input, parameters, markerSizeMeters, true);
}

IList<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(OpenCV::Net::Arr ^input, CameraParameters ^parameters, float markerSizeMeters, bool setYPerpendicular)
{
	IntPtr handle = input->DangerousGetHandle();
	cv::Mat cvinput = cv::cvarrToMat(handle.ToPointer());

	std::vector<aruco::Marker> markers;
	detector->detect(cvinput, markers, *(parameters->parameters), markerSizeMeters, setYPerpendicular);

	List<Marker ^> ^detectedMarkers = gcnew List<Marker ^>(markers.size());
	std::vector<aruco::Marker>::const_iterator it;
	for (it = markers.begin(); it < markers.end(); it++)
	{
		detectedMarkers->Add(gcnew Marker(*it));
	}

	return detectedMarkers;
}

IList<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion)
{
	return Detect(input, cameraMatrix, distortion, -1, true);
}

IList<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters)
{
	return Detect(input, cameraMatrix, distortion, markerSizeMeters, true);
}

IList<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters, bool setYPerpendicular)
{
	IntPtr handle = input->DangerousGetHandle();
	cv::Mat cvinput = cv::cvarrToMat(handle.ToPointer());
	cv::Mat cvcamMatrix = cameraMatrix != nullptr ? cv::cvarrToMat(cameraMatrix->DangerousGetHandle().ToPointer()) : cv::Mat();
	cv::Mat cvdistortion = distortion != nullptr ? cv::cvarrToMat(distortion->DangerousGetHandle().ToPointer()) : cv::Mat();

	std::vector<aruco::Marker> markers;
	detector->detect(cvinput, markers, cvcamMatrix, cvdistortion, markerSizeMeters, setYPerpendicular);

	List<Marker ^> ^detectedMarkers = gcnew List<Marker ^>(markers.size());
	std::vector<aruco::Marker>::const_iterator it;
	for (it = markers.begin(); it < markers.end(); it++)
	{
		detectedMarkers->Add(gcnew Marker(*it));
	}

	return detectedMarkers;
}