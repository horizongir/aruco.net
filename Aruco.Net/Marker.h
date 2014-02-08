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

			property int Id {
				int get() { return marker->id; }
			}

			property float Size {
				float get() { return marker->ssize; }
			}

			property bool IsValid {
				bool get() { return marker->isValid(); }
			}

			property OpenCV::Net::Point2f Center {
				OpenCV::Net::Point2f get() { return *((OpenCV::Net::Point2f*)&marker->getCenter()); }
			}

			property float Perimeter {
				float get() { return marker->getPerimeter(); }
			}

			property float Area {
				float get() { return marker->getArea(); }
			}

			void Draw(OpenCV::Net::Arr ^in, OpenCV::Net::Scalar color, int lineWidth, bool writeId);

			cli::array<double> ^ GetGLModelViewMatrix();
		};
	}
}

