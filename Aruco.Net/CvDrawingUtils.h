#pragma once

#include <cvdrawingutils.h>

#include "Marker.h"
#include "CameraParameters.h"
using namespace System;

namespace Aruco
{
	namespace Net
	{
		public ref class CvDrawingUtils
		{
		private:
			CvDrawingUtils();
		public:
			static void Draw3dAxis(IntPtr image, Marker ^marker, CameraParameters ^parameters);
			static void Draw3dCube(IntPtr image, Marker ^marker, CameraParameters ^parameters);
		};
	}
}

