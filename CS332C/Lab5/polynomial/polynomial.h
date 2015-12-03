//
//  polynomial.h
//  Lab5
//
//  Created by Robert Rosas on 2/20/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#ifndef Lab5_polynomial_h
#define Lab5_polynomial_h

#include <iostream>
#include <ctime>
#include <cstdlib>

class Polynomial{
public:
    Polynomial();//Constructor
    Polynomial(int degree);
    Polynomial(const Polynomial &maPolynomial);//Copy
    ~Polynomial(); //Destructor
    const Polynomial operator +(const Polynomial& maPolynomial) const;
    const Polynomial operator -(const Polynomial& maPolynomial) const;
    const void operator -() const;
    friend void operator *(const Polynomial& maPolynomial, const int a);
    friend void operator *(const int a, const Polynomial& maPolynomial);
    bool operator ==(const Polynomial& maPolynomial) const;
    friend std::ostream& operator <<(std::ostream& outputStream, const Polynomial& maPolynomial);
    friend std::istream& operator >>(std::istream& inputStream, Polynomial& maPolynomial);
    
private:
    int arraySize;
    double *coeff;
    
};


#endif
