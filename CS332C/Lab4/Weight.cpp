//
//  Weight.cpp
//  Lab4
//
//  Created by Robert Rosas on 1/30/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include "Weight.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Weight::Weight(int inputPounds, int inputOunces){
    this->pounds = inputPounds;
    this->ounces = inputOunces;
}

void Weight::output()
{
    int pound = pounds;
    int ounce = ounces;
    std::cout << "Pounds: " << pound << "  " << "Ounces: " << ounce << std::endl;
}

void Weight::output_d()
{
    double ounce = ounces / 16.0;
    double pound = pounds + ounce;
    std::cout << "Pounds: " << pound << std::endl;
}

const Weight Weight::operator +(const Weight& secondOperand) const{
    int totalOunces = pounds * 16 + ounces;
    int totalOunces2 = secondOperand.pounds * 16 + secondOperand.ounces;
    int AllWeights = totalOunces + totalOunces2;
    int finalPounds = AllWeights/16;
    int finalOunces = AllWeights%16;
    return Weight(finalPounds, finalOunces);
}

const Weight Weight::operator -(const Weight& secondOperand) const
{
    int totalOunces = pounds * 16 + ounces;
    int totalOunces2 = secondOperand.pounds * 16 + secondOperand.ounces;
    int AllWeightsDiff = totalOunces - totalOunces2;
    int finalPounds = AllWeightsDiff / 16;
    int finalOunces = AllWeightsDiff % 16;
    return Weight(finalPounds, finalOunces);
}

bool Weight::operator ==(const Weight& secondOperand) const
{
    return ((pounds == secondOperand.pounds)
            && (ounces== secondOperand.ounces));
}

std::ostream& operator <<(std::ostream& outputStream, const Weight& secondOperand)
{
    int inPounds = secondOperand.pounds;
    int inOunces = secondOperand.ounces;
    
        outputStream << inPounds << " lbs ";
        outputStream << inOunces << " oz ";
    
    return outputStream;
}


std::istream& operator >>(std::istream& inputStream, Weight& secondOperand)
{
    int inPounds;
    int inOunces;
    
    inputStream >> inPounds;
    inputStream >> inOunces;
    
    secondOperand.pounds = inPounds;
    secondOperand.ounces = inOunces;
    
    
    return inputStream;
}

