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

			void CopyParameters(IntPtr cameraMatrix, IntPtr distortion);
			void ReadFromXmlFile(String ^fileName);
		};
	}
}

