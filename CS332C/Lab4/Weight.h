//
//  Weight.h
//  Lab4
//
//  Created by Robert Rosas on 1/30/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#ifndef Lab4_Weight_h
#define Lab4_Weight_h
#include <iostream> 

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
    friend std::ostream& operator <<(std::ostream& outputStream, const Weight& secondOperand);
    friend std::istream& operator >>(std::istream& inputStream, Weight& secondOperand);
    
private:
    int pounds;
    int ounces;
};


#endif
