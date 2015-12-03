//
//  main.cpp
//  Lab4
//
//  Created by Robert Rosas on 1/29/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include "Weight.h"
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

int main() {
    
    std::ifstream inStream;
    std::ifstream inStream2;
    std::ofstream outStream;
    std::ofstream outStream2;
    std::ofstream outStream3;
    
    
    inStream.open("Weights1.txt");
    inStream2.open("Weights2.txt");
    if (inStream.fail( ) || inStream2.fail( ))
    {
        std::cout << "Input file opening failed.\n";
        exit(1);
    }
    
    outStream.open("Sums.txt");
    outStream2.open("Differences.txt");
    outStream3.open("Equalities.txt");
    if (outStream.fail( ) || outStream2.fail() || outStream3.fail())
    {
        std::cout << "Output file opening failed.\n";
        exit(1);
    }
    
    std::string temp;
    while (!inStream.eof() && !inStream2.eof())
    {
        Weight amount1, amount2;
        inStream >> amount1;
        inStream2 >> amount2;
        
        Weight addAmounts = amount1 + amount2;
        outStream << addAmounts << std::endl;
        //std::cout << addAmounts << std::endl;
        
        Weight diffAmounts = amount1 - amount2;
        outStream2 << diffAmounts << std::endl;
        //std::cout << diffAmounts << std::endl;
        
        if (amount1 == amount2)
        {
            outStream3 << "Equal.\n";
            //std::cout << "Equal \n";
        }
        else
        {
            outStream3 << "Not eqaul.\n";
            //std::cout << "Not eqaul \n";
        }
        getline(inStream, temp);
        std::cout << std:: endl;
    }
    
    inStream.close();
    inStream2.close();
    outStream.close();
    outStream2.close();
    outStream3.close();
    return 0;
}




















