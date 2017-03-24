#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp> 
int main(){
    // read video
    cv::VideoCapture capture(0);
    
    // show each frame
    while(1){
        cv::Mat frame, edges;
        
        // read current frame;
        capture >> frame;
        
        // convert to gray-scale
        cv::cvtColor(frame, edges, CV_BGR2GRAY);
        
        // denoise
        //cv::blur(edges, edges, cv::Size(7,7));
        
        // canny operator
        //cv::Canny(edges, edges, 0, 30, 3);
        
        // show current frame
        imshow("Read Video", edges);
        
        // if input 'e', exit
        char c = cv::waitKey(30);
        if (c=='e') {
            break;
        }
    }
    return 0;
}
