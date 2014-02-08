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
			void ReadFromXmlFile(String ^fileName);
		};
	}
}

