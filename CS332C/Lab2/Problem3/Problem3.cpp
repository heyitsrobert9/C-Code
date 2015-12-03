//
//  main.cpp
//  Problem3
//
//  Created by Robert Rosas on 1/18/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

struct Point3D {
    int x;
    int y;
    int z;
};

void printArray(Point3D array[], int SIZE);
void reflect(std::string whichToShift, Point3D array[]);
void translate(char whichToShift, Point3D array[], int shiftBy);

const int SIZE = 7;

using namespace std;

int main(int argc, const char * argv[]) {
    srand(time(NULL));
    
    Point3D array[SIZE];
    char userInput;
    string user;
    int shiftBy;
    
    for(int i = 0; i < SIZE; i++)
    {
        array[i].x = (rand() % 21) - 10;
        array[i].y = (rand() % 21) - 10;
        array[i].z = (rand() % 21) - 10;
    }
    
    cout << "Here is the orginal array values: " << endl;
    printArray(array, SIZE);
    cout << "Which values would you like to translate (x, y, or z): ";
    cin >> userInput;
    cout << "How many points would you like to translate it by? (Enter a number): " << endl;
    cin >> shiftBy;
    translate(userInput, array, shiftBy);
    cout << endl << endl;
    
    cout << "Here is the orginal array values for relfection: " << endl;
    printArray(array, SIZE);
    cout << "Which values would you like to reflect (xy, yz, or xz): ";
    cin >> user;
    reflect(user, array);
    
    return 0;
}

void reflect(string whichToShift, Point3D array[]){
    Point3D copy[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        copy[i] = array[i];
    }
    
    for (int i = 0; i < SIZE; i++)
    {
        if( whichToShift == "xy")
        {
            copy[i].z = 0 - (copy[i].z);
        }
        
        if( whichToShift == "yz")
        {
            copy[i].x =  0 - (copy[i].x);
        }
        
        if( whichToShift == "xz")
        {
            copy[i].y = 0 - (copy[i].y);
        }
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << copy[i].x << " " << copy[i].y << " " << copy[i].z << " " << endl;
    }
}

void translate(char whichToShift, Point3D array[], int shiftBy){
    Point3D copy[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        copy[i] = array[i];
    }
    
    
    for (int i = 0; i < SIZE; i++)
    {
        if( whichToShift == 'x')
        {
            copy[i].x = shiftBy + copy[i].x;
        }
        
        if( whichToShift == 'y')
        {
            copy[i].y = shiftBy + copy[i].y;
        }
        
        if( whichToShift == 'z')
        {
            copy[i].y = shiftBy + copy[i].z;
        }
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << copy[i].x << " " << copy[i].y << " " << copy[i].z << " " << endl;
    }
}

void printArray(Point3D array[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i].x << " " << array[i].y << " " << array[i].z << " " << endl;
    }
    cout << endl;
}
