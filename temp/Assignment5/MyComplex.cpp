#include <cstdio>

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

void MyComplex::setRealPart(double& newReal){
    real = newReal;
}

void MyComplex::setComplexPart(double newImaginary){
    imaginary = newImaginary;
}

MyComplex operator+(const MyComplex& m1, const MyComplex& m2){
    double n = m1.getRealPart() + m2.getRealPart();
    double m = m1.getComplexPart() + m2.getComplexPart();

    return MyComplex(n,m);
}

MyComplex operator-(const MyComplex& m1, const MyComplex& m2){
    double n = m1.getRealPart() - m2.getRealPart();
    double m = m1.getComplexPart() - m2.getComplexPart();

    return MyComplex(n,m);
}

MyComplex operator*(const MyComplex& m1, const MyComplex& m2){
    double a = m1.getRealPart();
    double b = m2.getRealPart();
    double c = m1.getComplexPart();
    double d = m2.getComplexPart();

    double n = a * c - b * d;
    double m = a * d + b * c;

    return MyComplex(n,m);
}

MyComplex operator/(const MyComplex& m1, const MyComplex& m2){
    double a = m1.getRealPart();
    double b = m1.getComplexPart();
    double c = m2.getRealPart();
    double d = m2.getComplexPart();
    double n = ((a * c) + (b * d)) / ((c * c) + (d * d));
    double m = ((b * c) - (a * d)) / ((c * c) + (d * d));

    return MyComplex(n,m);
}

//MyComplex MyComplex::operator+=(const MyComplex& other){
//    double n = real + other.getRealPart();
//    double m = imaginary + other.getComplexPart();

//    real = n;
//    imaginary = m;

//    return *this;
//}
