//#pragma once

#using <System.Drawing.dll>
#include <opencv2/core/core.hpp>
using namespace cv;



System::Drawing::Bitmap^ MatToBitmap(Mat srcImg) {
	int stride = srcImg.size().width * srcImg.channels();//calc the srtide
	int hDataCount = srcImg.size().height;

	System::Drawing::Bitmap^ retImg;

	System::IntPtr ptr(srcImg.data);

	//create a pointer with Stride
	if (stride % 4 != 0) {//is not stride a multiple of 4?
						  //make it a multiple of 4 by fiiling an offset to the end of each row

		uchar *dataPro = new uchar[((srcImg.size().width * srcImg.channels() + 3) & -4) * hDataCount];//to hold processed data

		uchar *data = srcImg.ptr();

		//current position on the data array
		int curPosition = 0;
		//current offset
		int curOffset = 0;

		int offsetCounter = 0;

		//itterate through all the bytes on the structure
		for (int r = 0; r < hDataCount; r++) {
			//fill the data
			for (int c = 0; c < stride; c++) {
				curPosition = (r * stride) + c;

				dataPro[curPosition + curOffset] = data[curPosition];
			}

			//reset offset counter
			offsetCounter = stride;

			//fill the offset
			do {
				curOffset += 1;
				dataPro[curPosition + curOffset] = 0;

				offsetCounter += 1;
			} while (offsetCounter % 4 != 0);
		}

		ptr = (System::IntPtr)dataPro;//set the data pointer to new/modified data array

									  //calc the stride to nearest number which is a multiply of 4
		stride = (srcImg.size().width * srcImg.channels() + 3) & -4;

		retImg = gcnew System::Drawing::Bitmap(srcImg.size().width, srcImg.size().height,
			stride,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			ptr);
	}
	else {

		//no need to add a padding or recalculate the stride
		retImg = gcnew System::Drawing::Bitmap(srcImg.size().width, srcImg.size().height,
			stride,
			System::Drawing::Imaging::PixelFormat::Format24bppRgb,
			ptr);
	}

	cli::array<System::Byte>^ imageData;
	System::Drawing::Bitmap^ output;

	// Create the byte array.
	{
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream();
		retImg->Save(ms, System::Drawing::Imaging::ImageFormat::Png);
		imageData = ms->ToArray();
		delete ms;
	}

	// Convert back to bitmap
	{
		System::IO::MemoryStream^ ms = gcnew System::IO::MemoryStream(imageData);
		output = (System::Drawing::Bitmap^)System::Drawing::Bitmap::FromStream(ms);
	}

	return output;
}