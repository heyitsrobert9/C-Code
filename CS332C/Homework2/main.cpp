//
//  main.cpp
//  Homework2
//
//  Created by Robert Rosas on 2/27/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include "ppmimage.h"
#include <fstream>


//testing path

// /Users/therobert9/Desktop/ppm_imgs/drink.ppm

// /Users/therobert9/Desktop/ppm_imgs/drinkNew.ppm



int main() {
    
    while (true) {
        
        std::string userChoice;
        
        std::string message;
        
        std::cout << "Hello, What would you like to do?" << std::endl;
        
        std::cout << "a.) Hide a message" << std::endl;
        
        std::cout << "b.) Recover a message" << std::endl;
        
        std::cout << "c.) Convert image to grayscale" << std::endl;
        
        std::cout << "d.) Convert image to sepia" << std::endl;
        
        std::cout << "e.) Convert image to negative" << std::endl;
        
        std::cout << "f.) Exit" << std::endl;
        
        std::cout << "Enter your selection: " << std::endl;
        
        std::cin >> userChoice;
        
        std::cout << "You chose " << userChoice << std::endl;
        
        
        
        if(userChoice == "a" || userChoice == "A" ){
            
            PPMImage test;
            
            std::string filePath;
            
            std::string filePath2;
            
            std::ifstream infile;
            
            std::ofstream outfile;
            
            std::cout << "Please specify the source PPM filename: " << std::endl;
            
            std::cin >> filePath;
            
            infile.open(filePath, std::ifstream::binary);
            
            std::cout << "Please specify the output PPM filename: " << std::endl;
            
            std::cin >> filePath2;
            
            outfile.open(filePath2, std::ifstream::binary);
            
            std::cout << "Please enter a phrase to hide: " << std::endl;
            
            std::cin >> message;
            
            test.hideData(message);
            
            std::cout << "Your message: " << message <<
            
            "  has been hidden in file: " << filePath2 << std::endl;
            
            infile.close();
            
            outfile.close();
        }
        
        
        
        else if(userChoice == "b" || userChoice == "B"){
            
            PPMImage test;
            
            std::string filePath;
            
            std::string filePath2;
            
            std::ifstream infile;
            
            std::ofstream outfile;
            
            std::cout << "Please specify the source PPM filename: " << std::endl;
            
            std::cin >> filePath2;
            
            test.recoverData();
            
            std::cout << "The following message has been recovered from file: " << filePath2 <<
            
            " " << message << std::endl;
            
            infile.close();
            
            outfile.close();
        }
        
        
        
        else if(userChoice == "c" || userChoice == "C"){
            
            PPMImage test;
            
            std::ifstream infile;
            
            std::ofstream outfile;
            
            std::string filePath;
            
            std::string filePath2;
            
            std::cout << "Please specify the source PPM filename: " << std::endl;
            
            std::cin >> filePath;
            
            infile.open(filePath, std::ifstream::binary);
            
            std::cout << "Please specify the output PPM filename: " << std::endl;
            
            std::cin >> filePath2;
            
            outfile.open(filePath2, std::ifstream::binary);
            
            infile >> test;
            
            test.grayscale();
            
            outfile << test;
            
            infile.close();
            
            outfile.close();
            
        }
        
        
        
        else if(userChoice == "d" || userChoice =="D"){
            
            PPMImage test;
            
            std::ifstream infile;
            
            std::ofstream outfile;
            
            std::string filePath;
            
            std::string filePath2;
            
            std::cout << "Please specify the source PPM filename: " << std::endl;
            
            std::cin >> filePath;
            
            infile.open(filePath, std::ifstream::binary);
            
            std::cout << "Please specify the output PPM filename: " << std::endl;
            
            std::cin >> filePath2;
            
            outfile.open(filePath2, std::ifstream::binary);
            
            infile >> test;
            
            test.sepia();
            
            outfile << test;
            
            infile.close();
            
            outfile.close();
            
        }
        
        else if(userChoice == "e" || userChoice == "E"){
            
            PPMImage test;
            
            std::ifstream infile;
            
            std::ofstream outfile;
            
            std::string filePath;
            
            std::string filePath2;
            
            std::cout << "Please specify the source PPM filename: " << std::endl;
            
            std::cin >> filePath;
            
            infile.open(filePath, std::ifstream::binary);
            
            std::cout << "Please specify the output PPM filename: " << std::endl;
            
            std::cin >> filePath2;
            
            outfile.open(filePath2, std::ifstream::binary);
            
            infile >> test;
            
            test.negative();
            
            outfile << test;
            
            infile.close();
            
            outfile.close();
            
        }
        
        
        else if(userChoice == "f" || userChoice == "F"){
            std::ifstream infile;
            
            std::ofstream outfile;
            
            infile.close();
            
            outfile.close();
            
            break;
        }
        
        else {
            std::cout << " The right letter wasnt inputted" << std::endl;
        }
        
    }
}