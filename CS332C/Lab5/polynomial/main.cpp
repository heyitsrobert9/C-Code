//
//  main.cpp
//  Lab5
//
//  Created by Robert Rosas on 2/20/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include "polynomial.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

int main() {
    const int SIZE = 4;
    
    Polynomial p1(SIZE);
    Polynomial p2(SIZE);
    
    //Read data into p1
    std::cout << "Enter Polynomial Coefficients (int int int int)" << std::endl;
    std::cin >> p1;
    
    std::cout << p1 << std::endl;
    
    //Read data into p2
    std::cout << "Enter Second Polynomial Coefficients (int int int int)" << std::endl;
    std::cin >> p2;
    
    std::cout << p2 << std::endl;
    
    
    //Perform basic operations on the pointers
    
    std::cout << std::endl;
    std::cout << "Adding  ";
    std::cout << p1 + p2 << std::endl;
    
    std::cout << "Subtracting ";
    std::cout << p1 - p2 << std::endl;
    
    std::cout << "Negation ";
    -p2;
    std::cout << p2 << std::endl;
    
    std::cout << "Multiplying  ";
    p1 * 2;
    std::cout << (p1) << std::endl;
    
    std::cout << "Multiplying again ";
    2 * p1;
    std::cout << (p1) << std::endl;
    
    return 0;
}
