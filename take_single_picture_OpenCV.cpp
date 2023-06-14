#include "opencv2/opencv.hpp"
#include "iostream"
// g++ take_picture_OpenCV.cpp -o take_picture_OpenCV -I /usr/local/include/opencv4/ -I ~/opencv/include/opencv2/ -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio
// Reference link : https://www.geeksforgeeks.org/opencv-saving-an-image/
#define FILE_PATH "~/Desktop/Coding_Folder/OpenCV/take_single_picture_OpenCV"
#define RESPONSE_TIME 10

int main(int, char**) 
{
    // open the first webcam plugged in the computer
    cv::VideoCapture camera(0);
    if (!camera.isOpened()) 
    {
        std::cerr << "ERROR: Could not open camera" << std::endl;
        return -1;
    }

    // create a window to display the images from the webcam
    //cv::namedWindow("CAM0_PORT",cv::WINDOW_AUTOSIZE);

    // this will contain the image from the webcam
    //cv::Mat frame;
        
    // capture the next frame from the webcam
    //camera >> frame;
    
    // display the frame until you press a key
    while(true)
    {
        cv::Mat frame;
        camera.read(frame);
        imshow("Live feed",frame);

        if(cv::waitKey(RESPONSE_TIME)== 's')
        {
            cv::Mat captured_image;
            captured_image = frame.clone();
            imshow("Captured image",captured_image);
        }

        if(cv::waitKey(30)=='d')
        {
            break;
        }

        //camera.release();
        //cv::destroyAllWindows();
        //printf("PROGRAM FINISHED\r\n");

        // show the image on the window
        //cv::imshow("Webcam", frame);
        // wait (10ms) for a key to be pressed
        //if (cv::waitKey(RESPONSE_TIME) >= 0)
        //    break;
    }

        camera.release();
        cv::destroyAllWindows();
        printf("PROGRAM FINISHED\r\n");

    return 0;
}

