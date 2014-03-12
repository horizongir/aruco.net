#pragma once

#include <board.h>

using namespace System;
using namespace System::Collections::Generic;

namespace Aruco
{
	namespace Net
	{
		/// <summary>
		/// The 3D representation of a marker in a marker board.
		/// </summary>
		public ref class MarkerInfo : public IList<OpenCV::Net::Point3f>
		{
		internal:
			aruco::MarkerInfo *markerInfo;
			MarkerInfo(const aruco::MarkerInfo& markerInfo);
			virtual System::Collections::IEnumerator ^ GetEnumeratorNonGeneric() = System::Collections::IEnumerable::GetEnumerator
			{
				return GetEnumerator();
			}

			property bool IsReadOnly {
				virtual bool get() = IList<OpenCV::Net::Point3f>::IsReadOnly::get { return false; }
			}

		public:
			/// <summary>
			/// Initializes a new instance of the <see cref="MarkerInfo"/> class.
			/// </summary>
			MarkerInfo();

			/// <summary>
			/// Releases unmanaged resources associated with the marker.
			/// </summary>
			~MarkerInfo();

			/// <summary>
			/// Gets or sets the id of the marker.
			/// </summary>
			property int Id {
				int get() { return markerInfo->id; }
				void set(int value) { markerInfo->id = value; }
			}

			/// <summary>
			/// Gets or sets the corner at the specified index.
			/// </summary>
			property OpenCV::Net::Point3f default[int] {
				virtual OpenCV::Net::Point3f get(int index) { return *((OpenCV::Net::Point3f*)&markerInfo->at(index)); }
				virtual void set(int index, OpenCV::Net::Point3f value) { (*markerInfo)[index] = cv::Point3f(value.X, value.Y, value.Z); }
			}

			/// <summary>
			/// Gets the number of corners contained in the marker.
			/// </summary>
			property int Count {
				virtual int get() { return markerInfo->size(); }
			}

			/// <summary>
			/// Removes all corners from the marker.
			/// </summary>
			virtual void Clear();

			/// <summary>
			/// Adds a corner to the marker definition.
			/// </summary>
			/// <param name="position">The position of the corner to add to the definition.</param>
			virtual void Add(OpenCV::Net::Point3f position);

			/// <summary>
			/// Removes a corner from the marker definition.
			/// </summary>
			/// <param name="position">The position of the corner to remove from the definition.</param>
			/// <returns>
			/// <b>true</b> if the corner was successfully removed from the marker definition;
			/// otherwise, false.
			/// </returns>
			virtual bool Remove(OpenCV::Net::Point3f position);

			/// <summary>
			/// Determines whether the marker definition contains the specified corner position.
			/// </summary>
			/// <param name="position">The position of the corner to locate in the definition.</param>
			/// <returns>
			/// <b>true</b> if the corner was found in the marker definition; otherwise, false.
			/// </returns>
			virtual bool Contains(OpenCV::Net::Point3f position);

			/// <summary>
			/// Determines the index of a specific corner in the marker definition.
			/// </summary>
			/// <param name="position">The position of the corner to locate in the definition.</param>
			/// <returns>
			/// The index of the corner if found in the marker definition; otherwise, -1.
			/// </returns>
			virtual int IndexOf(OpenCV::Net::Point3f position);

			/// <summary>
			/// Inserts a corner in the marker definition at the specified index.
			/// </summary>
			/// <param name="index">The zero-based index at which the corner should be inserted.</param>
			/// <param name="position">The position of the corner to insert into the definition.</param>
			virtual void Insert(int index, OpenCV::Net::Point3f position);

			/// <summary>
			/// Removes the corner at the specified index.
			/// </summary>
			/// <param name="index">The zero-based index of the corner to remove.</param>
			virtual void RemoveAt(int index);

			/// <summary>
			/// Copies the corners in the marker definition to an <see cref="System.Array"/>,
			/// starting at a particular <see cref="System.Array"/> index.
			/// </summary>
			/// <param name="array">
			/// The one-dimensional <see cref="System.Array"/> that is the destination of
			/// the corner positions copied from the marker definition.
			/// </param>
			/// <param name="arrayIndex">The zero-based index in array at which copying begins.</param>
			virtual void CopyTo(cli::array<OpenCV::Net::Point3f, 1> ^array, int arrayIndex);

			/// <summary>
			/// Returns an enumerator that iterates through the marker corners.
			/// </summary>
			/// <returns>
			/// An enumerator instance that can be used to iterate through the marker corners.
			/// </returns>
			virtual IEnumerator<OpenCV::Net::Point3f> ^ GetEnumerator()
			{
				return gcnew PositionEnumerator(markerInfo);
			}

		private:
			ref class PositionEnumerator : public IEnumerator<OpenCV::Net::Point3f>
			{
				internal:
					int index;
					aruco::MarkerInfo *markerInfo;
					PositionEnumerator(aruco::MarkerInfo *markerInfo):
						markerInfo(markerInfo),
					    index(-1)
					{
					}

					property Object ^ CurrentNonGeneric {
						virtual Object ^ get() = System::Collections::IEnumerator::Current::get { return Current; }
					}

				public:
					~PositionEnumerator() { }
					virtual void Reset() { index = -1; }

					property OpenCV::Net::Point3f Current {
						virtual OpenCV::Net::Point3f get() { return *((OpenCV::Net::Point3f*)&markerInfo->at(index)); }
					}

					virtual bool MoveNext()
					{
						return ++index < markerInfo->size();
					}
			};
		};
	}
}