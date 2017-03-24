#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgcodecs/imgcodecs.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
#include <vector>

void createAlphaMat(cv::Mat &mat)
{
    for (int i=0; i<mat.rows; i++) {
        for (int j = 0; j<mat.cols; ++j) {
            cv::Vec4b& rgba = mat.at<cv::Vec4b>(i,j);
            rgba[0] = UCHAR_MAX;
            rgba[1] = cv::saturate_cast<uchar>((float (mat.cols-j))/((float)mat.cols)*UCHAR_MAX);
            rgba[2] = cv::saturate_cast<uchar>((float (mat.rows-i))/((float)mat.rows)*UCHAR_MAX);
            rgba[3] = cv::saturate_cast<uchar>(0.5*(rgba[1]+rgba[2]));
        }
    }
}

int main(){
    // create Mat with alpha channel
    cv::Mat mat(480, 640, CV_8UC4);
    createAlphaMat(mat);
    
    std::vector<int> compression_params;
    if(CV_VERSION_MAJOR==3)
        compression_params.push_back(cv::IMWRITE_PNG_COMPRESSION);
        // if OpenCV2 comment this
    else
        compression_params.push_back(CV_IMWRITE_PNG_COMPRESSION);
    
    // show image
    try{
        imwrite("alpha.png", mat, compression_params);
        imshow("Created PNG", mat);
        fprintf(stdout, "Finish creating image with alpha channel.\n");
        cv::waitKey(0);
    }
    catch(std::runtime_error& ex){
        fprintf(stderr, "Error when converting to PNG: %s\n", ex.what());
        return 1;
    }
    return 0;
}
