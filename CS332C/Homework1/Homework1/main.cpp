//
//  main.cpp
//  Homework1
//
//  Created by Robert Rosas on 1/27/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//
#include <iostream>
#include "MySet.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>

class MySet{
public:
    MySet(){
        srand(time(NULL));
        SIZE = 10;
        
        std::vector<int> values(SIZE);
        for (int i = 0; i < SIZE; i++)
        {
            int temp = rand() % 100;
            add(temp);
            if ((false))
            {
                i--;
                temp = rand() % 100;
            }
        }
    };
    
    bool add(int x);
    bool remove(int x);
    const MySet operator +(const MySet &x) const;
    const MySet operator -(const MySet &x) const;
    const MySet operator &(const MySet &x) const;
    bool operator ==(const MySet &x) const;
    bool operator >(const MySet &x) const;
    bool operator <(const MySet &x) const;
    int size() const;
    bool isEmpty() const;
    void output();
    
private:
    int SIZE;
    int RANGE;
    std::vector<int> values();
};

int main() {
//    MySet object;
//    object.output();
//    object.add(55);

    std::cout << "************MySet Main Menu************" << std::endl;
    std::cout << "1. Generate a Default Set" << std::endl;
    std::cout << "3. Generate Set 1 With User Input" << std::endl;
    std::cout << "4. Generate a Default Set 2" << std::endl;
    std::cout << "5. Generate Set 2 Given the Size" << std::endl;
    std::cout << "6. Generate Set 2 With User Input" << std::endl;
    std::cout << "7. Add a Value" << std::endl;
    std::cout << "8. Remove a Value" << std::endl;
    std::cout << "9. Union" << std::endl;
    std::cout << "10. Relative Compliment" << std::endl;
    std::cout << "11. Intersection" << std::endl;
    std::cout << "12. Equality" << std::endl;
    std::cout << "13. Superset" << std::endl;
    std::cout << "14. Subset" << std::endl;
    std::cout << "15. Display Sets" << std::endl;
    std::cout << "16. Exit Program" << std::endl;
    std::cout << "***************************************" << std::endl;
    return 0;
}

bool MySet::add(int x)
{
  
    
}

//bool MySet::remove(int x){
//    x = rand() % 100;
//    if (std::find(values().begin(), values().end(), x) ==  values().end())
//    {
//        values().pop_back();
//        return true;
//    }
//    else
//    {
//        return false;
//    }
//}
//
//void MySet::output(){
//    for (int i = 0; i < values().size();i++){
//        std::cout << values()[i] << std::endl;
//    }
//}
//
