// This is the main DLL file.

#include "stdafx.h"
#using <System.Threading.dll>

#include "BTol.h"
#include "MatToBitmap.h"
#include "BitmapToMat.h"
#include "OtsuForm1.h"
#include "TestingForm.h"

#include "msclr\marshal_cppstd.h"
#include <iostream>

using namespace std;
using namespace cv;
using namespace System;
using namespace BTol;

//using namespace WindowsFormsApp1;

/* Constructor */

Btol::Btol()
{
	_nameOfVideoFile_Managed = nullptr;
}

Btol::Btol(System::String^ nameOfVideoFile)
{
	_nameOfVideoFile_Managed = nameOfVideoFile;

	// Chuyen kieu Managed String -> Native String
	msclr::interop::marshal_context context;
	std::string _nameOfVideoFile_Native = context.marshal_as<std::string>(_nameOfVideoFile_Managed);

	//video->open(_nameOfVideoFile_Native);
}

Btol::~Btol()
{
	
}

System::Drawing::Bitmap^ BTol::Btol::ApplyOtsuThresholdingAlgorithm()
{

	if (_nameOfVideoFile_Managed == nullptr)
	{
		return nullptr;
	}

	// Chuyen kieu Managed String -> Native String
	msclr::interop::marshal_context context;
	std::string _nameOfVideoFile_Native = context.marshal_as<std::string>(_nameOfVideoFile_Managed);
	
	// Khoi tao doi tuong VideoCapture
	cv::VideoCapture video(_nameOfVideoFile_Native);
	
	if (!video.isOpened())
	{
		cout << "Video is not opened" << endl;
		return nullptr;
	}
	
	//OtsuForm^ form = gcnew OtsuForm();
	//form->Show();
	//form->ShowDialog();
	//Application::Run();

	while (true)
	{
		Mat frame;
		video >> frame;

		if (frame.empty())
		{
			cout << "No frame is available" << endl;
			break;
		}

		/* Ap dung phan nguong Otsu */
		Mat grayFrame;
		//cvtColor(frame, grayFrame, COLOR_BGR2GRAY);
		//threshold(grayFrame, grayFrame, 0, 255, CV_THRESH_BINARY | CV_THRESH_OTSU);

		/* Chuyen Mat -> Bitmap */
		//System::Drawing::Bitmap^ bitmapFrame = MatToBitmap(frame);
		//System::Drawing::Bitmap^ bitmapFrame = gcnew System::Drawing::Bitmap(tempBitmapFrame);

		cv::namedWindow("Otsu", WINDOW_AUTOSIZE);
		//cv::resizeWindow("Otsu", 0, 0);
		cv::imshow("Otsu", frame);

		/* Hien thi tung Frame (Bitmap) ra Picturebox */
		/*
		if (form->pictureBox1->Image != nullptr)
		{
			delete form->pictureBox1->Image;
			form->pictureBox1->Image = nullptr;
		}
		form->pictureBox1->Image = bitmapFrame;
		*/
		//delete tempBitmapFrame;
		
		/* Delay 30ms */
		cv::waitKey(10);
		//System::Threading::Thread::Sleep();
	}		
		
	return nullptr;
	/*
	Mat image = imread("C:\\Users\\PC\\Pictures\\image.jpg");
	Mat dstImage;

	if (!image.data) {
		cout << "Error Line 17" << endl;
		return ;
	}

	//Apply the Filter
	GaussianBlur(image, dstImage, Size(31, 31), 0);

	namedWindow("Image Window", CV_WINDOW_KEEPRATIO);
	imshow("Image Window", dstImage);
	*/
}

void Btol::RunAnalysis()
{
	//System::Threading::Thread^ th = gcnew System::Threading::Thread(ImplementProcessing);
}

void Btol::ImplementProcessing()
{
	VideoCapture video("C:\\Users\\giahu\\Downloads\\Video\\F02_SAU_RUA_DUONG_4h01_AM.avi");
	while (1)
	{
		Mat frame;
		video >> frame;
		cvtColor(frame, frame, CV_BGR2GRAY);

		Bitmap^ BitmapFrame = MatToBitmap(frame);
	}
}

System::Drawing::Bitmap^ Btol::RunAnalysis(System::Drawing::Bitmap^ bitmap)
{
	Mat inputFrame = BitmapToMat(bitmap);
	//Mat grayFrame;
	//cvtColor(inputFrame, grayFrame, COLOR_BGR2GRAY);
	//threshold(grayFrame, grayFrame, 0, 255, CV_THRESH_BINARY);
	medianBlur(inputFrame, inputFrame, 5);
	
	return MatToBitmap(inputFrame);

	//return nullptr;
}

/*
bool Btol::checkFrame()
{
	if (video->grab())
	{
		return true;
	}

	return false;
}
*/

void Btol::Testing()
{
	//TestingForm^ testForm = gcnew TestingForm();
	//testForm->Show();
}