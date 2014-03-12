#include "StdAfx.h"
#include "BoardConfiguration.h"

using namespace System::Runtime::InteropServices;

void Aruco::Net::BoardConfiguration::SaveToFile(String ^fileName)
{
	IntPtr hFileName = Marshal::StringToHGlobalAnsi(fileName);
	std::string filePath((char *)hFileName.ToPointer());

	aruco::BoardConfiguration bConfig;
	bConfig.mInfoType = (int)markerInfoType;
	for each (MarkerInfo ^markerInfo in markers)
	{
		bConfig.push_back(*markerInfo->markerInfo);
	}

	bConfig.saveToFile(filePath);
	Marshal::FreeHGlobal(hFileName);
}

void Aruco::Net::BoardConfiguration::ReadFromFile(String ^fileName)
{
	IntPtr hFileName = Marshal::StringToHGlobalAnsi(fileName);
	std::string filePath((char *)hFileName.ToPointer());

	aruco::BoardConfiguration bConfig;
	bConfig.readFromFile(filePath);
	Marshal::FreeHGlobal(hFileName);

	markerInfoType = (Aruco::Net::MarkerInfoType)bConfig.mInfoType;
	std::vector<aruco::MarkerInfo>::const_iterator it;
	for (it = bConfig.begin(); it != bConfig.end(); it++)
	{
		markers->Add(gcnew MarkerInfo(*it));
	}
}