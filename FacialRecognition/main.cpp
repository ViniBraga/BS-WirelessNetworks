//
//  main.cpp
//  FacialRecognition
//
//  Created by Vinicius Braga on 10/09/16.
//  Copyright © 2016 Vinicius Braga. All rights reserved.
//

#include <iostream>

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/core/core.hpp>


#include "ObjectDetector.hpp"


int main(int argc, const char * argv[]) {
    std::cout << "Hello, World!\n";
    std::cout << "Minha versão do OpenCV é " << CV_VERSION <<std::endl;
    
    char key;
    bool bLoaded = false;
    std::vector<std::string> vecXmlFiles;
   
    cv::namedWindow("Camera_Output", CV_WINDOW_AUTOSIZE);
    cv::VideoCapture capture;
    cv::Mat mtFrame;
    
    capture.open(0);
    capture.set(CV_CAP_PROP_FRAME_WIDTH, 1024);
    capture.set(CV_CAP_PROP_FRAME_HEIGHT, 560);
    
    ObjectDetector* detector = new ObjectDetector;
    
    bLoaded = detector->LoadModels();
    
    if (bLoaded)
    {
        while (1)
        {
            capture.read(mtFrame);
            //detector->DetectObjects(mtFrame);
            //cv::imshow("Camera_Output", mtFrame);
            
            key = cvWaitKey(10);
        if (char(key) == 27) break;
        }
    }
    
    delete detector;
    detector = NULL;
    
    return 0;
    
}
