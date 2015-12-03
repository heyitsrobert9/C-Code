//
//  main.cpp
//  polynomial
//
//  Created by Robert Rosas on 2/20/15.
//  Copyright (c) 2015 Robert Rosas. All rights reserved.
//

#include "polynomial.h"
#include <iostream>
#include <cstdlib>
#include <cmath>

Polynomial::Polynomial() {
}

Polynomial::Polynomial(int degree) {
    arraySize  = degree + 1;
    coeff = new double[arraySize];
}

Polynomial::Polynomial(const Polynomial& maPolynomial) {
    
    coeff = new double[arraySize];
    for (int i = 0 ; i < maPolynomial.arraySize ; i++) {
        coeff[i] = maPolynomial.coeff[i];
    }
    arraySize = maPolynomial.arraySize;
}

Polynomial::~Polynomial() {
    delete [] coeff;
}

std::istream& operator >>(std::istream& inputStream, Polynomial& maPolynomial)
{
    
    for (int i = maPolynomial.arraySize - 1; i >= 0; i--)
    {
        inputStream >> *(maPolynomial.coeff + i);
    }
    
    return inputStream;
}

std::ostream& operator <<(std::ostream &outputStream, const Polynomial& maPolynomial)
{
    
    for (int i = maPolynomial.arraySize - 1; i >= 0; i--)
    {
        
        if (*(maPolynomial.coeff + i) != 0){
            if (i == 0){
                outputStream << *(maPolynomial.coeff + i);
            }
            else {
                outputStream << *(maPolynomial.coeff + i) << "x^" << i << " + ";
            }
            
        }
        
    }
    
    return outputStream;
}

bool Polynomial::operator ==(const Polynomial& maPolynomial) const
{
    if (this->arraySize == maPolynomial.arraySize){
        for(int i = 0; i < arraySize; i++)
        {
            if (*(this->coeff + i) != *(maPolynomial.coeff + i))
                return false;
        }
    }
    else {
        return false;
    }
    return true;
}


const Polynomial Polynomial::operator +(const Polynomial& maPolynomial) const
{
    int size;
    if (this->arraySize < maPolynomial.arraySize) {
        size = maPolynomial.arraySize;
    }
    else{
        size = this->arraySize;
    }
    
    Polynomial sum(size-1);
    for (int i = 0; i < maPolynomial.arraySize; i++)
    {
        *(sum.coeff + i) = *(this->coeff + i) + *(maPolynomial.coeff + i);
    }
    return sum;
}


const Polynomial Polynomial::operator -(const Polynomial& maPolynomial) const
{
    int size;
    if (this->arraySize < maPolynomial.arraySize) {
        size = maPolynomial.arraySize;
    }
    else{
        size = this->arraySize;
    }
    
    Polynomial sum(size-1);
    for (int i = 0; i < maPolynomial.arraySize; i++)
    {
        *(sum.coeff + i) = *(this->coeff + i) - *(maPolynomial.coeff + i);
    }
    return sum;
}

const void Polynomial::operator -() const
{
    for (int i = 0; i < arraySize; i++){
     *(this->coeff + i) = *(this->coeff + i) * -1;
    }
}


void operator *(const Polynomial& maPolynomial, const int a)
{
    for (int i = 0; i < maPolynomial.arraySize; i++){
        *(maPolynomial.coeff + i) = *(maPolynomial.coeff + i) *  a;
    }
}

void operator *( const int a, const Polynomial& maPolynomial)
{
    for (int i = 0; i < maPolynomial.arraySize; i++){
        *(maPolynomial.coeff + i) = *(maPolynomial.coeff + i) *  a;
    }
}





