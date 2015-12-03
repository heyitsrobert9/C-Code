//
//  main.cpp
//  Problem1
//
//  Created by Robert Rosas on 1/15/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

void swap(int array[], int SIZE);
void method2(int array[], int SIZE);
void method3(int array[], int SIZE);
void method4(int array[], int SIZE);
void method5(int array[], int SIZE);
void method6(int array[], int SIZE);
void method7(int array[], int SIZE);
void method8(int array[], int SIZE);
void method9(int array[], int SIZE);
void printArray(int array[], int SIZE);

const int SIZE = 9;

using namespace std;

int main(int argc, const char * argv[]) {
    
    srand(time(NULL));
    int array[SIZE];
    for(int i = 0; i < SIZE; i++)
    {
        array[i] = (rand() % 20 ) + 1;
    }
    
    cout << "Original: ";
    printArray(array, SIZE);
    cout << endl;
    
    cout << "Method 1: ";
    swap(array, SIZE);
    cout << endl;
    
    cout << "Method 2: ";
    method2(array, SIZE);
    cout << endl;
    
    cout << "Method 3: ";
    method3(array, SIZE);
    cout << endl;
    
    cout << "Method 4: ";
    method4(array, SIZE);
    cout << endl;
    
    cout << "Method 5: ";
    method5(array, SIZE);
    cout << endl;
    
    cout << "Method 6: ";
    method6(array, SIZE);
    cout << endl;
    
    cout << "Method 7: ";
    method7(array, SIZE);
    cout << endl;
    
    cout << "Method 8: ";
    method8(array, SIZE);
    cout << endl;
    
    cout << "Method 9: ";
    method9(array, SIZE);
    cout << endl;
    
    return 0;
}

void swap(int array[], int SIZE) {
    int temp;
    int b[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
        temp = b[0];
        b[0] = b[SIZE - 1];
        b[SIZE - 1]= temp;
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

void method2(int array[], int SIZE) {
    
    int b[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
    int last = b[SIZE - 1];
    
    for (int i = SIZE - 1; i >= 0; i--)
    {
        b[i + 1] = b[i];
        b[i] = last;
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

void method3(int array[], int SIZE) {
    
    int b[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
    for (int i = 0 ; i < SIZE ; i++)
    {
        if(b[i] % 2 == 0)
        {
            b[i] = 0;
        }
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    
}

void method4(int array[], int SIZE) {
    int b[SIZE];
    int copies[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
        copies[i] = array[i];
    }
    
    for (int i = 1 ; i < SIZE - 1 ; i++)
    {
        int greaterRight = b[i + 1];
        int greaterLeft = b[i - 1];
        
        if(greaterRight > greaterLeft)
        {
            copies[i] = greaterRight;
        }
        else
        {
            copies[i] = greaterLeft;
        }
        

    }
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << copies[i] << " ";
    }
    cout << endl;
}

void method5(int array[], int SIZE) {
    
    int b[SIZE];
    int even[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }

    
    for (int i = 0 ; i < SIZE ; i++)
    {
       
        if(b[i] % 2 == 0)
        {
            for(int i = 0; i < SIZE; i++)
            {
                even[i] = b[i];
            }
        }
        
        
    }
    
    for(int i = 0; i < SIZE; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
    
}

void method6(int array[], int SIZE) {
    int b[SIZE];
    int max = 0;
    int secondMax = 0;
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
    
    for (int i = 1; i < SIZE; i++)
    {
        if (b[i] > max)
        {
            secondMax = max;
            max = b[i];
        }
        else if(b[i] > secondMax)
        {
            secondMax = b[i];
        }
        
    }
    cout << secondMax;

    cout << endl;
}

void method7(int array[], int SIZE) {
    int b[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
    bool increasing = true;
    for (int i = 0; i < SIZE - 1; i++)
    {
        if (b[i] > b[i + 1])
        {
            increasing = false;
        }
    }

    
    if(increasing == true)
    {
        cout << "True";
    }
    
    else if (increasing == false)
    {
        cout << "False";
    }

    cout << endl;
}

void method8(int array[], int SIZE) {
    int b[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
    bool adjacent = false;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = i + 1; j < SIZE; j++)
        {
            if(b[i] == b[j])
                adjacent = true;
        }
    }
    
    if(adjacent == true)
    {
        cout << "True";
    }
    
    else if (adjacent == false)
    {
        cout << "False";
    }

    cout << endl;
}

void method9(int array[], int SIZE) {
    int b[SIZE];
    
    for(int i = 0; i < SIZE; i++)
    {
        b[i] = array[i];
    }
    
    bool duplicate = false;
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = i + 1; j < SIZE; j++)
        {
            if(b[i] == b[j])
                duplicate = true;
        }
    }
    
    if(duplicate == true)
    {
        cout << "True";
    }
    
    else if (duplicate == false)
    {
        cout << "False";
    }
    
    cout << endl;
}

void printArray(int array[], int SIZE) {
    for (int i = 0 ; i < SIZE ; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}


