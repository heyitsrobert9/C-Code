//
//  main.cpp
//  Lab2
//
//  Created by Robert Rosas on 1/15/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include <string>

struct Person {
    std::string name;
    int age;
};

int main() {
    Person p1;
    Person p2;
    
    p1.name = "Jack Sprat";
    p1.age = 23;
    
    //Initialize p2 with the values of p1;
    p2 = p1;
    
    //This is the same as saying:
    // p2.name = p1.name;
    // p2.age = p1.age;
    
    //Structures are NOT reference (call-by-reference) types by default, they are structure types.
    //When you say p2 = p1 you are not assigning a reference of p1 to p2,
    //you are literally taking the values stored in the member variables
    //of p1 and copying them one by one into the member variables of p2.
    
    std::cout << "p1.name before change: " << p1.name << std::endl;
    std::cout << "p2.name before change: " << p2.name << std::endl << std::endl;
    
    p1.name = "Sue Smith";
    
    std::cout << "p1.name before change: " << p1.name << std::endl;
    std::cout << "p2.name before change: " << p2.name << std::endl;
}
