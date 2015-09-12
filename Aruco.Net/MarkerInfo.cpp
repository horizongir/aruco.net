#include "StdAfx.h"
#include "MarkerInfo.h"

using namespace System::Runtime::InteropServices;

Aruco::Net::MarkerInfo::MarkerInfo():
	markerInfo(new aruco::MarkerInfo())
{
}

Aruco::Net::MarkerInfo::MarkerInfo(const aruco::MarkerInfo& markerInfo):
	markerInfo(new aruco::MarkerInfo(markerInfo))
{
}

Aruco::Net::MarkerInfo::!MarkerInfo()
{
	delete markerInfo;
}

void Aruco::Net::MarkerInfo::Clear()
{
	markerInfo->clear();
}

void Aruco::Net::MarkerInfo::Add(OpenCV::Net::Point3f position)
{
	markerInfo->push_back(cv::Point3f(position.X, position.Y, position.Z));
}

bool Aruco::Net::MarkerInfo::Remove(OpenCV::Net::Point3f position)
{
	cv::Point3f positionToRemove = cv::Point3f(position.X, position.Y, position.Z);
	std::vector<cv::Point3f>::iterator end = markerInfo->end();
	std::vector<cv::Point3f>::iterator newEnd = std::remove(markerInfo->begin(), end, positionToRemove);
	markerInfo->erase(newEnd);
	return end != newEnd;
}

bool Aruco::Net::MarkerInfo::Contains(OpenCV::Net::Point3f position)
{
	cv::Point3f positionToFind = cv::Point3f(position.X, position.Y, position.Z);
	auto iter = std::find(markerInfo->begin(), markerInfo->end(), positionToFind);
	return iter != markerInfo->end();
}

int Aruco::Net::MarkerInfo::IndexOf(OpenCV::Net::Point3f position)
{
	cv::Point3f positionToFind = cv::Point3f(position.X, position.Y, position.Z);
	auto iter = std::find(markerInfo->begin(), markerInfo->end(), positionToFind);
	int index = std::distance(markerInfo->begin(), iter);
	return index == markerInfo->size() ? -1 : index;
}

void Aruco::Net::MarkerInfo::Insert(int index, OpenCV::Net::Point3f position)
{
	markerInfo->insert(markerInfo->begin() + index, cv::Point3f(position.X, position.Y, position.Z));
}

void Aruco::Net::MarkerInfo::RemoveAt(int index)
{
	markerInfo->erase(markerInfo->begin() + index);
}

void Aruco::Net::MarkerInfo::CopyTo(cli::array<OpenCV::Net::Point3f, 1> ^array, int arrayIndex)
{
	if (array == nullptr)
	{
		throw gcnew System::ArgumentNullException("array");
	}

	if (arrayIndex < 0)
	{
		throw gcnew System::ArgumentOutOfRangeException("arrayIndex");
	}

	int lastIndex = arrayIndex + markerInfo->size();
	if (lastIndex >= array->Length)
	{
		throw gcnew System::ArgumentException("The number of elements in the collection is greater than the available array space.", "array");
	}

	std::vector<cv::Point3f>::iterator it;
	for (it = markerInfo->begin(); it != markerInfo->end(); it++, arrayIndex++)
	{
		array[arrayIndex] = *((OpenCV::Net::Point3f*)&(*it));
	}
}