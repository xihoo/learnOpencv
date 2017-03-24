#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgcodecs/imgcodecs.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

int main(){
    // load image and show
    cv::Mat image = cv::imread("dota.jpg");
    cv::namedWindow("Image");
    cv::imshow("Image", image);
    
    // overlap images
    cv::Mat logo = cv::imread("dota_logo.jpg");
    cv::namedWindow("Logo");
    cv::imshow("Logo", logo);
    
    // define a Mat instance to save ROI
    cv::Mat imageROI;
    imageROI = image(cv::Rect(400,100,logo.cols,logo.rows));
    // Rect(x,y,Width,Height)
    
    // another way
    //imageROI = image(cv::Range(350,350+logo.rows), cv::Range(800,800+logo.cols));
    
    // put the logo onto the image
    addWeighted(imageROI, 1.0, logo, 1.0, 0., imageROI);
    //void cv::addWeighted(InputArray src1, double alpha, InputArray src2, double beta,
    //  double gamma, OutputArray dst, int dtype = -1)
    
    // show Results
    cv::namedWindow("Image with Logo");
    cv::imshow("Image with Logo", image);
    cv::waitKey();
    
    // save image
    cv::imwrite("results.jpg", image);
    
    return 0;
}
