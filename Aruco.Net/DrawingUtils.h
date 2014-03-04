#pragma once

#include <cvdrawingutils.h>

#include "Marker.h"
#include "CameraParameters.h"
using namespace System;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Specifies visualization and debugging drawing methods.
		/// </summary>
		public ref class DrawingUtils
		{
		private:
			DrawingUtils();
		public:
			/// <summary>
			/// Draws a 3D reference axis on top of the input image.
			/// </summary>
			/// <param name="image">The image on which to draw the axis.</param>
			/// <param name="marker">The marker used to compute the axis position and orientation.</param>
			/// <param name="parameters">The camera intrinsic parameters.</param>
			static void Draw3dAxis(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters);

			/// <summary>
			/// Draws a 3D reference cube on top of the input image.
			/// </summary>
			/// <param name="image">The image on which to draw the cube.</param>
			/// <param name="marker">The marker used to compute the cube position and orientation.</param>
			/// <param name="parameters">The camera intrinsic parameters.</param>
			static void Draw3dCube(OpenCV::Net::Arr ^image, Marker ^marker, CameraParameters ^parameters);
		};
	}
}

