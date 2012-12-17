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

void Aruco::Net::MarkerDetector::CopyThresholdedImage(IntPtr image)
{
	cv::Mat cvimage = cv::Mat((IplImage*)image.ToPointer());
	detector->getThresholdedImage().copyTo(cvimage);
}

IEnumerable<Marker ^> ^ Aruco::Net::MarkerDetector::Detect(IntPtr input, IntPtr cameraMatrix, IntPtr distortion, float markerSizeMeters)
{
	cv::Mat cvinput = cv::Mat((IplImage*)input.ToPointer());
	cv::Mat cvcamMatrix = cameraMatrix != IntPtr::Zero ? cv::Mat((CvMat*)cameraMatrix.ToPointer()) : cv::Mat();
	cv::Mat cvdistortion = distortion != IntPtr::Zero ? cv::Mat((CvMat*)distortion.ToPointer()) : cv::Mat();

	std::vector<aruco::Marker> markers;
	detector->detect(cvinput,markers,cvcamMatrix,cvdistortion,markerSizeMeters);

	List<Marker ^> ^detectedMarkers = gcnew List<Marker ^>(markers.size());
	std::vector<aruco::Marker>::const_iterator it;
	for (it = markers.begin(); it < markers.end(); it++)
	{
		detectedMarkers->Add(gcnew Marker(*it));
	}

	return detectedMarkers;
}