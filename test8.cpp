#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#define WINDOW_NAME "Mixed Images"

// global variables
const int g_nMaxAlphaValue = 100; // maximun alpha value
int g_nAlphaValueSlider; // value from trackbar
double g_dAlphaValue;
double g_dBetaValue;

// Mat objects for images
cv::Mat g_srcImage1;
cv::Mat g_srcImage2;
cv::Mat g_dstImage;

// on trackbar
void on_Trackbar( int, void* )
{
    g_dAlphaValue = (double) g_nAlphaValueSlider/g_nMaxAlphaValue;
    g_dBetaValue = (1.0-g_dAlphaValue);
    
    addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
    
    cv::imshow(WINDOW_NAME, g_dstImage);
}

// main
int main( int argc, char** argv )
{
    // load image and show
    g_srcImage1 = cv::imread("dota.jpg");
    g_srcImage2 = cv::imread("dota.jpg");
    // NOTE: two image should be the same size
    if(!g_srcImage1.data)
    {
        printf("Error getting the first images. Put the image wuliEddie1.jpeg to Debug folder. \n");
        return -1;
    }
    if(!g_srcImage1.data)
    {
        printf("Error getting the second images. Put the image wuliShishi1.jpeg to Debug folder. \n");
        return -1;
    }

    // initialize trackbar value
    g_nAlphaValueSlider = 70;
    
    // create window
    cv::namedWindow(WINDOW_NAME, 1);
    
    // create trackbar
    char TrackbarName[50];
    sprintf( TrackbarName, "Alpha Value %d", g_nMaxAlphaValue );
    
    cv::createTrackbar( TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar );
    
    // to show the initial image
    on_Trackbar(g_nAlphaValueSlider, 0);
    
    cv::waitKey(0);
    return 0;
}
