#pragma once

#include <cameraparameters.h>

using namespace System;

namespace Aruco
{
	namespace Net
	{
		public ref class CameraParameters
		{
		internal:
			aruco::CameraParameters *parameters;
		public:
			CameraParameters();

			void GetParams(OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, [System::Runtime::InteropServices::Out]OpenCV::Net::Size %size);
			void SetParams(OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, OpenCV::Net::Size size);

			void ReadFromFile(String ^fileName);
			void SaveToFile(String ^fileName);
			void SaveToFile(String ^fileName, bool inXml);
			void ReadFromXmlFile(String ^fileName);
			void Resize(OpenCV::Net::Size size);
		};
	}
}

