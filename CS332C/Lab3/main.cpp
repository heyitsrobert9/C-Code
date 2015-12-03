//
//  main.cpp
//  Lab3
//
//  Created by Robert Rosas on 1/22/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <cmath>

class Weight{
public:
    Weight(){
        pounds = 0;
        ounces = 0;
    }
    Weight(int inputPounds, int inputOunces);
    void input();
    void output();
    void output_d();
    int getPounds();
    int getOunces();
    void setPounds();
    void setOunces();
    const Weight operator +(const Weight& secondOperand) const;
    const Weight operator -(const Weight& secondOperand) const;
    bool operator ==(const Weight& secondOperand) const;
    
private:
    int pounds;
    int ounces;
};

int main() {
//    Weight w(20,25), w2;
//    
//    w.output();
//    w2.output();
    
    Weight yourAmount(11,6), myAmount(10, 9);
    std::cout << "Your Amount: "; yourAmount.output();
    std::cout << std::endl;
    std::cout << "My Amount: ";myAmount.output();
    std::cout << std::endl;
    
    Weight yourAmount2(13.5,15.5), myAmount2(11.6, 12.2);
    std::cout << "Your Amount: "; yourAmount2.output_d();
    std::cout << std::endl;
    std::cout << "My Amount: ";myAmount2.output_d();
    std::cout << std::endl;

    Weight yourAmount3, myAmount3(13, 15);
    yourAmount3.operator==(myAmount3);
    if (yourAmount == myAmount)
        std::cout << "We have the same weight.\n";
    else
        std::cout << "One of us is heavier.\n";
    std::cout << std::endl;
    
    Weight ourAmount = yourAmount + myAmount;
    yourAmount.output(); std::cout << " + "; myAmount.output( );
    std::cout << " equals "; ourAmount.output( ); std::cout << std::endl;
    
    Weight diffAmount = yourAmount - myAmount;
    yourAmount.output( ); std::cout << " - "; myAmount.output( );
    std::cout << " equals "; diffAmount.output( ); std::cout << std::endl;
    
    return 0;
}

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







