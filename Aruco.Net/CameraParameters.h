#pragma once

#include <cameraparameters.h>

using namespace System;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Represents the set of camera intrinsic parameters.
		/// </summary>
		public ref class CameraParameters
		{
		internal:
			aruco::CameraParameters *parameters;
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="CameraParameters"/> class.
			/// </summary>
			CameraParameters();

			/// <summary>
			/// Gets a copy of the camera parameters.
			/// </summary>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <param name="size">The resolution of the camera.</param>
			void CopyParameters(OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, [System::Runtime::InteropServices::Out]OpenCV::Net::Size %size);

			/// <summary>
			/// Sets the camera parameters.
			/// </summary>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <param name="size">The resolution of the camera.</param>
			void SetParameters(OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, OpenCV::Net::Size size);

			/// <summary>
			/// Reads the camera parameters from a file saved with <see cref="SaveToFile"/>.
			/// </summary>
			/// <param name="fileName">The file containing the camera parameters.</param>
			void ReadFromFile(String ^fileName);

			/// <summary>
			/// Saves the camera parameters to a file.
			/// </summary>
			/// <param name="fileName">The file on which to save the camera parameters.</param>
			void SaveToFile(String ^fileName);

			/// <summary>
			/// Saves the camera parameters to a file.
			/// </summary>
			/// <param name="fileName">The file on which to save the camera parameters.</param>
			/// <param name="inXml">A value indicating whether to use an XML format to save the file.</param>
			void SaveToFile(String ^fileName, bool inXml);

			/// <summary>
			/// Reads the camera parameters from a YAML file generated with the OpenCV
			/// calibration utility.
			/// </summary>
			/// <param name="fileName">The file containing the camera parameters.</param>
			void ReadFromXmlFile(String ^fileName);

			/// <summary>
			/// Adjusts the parameters to the specified image size.
			/// </summary>
			/// <param name="size">The image resolution used to scale the camera parameters.</param>
			void Resize(OpenCV::Net::Size size);
		};
	}
}

