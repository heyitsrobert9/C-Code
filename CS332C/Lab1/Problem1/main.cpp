//
//  main.cpp
//  Problem1
//
//  Created by Rosas, Roberto C on 1/13/15.
//  Copyright (c) 2015 Rosas, Roberto C. All rights reserved.
//

#include <iostream>

using namespace std;
double male_child(double, double);
double female_child(double, double);

int main() {
    enum Gender {
        MALE = 0,
        FEMALE = 1
    };
    
    
    while (true) {
        int gender;
        cout << "Enter 0 for Male, or 1 for Female, or 2 to end ";
        cin >> gender;
        
        if ( gender == 2){
            break;
        }
        
        double father_height;
        cout << "Enter height of father in inches ";
        cin >> father_height;
        
        double mother_height;
        cout << "Enter height of mother in inches ";
        cin >> mother_height;
        
        double male_height = male_child(father_height, mother_height);
        double female_height = female_child(father_height, mother_height);
        
        cout << "Your male childs height will be  " << male_height << " inches " << endl;
        cout << "Your female childs height will be  " << female_height <<  " inches " << endl;
        
    }
    return 0;
}

double male_child(double father, double mother) {
    return ((mother*(1.08)) + father) / 2;
}

double female_child(double father, double mother) {
    return ((father*(.92)) + mother) / 2;
}