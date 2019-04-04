/**
  * @brief Assignment 5 Problem 1
  * @author Travis Shands
  */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#include "MyComplex.h"

MyComplex::MyComplex(){
    real = 0;
    imaginary = 0;
}

MyComplex::MyComplex(double newReal){
    real = newReal;
    imaginary = 0;
}

MyComplex::MyComplex(double newReal, double newImaginary){
    real = newReal;
    imaginary = newImaginary;
}

double MyComplex::getRealPart() const{
    return real;
}

double MyComplex::getComplexPart() const{
    return imaginary;
}

MyComplex MyComplex::operator+(const MyComplex& other){
    double n = real + other.getRealPart();
    double m = imaginary + other.getComplexPart();

    return MyComplex(n,m);
}

MyComplex MyComplex::operator-(const MyComplex& other){
    double n = real - other.getRealPart();
    double m = imaginary - other.getComplexPart();

    return MyComplex(n,m);
}

MyComplex MyComplex::operator*(const MyComplex& other){
    double a = real;
    double b = other.getRealPart();
    double c = imaginary;
    double d = other.getComplexPart();

    double n = a * c - b * d;
    double m = a * d + b * c;

    return MyComplex(n,m);
}

MyComplex MyComplex::operator/(const MyComplex& other){
    double a = real;
    double b = imaginary;
    double c = other.getRealPart();
    double d = other.getComplexPart();
    double n = ((a * c) + (b * d)) / ((c * c) + (d * d));
    double m = ((b * c) - (a * d)) / ((c * c) + (d * d));

    return MyComplex(n,m);
}

MyComplex& MyComplex::operator+=(const MyComplex& other){
    double n = real + other.getRealPart();
    double m = imaginary + other.getComplexPart();

    real = n;
    imaginary = m;

    return *this;
}

MyComplex& MyComplex::operator-=(const MyComplex& other){
    double n = real - other.getRealPart();
    double m = imaginary - other.getComplexPart();

    real = n;
    imaginary = m;

    return *this;
}

MyComplex& MyComplex::operator*=(const MyComplex& other){
    double a = real;
    double b = other.getRealPart();
    double c = imaginary;
    double d = other.getComplexPart();

    real = a * c - b * d;
    imaginary = a * d + b * c;

    return *this;
}

MyComplex& MyComplex::operator/=(const MyComplex& other){
    double a = real;
    double b = imaginary;
    double c = other.getRealPart();
    double d = other.getComplexPart();
    real = ((a * c) + (b * d)) / ((c * c) + (d * d));
    imaginary = ((b * c) - (a * d)) / ((c * c) + (d * d));

    return *this;
}

MyComplex& MyComplex::operator++(){
    real += 1;
    return *this;
}

MyComplex MyComplex::operator++(int dummy){
    ++dummy;
    MyComplex temp(real, imaginary);
    real += 1;
    return temp;
}

MyComplex& MyComplex::operator--(){
    real -= 1;
    return *this;
}

MyComplex MyComplex::operator--(int dummy){
    ++dummy;
    MyComplex temp(real, imaginary);
    real -= 1;
    return temp;
}

MyComplex MyComplex::operator-(){
    return MyComplex(-real, -imaginary);
}

MyComplex MyComplex::operator==(const MyComplex other){
    if(real - other.getComplexPart() < EPSILON){
        return true;
    }
    else return false;
}

MyComplex MyComplex::operator!=(const MyComplex other){
    if(real - other.getComplexPart() > EPSILON){
        return true;
    }
    else return false;
}

ostream& operator<<(ostream& stream, const MyComplex& complex){
    if(complex.getComplexPart() - abs(complex.getComplexPart()) < 0){
        stream << complex.getRealPart() << " - " << -complex.getComplexPart() << "i";
    }
    else
        stream << complex.getRealPart() << " + " << complex.getComplexPart() << "i";
    return stream;
}

istream& operator>>(istream& stream, MyComplex& complex){
    stream >> complex.real;
    char sign;
    stream >> sign;
    stream >> complex.imaginary;

    if(sign == '-'){
        complex.imaginary = complex.imaginary * -1;
    }

    char i;
    stream >> i;

    return stream;
}
