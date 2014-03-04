#pragma once

#include <marker.h>

using namespace System;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Represents a fiducial marker, defined by a vector of its four corners.
		/// </summary>
		public ref class Marker
		{
		internal:
			aruco::Marker *marker;
		internal:
			Marker(const aruco::Marker &marker);
		public:
			~Marker();

			/// <summary>
			/// Gets the id of the marker.
			/// </summary>
			property int Id {
				int get() { return marker->id; }
			}

			/// <summary>
			/// Gets the size of the marker sides, in meters.
			/// </summary>
			property float Size {
				float get() { return marker->ssize; }
			}

			/// <summary>
			/// Gets a value indicating whether the marker is valid.
			/// </summary>
			property bool IsValid {
				bool get() { return marker->isValid(); }
			}

			/// <summary>
			/// Gets the centroid of the marker in image space.
			/// </summary>
			property OpenCV::Net::Point2f Center {
				OpenCV::Net::Point2f get() { return *((OpenCV::Net::Point2f*)&marker->getCenter()); }
			}

			/// <summary>
			/// Gets the perimeter of the marker.
			/// </summary>
			property float Perimeter {
				float get() { return marker->getPerimeter(); }
			}

			/// <summary>
			/// Gets the area of the marker.
			/// </summary>
			property float Area {
				float get() { return marker->getArea(); }
			}

			/// <summary>
			/// Draws this marker in the input image.
			/// </summary>
			/// <param name="image">The image on which to draw the marker.</param>
			/// <param name="color">The color used to draw the marker.</param>
			void Draw(OpenCV::Net::Arr ^image, OpenCV::Net::Scalar color);

			/// <summary>
			/// Draws this marker in the input image.
			/// </summary>
			/// <param name="image">The image on which to draw the marker.</param>
			/// <param name="color">The color used to draw the marker.</param>
			/// <param name="lineWidth">The width of the lines used to draw the marker.</param>
			void Draw(OpenCV::Net::Arr ^image, OpenCV::Net::Scalar color, int lineWidth);

			/// <summary>
			/// Draws this marker in the input image.
			/// </summary>
			/// <param name="image">The image on which to draw the marker.</param>
			/// <param name="color">The color used to draw the marker.</param>
			/// <param name="lineWidth">The width of the lines used to draw the marker.</param>
			/// <param name="writeId">A value indicating whether to draw the marker id.</param>
			void Draw(OpenCV::Net::Arr ^image, OpenCV::Net::Scalar color, int lineWidth, bool writeId);

			/// <summary>
			/// Returns the modelview matrix for the marker given the extrinsic camera
			/// parameters in OpenGL format.
			/// </summary>
			/// <returns>
			/// The modelview matrix for the marker given the extrinsic camera parameters.
			/// </returns>
			cli::array<double> ^ GetGLModelViewMatrix();
		};
	}
}

