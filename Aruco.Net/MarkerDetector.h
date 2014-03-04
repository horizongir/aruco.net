// Aruco.Net.h

#pragma once

#include <markerdetector.h>

#include "Marker.h"
using namespace System;
using namespace System::Collections::Generic;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// Specifies the available image thresholding methods.
		/// </summary>
		public enum class ThresholdMethod
		{
			/// <summary>
			/// Specifies a segmentation method based on a fixed threshold.
			/// </summary>
			FixedThreshold = aruco::MarkerDetector::FIXED_THRES,

			/// <summary>
			/// Specifies a segmentation method based on an adaptive threshold.
			/// </summary>
			AdaptiveThreshold = aruco::MarkerDetector::ADPT_THRES,

			/// <summary>
			/// Specifies a segmentation method based on the Canny edge detector.
			/// </summary>
			Canny = aruco::MarkerDetector::CANNY
		};

		/// <summary>
		/// Specifies the available methods for corner refinement.
		/// </summary>
		public enum class CornerRefinementMethod
		{
			/// <summary>
			/// Specifies that no corner refinement should be performed.
			/// </summary>
			None = aruco::MarkerDetector::NONE,

			/// <summary>
			/// Specifies a corner refinement method based on the Harris operator.
			/// </summary>
			Harris = aruco::MarkerDetector::HARRIS,

			/// <summary>
			/// Specifies a corner refinement method with sub-pixel accuracy.
			/// </summary>
			SubPix = aruco::MarkerDetector::SUBPIX,

			/// <summary>
			/// Specifies a corner refinement method based on interpolating contour lines.
			/// </summary>
			Lines = aruco::MarkerDetector::LINES
		};

		/// <summary>
		/// Represents the marker detection procedure.
		/// </summary>
		public ref class MarkerDetector
		{
		private:
			aruco::MarkerDetector *detector;
		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="MarkerDetector"/> class.
			/// </summary>
			MarkerDetector();

			/// <summary>
			/// Releases unmanaged resources associated with the marker detector.
			/// </summary>
			~MarkerDetector();

			/// <summary>
			/// Gets or sets the threshold method.
			/// </summary>
			property ThresholdMethod ThresholdType {
				ThresholdMethod get() { return (ThresholdMethod)detector->getThresholdMethod(); }
				void set(ThresholdMethod value) { detector->setThresholdMethod((aruco::MarkerDetector::ThresholdMethods)value); }
			}

			/// <summary>
			/// Gets or sets the first parameter of the threshold method.
			/// </summary>
			property double Param1 {
				double get()
				{
					double p1, p2;
					detector->getThresholdParams(p1,p2);
					return p1;
				}
				void set(double value)
				{
					double p1, p2;
					detector->getThresholdParams(p1,p2);
					detector->setThresholdParams(value,p2);
				}
			}

			/// <summary>
			/// Gets or sets the second parameter of the threshold method.
			/// </summary>
			property double Param2 {
				double get()
				{
					double p1, p2;
					detector->getThresholdParams(p1,p2);
					return p2;
				}
				void set(double value)
				{
					double p1, p2;
					detector->getThresholdParams(p1,p2);
					detector->setThresholdParams(p1,value);
				}
			}

			/// <summary>
			/// Gets or sets the minimum marker size as a fraction of the image size.
			/// </summary>
			property float MinSize {
				float get()
				{
					float minSize, maxSize;
					detector->getMinMaxSize(minSize,maxSize);
					return minSize;
				}
				void set(float value)
				{
					float minSize, maxSize;
					detector->getMinMaxSize(minSize,maxSize);
					detector->setMinMaxSize(value,maxSize);
				}
			}

			/// <summary>
			/// Gets or sets the maximum marker size as a fraction of the image size.
			/// </summary>
			property float MaxSize {
				float get()
				{
					float minSize, maxSize;
					detector->getMinMaxSize(minSize,maxSize);
					return maxSize;
				}
				void set(float value)
				{
					float minSize, maxSize;
					detector->getMinMaxSize(minSize,maxSize);
					detector->setMinMaxSize(minSize,value);
				}
			}

			/// <summary>
			/// Gets or sets the corner refinement method.
			/// </summary>
			property CornerRefinementMethod CornerRefinement {
				CornerRefinementMethod get() { return (CornerRefinementMethod)detector->getCornerRefinementMethod(); }
				void set(CornerRefinementMethod value) { detector->setCornerRefinementMethod((aruco::MarkerDetector::CornerRefinementMethod)value); }
			}

			/// <summary>
			/// Gets or sets the desired speed of internal processes. If you need maximum speed at
			/// the cost of a lower detection rate set it to 3, otherwise use 0 for a precise but
			/// slow detection.
			/// </summary>
			property int DesiredSpeed {
				int get() { return detector->getDesiredSpeed(); }
				void set(int value) { detector->setDesiredSpeed(value); }
			}

			/// <summary>
			/// Copies the thresholding result into the specified image for visualization and
			/// calibration purposes.
			/// </summary>
			/// <param name="image">The destination image for the thresholding result.</param>
			void CopyThresholdedImage(OpenCV::Net::Arr ^image);

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="input">The source image on which to look for markers.</param>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <returns>
			/// A list of detected fiducial markers in the specified image.
			/// </returns>
			IList<Marker ^> ^ Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion);

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="input">The source image on which to look for markers.</param>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <param name="markerSizeMeters">The size of the marker sides, in meters.</param>
			/// <returns>
			/// A list of detected fiducial markers in the specified image.
			/// </returns>
			IList<Marker ^> ^ Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters);

			/// <summary>
			/// Detects fiducial markers in the specified image.
			/// </summary>
			/// <param name="input">The source image on which to look for markers.</param>
			/// <param name="cameraMatrix">The 3x3 camera matrix.</param>
			/// <param name="distortion">The 4x1 lens distortion matrix.</param>
			/// <param name="markerSizeMeters">The size of the marker sides, in meters.</param>
			/// <param name="setYPerpendicular">
			/// A value indicating which axis represents the surface normal. If true, the Y axis
			/// will be set perpendicular to the surface; otherwise, the Z axis will be used.
			/// </param>
			/// <returns>
			/// A list of detected fiducial markers in the specified image.
			/// </returns>
			IList<Marker ^> ^ Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters, bool setYPerpendicular);
		};
	}
}
