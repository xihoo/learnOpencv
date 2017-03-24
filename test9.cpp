#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
// main
int main( int argc, char** argv )
{
    // Load image
    cv::Mat srcImage = cv::imread("girl.jpg"), dstImage;
    
    // Convert to other color space
    cv::cvtColor(srcImage, dstImage, cv::COLOR_BGR2Lab);
    imshow("Lab Space", dstImage);
    
    cv::cvtColor(srcImage, dstImage, cv::COLOR_BGR2GRAY);
    imshow("Gray Scale", dstImage);
    
    cv::waitKey();
    
    return 0;
}
