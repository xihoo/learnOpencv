#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>

int main(){
    // read image
    cv::Mat srcImage = cv::imread("girl.jpg");
    
    // show original image
    imshow("Original Image", srcImage);
    
    // blur image
    cv::Mat dstImage, edge, grayImage;
    
    // create a matrix the same size as srcImage
    dstImage.create(srcImage.size(), srcImage.type());
    
    // convert color image to gray-scale image
    // OpenCV2
    // cv::cvtColor(srcImage, grayImage, cv::CV_BGR2GRAY);
    // OpenCV3
    cv::cvtColor(srcImage, grayImage, cv::COLOR_BGR2GRAY);
    
    // denoising
    blur(srcImage, dstImage, cv::Size(3,3));
    
    // apply Canny operator
    Canny( dstImage, edge, 3, 9, 3);
    
    // show results
    imshow("Canny Edge Detection", edge);
    cv::waitKey(0);
    return 0;
}
