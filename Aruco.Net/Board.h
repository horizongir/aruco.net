#pragma once

#include <board.h>

#include "Marker.h"
using namespace System;
using namespace System::Collections::Generic;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Represents a marker board, defined by a collection of fiducial markers.
		/// </summary>
		public ref class Board
		{
		private:
			List<Marker ^> ^markers;
			float likelihood;
		internal:
			aruco::Board *board;
			Board(const aruco::Board &board, float likelihood);

		public:
			/// <summary>
			/// Releases unmanaged resources associated with the marker board.
			/// </summary>
			~Board();

			/// <summary>
			/// Gets the likelihood of having found the marker board.
			/// </summary>
			property float Likelihood {
				float get() { return likelihood; }
			}

			/// <summary>
			/// Gets the list of markers contained in the marker board.
			/// </summary>
			property IReadOnlyList<Marker ^> ^ Markers {
				virtual IReadOnlyList<Marker ^> ^ get() { return markers; }
			}

			/// <summary>
			/// Returns the modelview matrix for the marker board given the extrinsic camera
			/// parameters in OpenGL format.
			/// </summary>
			/// <returns>
			/// The modelview matrix for the marker board given the extrinsic camera parameters.
			/// </returns>
			cli::array<double> ^ GetGLModelViewMatrix();
		};
	}
}