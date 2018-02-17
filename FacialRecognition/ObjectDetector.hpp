//
//  ObjectDetector.hpp
//  FacialRecognition
//
//  Created by Vinicius Braga on 10/09/16.
//  Copyright © 2016 Vinicius Braga. All rights reserved.
//

#ifndef ObjectDetector_hpp
#define ObjectDetector_hpp

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/objdetect/objdetect.hpp>
#include <opencv/cv.h>
#include <sys/types.h>
#include <sys/dir.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>

class ObjectDetector
{
public:
    
    void DetectObjects(cv::Mat &mtFrame);
    bool LoadModels();
    
private:
    
    bool GetXmlFiles(std::vector<std::string> vec);
    
    cv::CascadeClassifier m_Classifier;
    std::vector<cv::CascadeClassifier> vecClassifiers;
};

#endif /* ObjectDetector_hpp */
