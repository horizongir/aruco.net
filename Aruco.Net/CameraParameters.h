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

			void CopyParameters(OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion);
			void ReadFromFile(String ^fileName);
			void SaveToFile(String ^fileName);
			void SaveToFile(String ^fileName, bool inXml);
			void ReadFromXmlFile(String ^fileName);
			void Resize(OpenCV::Net::Size size);
		};
	}
}

