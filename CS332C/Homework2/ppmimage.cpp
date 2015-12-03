//
//  ppmimage.cpp
//  Homework2
//
//  Created by Robert Rosas on 2/27/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include "ppmimage.h"
#include <string>
#include <fstream>
#include <iostream>

PPMImage::PPMImage() {
    this->magicNumber = "";
    this->imageWidth = 0;
    this->imageHeight = 0;
    this->maxColor = 0;
}

PPMImage::PPMImage(const PPMImage& secondOperand) {
    
}

PPMImage::~PPMImage() {
    delete [] pixel;
    pixel = 0;
}

std::istream& operator >> (std::istream& inputStream, PPMImage& secondOperand){
    
    inputStream >> secondOperand.magicNumber;
    
    inputStream >> secondOperand.imageWidth;
    inputStream >> secondOperand.imageHeight;
    inputStream >> secondOperand.maxColor;
    
    std::string empty;
    
    getline(inputStream, empty);
    
    int SIZE = secondOperand.imageWidth * secondOperand.imageHeight * 3;
    
    secondOperand.pixel = new char[SIZE];
    
    inputStream.read(secondOperand.pixel, SIZE);
    
    return inputStream;
}

std::ostream& operator <<(std::ostream& outputStream,const PPMImage& secondOperand){
    outputStream << secondOperand.magicNumber << "\n";
    outputStream << secondOperand.imageWidth << " " << secondOperand.imageHeight << "\n";
    outputStream << secondOperand.maxColor << "\n";
    int SIZE = secondOperand.imageWidth * secondOperand.imageHeight * 3;
    outputStream.write(secondOperand.pixel, SIZE);
    
    return outputStream;
    
}

void PPMImage::negative()
{
    int SIZE = imageWidth * imageHeight * 3;
    
    for(int i = 0; i < SIZE; i++){
        unsigned char negative = pixel[i];
        pixel[i]= (255 - negative);
        
    }
}

void PPMImage::grayscale()
{
    int SIZE = imageWidth * imageHeight * 3;
    for(int i = 0; i < SIZE; i+=3){
        
        unsigned char oldRed = pixel[i];
        unsigned char oldGreen = pixel[i + 1];
        unsigned char oldBlue = pixel[i + 2];
        
        pixel[i] = (oldRed * .299) + (oldGreen * .587) + (oldBlue * .114);
        pixel[i + 1] = (oldRed * .299) + (oldGreen * .587) + (oldBlue * .114);
        pixel[i + 2] = (oldRed * .299) + (oldGreen * .587) + (oldBlue * .114);
        
    }
}

void PPMImage::sepia()
{
    int SIZE = imageWidth * imageHeight * 3;
    for(int i = 0; i < SIZE; i+=3){
        
        unsigned char oldRed = pixel[i];
        unsigned char oldGreen = pixel[i + 1];
        unsigned char oldBlue = pixel[i + 2];
        
        int newRed;
        int newGreen;
        int newBlue;
        
        
        newRed = (oldRed * .393) + (oldGreen * .769) + (oldBlue * .189);
        newGreen = (oldRed * .349) + (oldGreen * .686) + (oldBlue * .168);
        newBlue = (oldRed * .272) + (oldGreen * .534) + (oldBlue * .131);
        
        
        if (newRed > 255){
            newRed = 255;
        }
        
        if (newGreen > 255){
            newGreen = 255;
        }
        
        if (newBlue > 255){
            newBlue = 255;
        }
        
        pixel[i] = newRed;
        pixel[i + 1] = newGreen;
        pixel[i + 2] = newBlue;
        
        
    }
}

std::string PPMImage::hideData(std::string message){
    int SIZE = imageWidth * imageHeight * 3;
    
    int numBits = sizeof(SIZE) * 8;
    char mask = 1;
    
    for (int i = 1 ; i <= numBits ; i++) {
        std::string bitValue = (SIZE & mask) ? "1" : "0";
        message.insert(0,bitValue);
        mask <<= 1;
    }
    return message;
}

std::string PPMImage::recoverData()
{
    int SIZE = imageWidth * imageHeight * 3;

    std::string result = "";
    for(int b = 0; b < SIZE; ++b )
    {
        for(int i=0; i < 8; ++i)
        {
            result[b] = (result[b] << 1);
        }
    }
    return result;
    
    
    
    
}
