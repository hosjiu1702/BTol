// BTol.h

#pragma once

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>


//using namespace System;

namespace BTol {

	public ref class Btol
	{
		// TODO: Add your methods for this class here.
	private:
		System::String^ _nameOfVideoFile_Managed;
		//cv::VideoCapture* video = NULL;
	public:
		/* Constructor */
		Btol();
		Btol(System::String^ nameOfVideoFile);

		/* Destructor */
		~Btol();

		System::Drawing::Bitmap^ ApplyOtsuThresholdingAlgorithm();
		void Testing();
		System::Drawing::Bitmap^ RunAnalysis(System::Drawing::Bitmap^ bitmap);

		//bool checkFrame();
	};
}
