#pragma once

#include <marker.h>

using namespace System;

namespace Aruco
{
	namespace Net
	{
		public ref class Marker
		{
		internal:
			aruco::Marker *marker;
		internal:
			Marker(const aruco::Marker &marker);
		public:
			~Marker();

			void Draw(IntPtr in, double c0, double c1, double c2, int lineWidth, bool writeId);
			cli::array<double> ^ GetGLModelViewMatrix();

			property int Id {
				int get() { return marker->id; }
			}
		};
	}
}

