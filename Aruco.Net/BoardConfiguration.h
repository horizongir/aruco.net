#pragma once

#include <board.h>
#include "MarkerInfo.h"

using namespace System;
using namespace System::Collections::Generic;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Specifies the units that marker position information is expressed in
		/// for internal processing.
		/// </summary>
		public enum class MarkerInfoType
		{
			/// <summary>
			/// Specifies that the units of marker position are not specified.
			/// </summary>
			None = aruco::BoardConfiguration::NONE,

			/// <summary>
			/// Specifies that the marker position information is expressed in pixels.
			/// </summary>
			Pixels = aruco::BoardConfiguration::PIX,

			/// <summary>
			/// Specifies that the marker position information is expressed in meters.
			/// </summary>
			Meters = aruco::BoardConfiguration::METERS
		};

		/// <summary>
		/// Represents the 3D configuration of a marker board.
		/// </summary>
		public ref class BoardConfiguration
		{
		private:
			Aruco::Net::MarkerInfoType markerInfoType;
			List<MarkerInfo ^> ^markers;
		public:
			/// <summary>
			/// Gets the units used to specify each marker position.
			/// </summary>
			property Aruco::Net::MarkerInfoType MarkerInfoType {
				Aruco::Net::MarkerInfoType get() { return markerInfoType; }
				void set(Aruco::Net::MarkerInfoType value) { markerInfoType = value; }
			}

			/// <summary>
			/// Gets the configuration list of markers contained in the marker board.
			/// </summary>
			property IList<MarkerInfo ^> ^ Markers {
				IList<MarkerInfo ^> ^ get() { return markers; }
			}

			/// <summary>
			/// Saves the marker board configuration to a file.
			/// </summary>
			/// <param name="fileName">The file on which to save the board configuration.</param>
			void SaveToFile(String ^fileName);

			/// <summary>
			/// Reads the marker board configuration from a file saved with <see cref="SaveToFile"/>.
			/// </summary>
			/// <param name="fileName">The file containing the board configuration.</param>
			void ReadFromFile(String ^fileName);
		};
	}
}