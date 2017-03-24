#include <opencv2/opencv.hpp>

int main(){
    // read video
    cv::VideoCapture capture("1.avi");
    
    // show each frame
    while(1){
        cv::Mat frame;
        
        // read current frame;
        capture >> frame;
        if(frame.empty()) break;
        
        // show current frame
        imshow("Read Video", frame);
        cv::waitKey(30);
    }
    return 0;
}
