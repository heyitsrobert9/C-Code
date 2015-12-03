//
//  ppmimage.h
//  Homework2
//
//  Created by Robert Rosas on 2/27/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#ifndef __Homework2__ppmimage__
#define __Homework2__ppmimage__

#include <iostream>
#include <string>


class PPMImage{
public:
    PPMImage();
    PPMImage(const PPMImage& secondOperand);
    ~PPMImage();
    void sepia();
    void negative();
    void grayscale();
    std::string recoverData();
    std::string hideData(std::string);
    friend std::ostream& operator <<(std::ostream& outputStream, const PPMImage& secondOperand);
    friend std::istream& operator >>(std::istream& inputStream, PPMImage& secondOperand);
    
    
private:
    std::string magicNumber;
    int imageWidth;
    int imageHeight;
    int maxColor;
    char *pixel;
};

#endif 
