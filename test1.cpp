#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgcodecs/imgcodecs.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

int main(){
    // read image
    cv::Mat srcImage = cv::imread("dota_logo.jpg");
    
    // show original image
    imshow("Original Image", srcImage);
    
    // erode image
    cv::Mat element = getStructuringElement(cv::MORPH_RECT, cv::Size(15,15));
    cv::Mat dstImage;
    erode(srcImage, dstImage, element);
    
    // show results
    imshow("Image Erosion", dstImage);
    cv::waitKey(0);
    return 0;
}
