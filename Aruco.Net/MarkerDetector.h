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
		public enum class ThresholdMethod
		{
			FixedThreshold = aruco::MarkerDetector::FIXED_THRES,
			AdaptiveThreshold = aruco::MarkerDetector::ADPT_THRES,
			Canny = aruco::MarkerDetector::CANNY
		};

		public enum class CornerRefinementMethod
		{
			None = aruco::MarkerDetector::NONE,
			Harris = aruco::MarkerDetector::HARRIS,
			SubPix = aruco::MarkerDetector::SUBPIX
		};

		public ref class MarkerDetector
		{
		private:
			aruco::MarkerDetector *detector;
		public:
			MarkerDetector();
			~MarkerDetector();

			property ThresholdMethod ThresholdType {
				ThresholdMethod get() { return (ThresholdMethod)detector->getThresholdMethod(); }
				void set(ThresholdMethod value) { detector->setThresholdMethod((aruco::MarkerDetector::ThresholdMethods)value); }
			}

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

			property CornerRefinementMethod CornerRefinement {
				CornerRefinementMethod get() { return (CornerRefinementMethod)detector->getCornerRefinementMethod(); }
				void set(CornerRefinementMethod value) { detector->setCornerRefinementMethod((aruco::MarkerDetector::CornerRefinementMethod)value); }
			}

			property int DesiredSpeed {
				int get() { return detector->getDesiredSpeed(); }
				void set(int value) { detector->setDesiredSpeed(value); }
			}

			void CopyThresholdedImage(OpenCV::Net::Arr ^image);
			IList<Marker ^> ^ Detect(OpenCV::Net::Arr ^input, OpenCV::Net::Mat ^cameraMatrix, OpenCV::Net::Mat ^distortion, float markerSizeMeters);
		};
	}
}
