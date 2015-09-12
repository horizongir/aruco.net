#include "StdAfx.h"
#include "BoardDetector.h"

using namespace Aruco::Net;
using namespace System::Runtime::InteropServices;

Aruco::Net::BoardDetector::BoardDetector():
detector(new aruco::BoardDetector())
{
}

Aruco::Net::BoardDetector::!BoardDetector()
{
	delete detector;
}

Board ^ Aruco::Net::BoardDetector::Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, CameraParameters ^parameters)
{
	return Detect(detectedMarkers, boardConfiguration, parameters, -1);
}

Board ^ Aruco::Net::BoardDetector::Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, CameraParameters ^parameters, float markerSizeMeters)
{
	std::vector<aruco::Marker> markers;
	for each (Marker ^marker in detectedMarkers)
	{
		markers.push_back(*marker->marker);
	}

	aruco::BoardConfiguration bConfig;
	bConfig.mInfoType = (int)boardConfiguration->MarkerInfoType;
	for each (MarkerInfo ^markerInfo in boardConfiguration->Markers)
	{
		bConfig.push_back(*markerInfo->markerInfo);
	}

	aruco::Board bDetected;
	float likelihood = detector->detect(markers, bConfig, bDetected, *(parameters->parameters), markerSizeMeters);
	return gcnew Board(bDetected, likelihood);
}

Board ^ Aruco::Net::BoardDetector::Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion)
{
	return Detect(detectedMarkers, boardConfiguration, cameraMatrix, distortion, -1);
}

Board ^ Aruco::Net::BoardDetector::Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters)
{
	cv::Mat cvcamMatrix = cameraMatrix != nullptr ? cv::cvarrToMat(cameraMatrix->DangerousGetHandle().ToPointer()) : cv::Mat();
	cv::Mat cvdistortion = distortion != nullptr ? cv::cvarrToMat(distortion->DangerousGetHandle().ToPointer()) : cv::Mat();

	std::vector<aruco::Marker> markers;
	for each (Marker ^marker in detectedMarkers)
	{
		markers.push_back(*marker->marker);
	}

	aruco::BoardConfiguration bConfig;
	bConfig.mInfoType = (int)boardConfiguration->MarkerInfoType;
	for each (MarkerInfo ^markerInfo in boardConfiguration->Markers)
	{
		bConfig.push_back(*markerInfo->markerInfo);
	}

	aruco::Board bDetected;
	float likelihood = detector->detect(markers, bConfig, bDetected, cvcamMatrix, cvdistortion, markerSizeMeters);
	return gcnew Board(bDetected, likelihood);
}