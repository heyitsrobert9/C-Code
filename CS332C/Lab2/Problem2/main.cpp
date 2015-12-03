//
//  main.cpp
//  Problem2
//
//  Created by Robert Rosas on 1/19/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include <ctime>
#include <cstdlib>

void printArray(int array[], int SIZE);
void checkPin(int[], int[], int[]);

using namespace std;
const int SIZE = 10;

int main(int argc, const char * argv[]) {
   srand(time(NULL));
    
    int pin[] = {6,6,5,8,4};
  
    int input[5];
   
    int generated[SIZE];
    
    for (int i = 0; i < 10; i++)
    {
        generated[i] = rand() % 3;
    }
    
    cout << " Hello and Welcome, You will see generated numbers that correspond to ones you enter as a pin";
    cout << endl << "PIN: 0 1 2 3 4 5 6 7 8 9" << endl;
    cout << "NUM: ";
    printArray(generated, SIZE);
    cout << endl << "Now please enter your pin according to the generated numbers and press enter after every number: " << endl;
    for(int i = 0; i < 5; i++)
    {
        cin >> input[i];
    }
    checkPin(input, generated, pin);
    
    return 0;
}

void checkPin(int input[], int generated[], int pin[]){
    
    bool valid = false;
    for(int i = 0; i < 5; i++)
    {
        if(generated[pin[i]] == input[i])
            valid = true;
        else
        {
            valid = false;
            break;
        }
    }
    if(valid)
    {
        cout << "You entered the correct PIN!" << endl;
    }
    else
    {
        cout << "You entered an incorrect PIN!" << endl;
        
    }
}
void printArray(int array[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


