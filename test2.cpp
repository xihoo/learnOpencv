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
    cv::Mat dstImage;
    blur(srcImage, dstImage, cv::Size(10,1));
    
    // show results
    imshow("Image Blurring", dstImage);
    cv::waitKey(0);
    return 0;
}
