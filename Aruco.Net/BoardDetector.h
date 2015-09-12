// Aruco.Net.h

#pragma once

#include <boarddetector.h>

#include "Board.h"
#include "BoardConfiguration.h"
#include "CameraParameters.h"
using namespace System;
using namespace System::Collections::Generic;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Represents the marker board detection procedure.
		/// </summary>
		public ref class BoardDetector
		{
		private:
			aruco::BoardDetector *detector;
			~BoardDetector() { this->!BoardDetector(); }
			!BoardDetector();
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="BoardDetector"/> class.
			/// </summary>
			BoardDetector();

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="detectedMarkers">The list of previously detected fiducial markers.</param>
			/// <param name="boardConfiguration">The configuration of the marker board.</param>
			/// <param name="parameters">The intrinsic camera parameters.</param>
			/// <returns>
			/// The detected marker board.
			/// </returns>
			Board ^ Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, CameraParameters ^parameters);

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="detectedMarkers">The list of previously detected fiducial markers.</param>
			/// <param name="boardConfiguration">The configuration of the marker board.</param>
			/// <param name="parameters">The intrinsic camera parameters.</param>
			/// <param name="markerSizeMeters">The size of the marker sides, in meters.</param>
			/// <returns>
			/// The detected marker board.
			/// </returns>
			Board ^ Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, CameraParameters ^parameters, float markerSizeMeters);

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="detectedMarkers">The list of previously detected fiducial markers.</param>
			/// <param name="boardConfiguration">The configuration of the marker board.</param>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <returns>
			/// The detected marker board.
			/// </returns>
			Board ^ Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion);

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="detectedMarkers">The list of previously detected fiducial markers.</param>
			/// <param name="boardConfiguration">The configuration of the marker board.</param>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <param name="markerSizeMeters">The size of the marker sides, in meters.</param>
			/// <returns>
			/// The detected marker board.
			/// </returns>
			Board ^ Detect(IList<Marker ^> ^detectedMarkers, BoardConfiguration ^boardConfiguration, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters);
		};
	}
}