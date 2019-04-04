#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

class MyComplex{
private:
    double real;
    double imaginary;
public:
    MyComplex();
    MyComplex(double newReal);
    MyComplex(double newReal, double newImaginary);
    double getRealPart() const;
    double getComplexPart() const;
    void setRealPart(double &newReal);
    void setComplexPart(double newImaginary);

    friend MyComplex operator+(const MyComplex& m1, const MyComplex& m2);
    friend MyComplex operator-(const MyComplex& m1, const MyComplex& m2);
    friend MyComplex operator*(const MyComplex& m1, const MyComplex& m2);
    friend MyComplex operator/(const MyComplex& m1, const MyComplex& m2);

    //friend MyComplex operator+=(const MyComplex &other);

};

#endif // MYCOMPLEX_H
