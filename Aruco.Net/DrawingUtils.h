#pragma once

#include <cvdrawingutils.h>

#include "Marker.h"
#include "CameraParameters.h"
using namespace System;

namespace Aruco
{
	namespace Net
	{
		public ref class DrawingUtils
		{
		private:
			DrawingUtils();
		public:
			static void Draw3dAxis(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters);
			static void Draw3dCube(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters);
		};
	}
}

