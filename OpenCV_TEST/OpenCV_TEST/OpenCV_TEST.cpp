#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;
int main()
{
	int blockSize = 75;
	int linepoint = blockSize - 1;
	int imageSize = blockSize * 11;
	Mat monopolyBoard(imageSize, imageSize, CV_8UC3, Scalar::all(0));
	unsigned int color[3];
	color[0] = color[1] = color[2] = 255;

	for (int i = 0; i<imageSize; i = i + blockSize) {

		for (int j = 0; j<imageSize; j = j + blockSize) {

			Mat ROI = monopolyBoard(Rect(i, j, blockSize, blockSize));
			ROI.setTo(Scalar(color[0], color[1], color[2]));

			if (i == 0 || j == 0 || (i / blockSize) == 10 || (j / blockSize) == 10) {

				line(ROI, Point(0, 0), Point(0, linepoint),Scalar(0,0,0), 1);
				line(ROI, Point(0, 0), Point(linepoint, 0), Scalar(0, 0, 0), 1);
				line(ROI, Point(linepoint, 0), Point(linepoint, linepoint), Scalar(0, 0, 0), 1);
				line(ROI, Point(0, linepoint), Point(linepoint, linepoint), Scalar(0, 0, 0), 1);
			}

			if (i == 0) {
				color[0] = color[1] = color[2] = 255;
				switch (j / blockSize) {
					case 0:
						putText(ROI, "GO", Point(20, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 204; color[1] = 0; color[2] = 0;
						break;
					case 1:
						color[0] = color[1] = color[2] = 255;
						break;
					case 2:
						putText(ROI, "Tax", Point(15, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 204; color[1] = 0; color[2] = 0;
						break;
					case 4:
						putText(ROI, "?", Point(27, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						break;
					case 5:
						putText(ROI, "Train", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 0; color[1] = 153; color[2] = 0;
						break;
					case 7:
						putText(ROI, "Chest", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 0; color[1] = 153; color[2] = 0;
						break;
					case 8:
						color[0] = 0; color[1] = 153; color[2] = 0;
						break;
					case 10:
						putText(ROI, "Go To", Point(5, 25), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						putText(ROI, "Jail", Point(25, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 0; color[1] = 53; color[2] = 102;
						break;
					default:
						break;
				}
			}
			else if (j == 0) {
				switch (i / blockSize) {
					case 2:
						putText(ROI, "Chest", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						break;
					case 4:
						putText(ROI, "Tax", Point(15, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						break;
					case 5:
						putText(ROI, "Train", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						break;
					case 7:
						putText(ROI, "?", Point(27, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						break;
					case 10:
						putText(ROI, "Jail", Point(15, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						break;
					default:
						break;
				}
				color[0] = color[1] = color[2] = 255;
			}
			else if ((j/blockSize) == 9) {
				color[0] = color[1] = color[2] = 255;
				switch (i / blockSize) {
				case 1:
				case 3:
				case 4:
					color[0] = 0;
					break;
				case 6:
				case 7:
				case 9:
					color[0] = color[1] = 0;
					break;
				default:
					break;
				}
				
			}
			else if ((j / blockSize) == 10) {
				color[0] = color[1] = color[2] = 255;
				switch (i / blockSize) {
					case 2:
						putText(ROI, "water", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 0; color[1] = 53; color[2] = 102;
						break;
					case 5:
						putText(ROI, "Train", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[2] = 153;
						break;
					case 7:
						color[2] = 153;
						break;
					case 8:
						putText(ROI, "?", Point(27, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[2] = 153;
						break;
					case 10:
						putText(ROI, "Free", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
					default:
						break;
				}
			}
			if ((i/blockSize) == 10) {
				color[0] = color[1] = color[2] = 255;
				switch (j / blockSize) {
					case 0:
					case 3:
						color[0] = 153; color[1] = 51; color[2] = 255;
						break;
					case 2:
						putText(ROI, "electric", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0), 2);
						color[0] = 153; color[1] = 51; color[2] = 255;
						break;
					case 5:
						putText(ROI, "Train", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 0; color[1] = 128; color[2] = 255;
						break;
					case 7:
						putText(ROI, "Chest", Point(5, 65), FONT_HERSHEY_SIMPLEX, 0.75, Scalar(0), 2);
						color[0] = 0; color[1] = 128; color[2] = 255;
						break;
					case 8:
						color[0] = 0; color[1] = 128; color[2] = 255;
						break;
					default:
						break;
				}
			}
			
		}
	}	

	imshow("Monopoly Board", monopolyBoard);
	waitKey(0);
	return 0;
}