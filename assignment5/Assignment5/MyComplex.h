/**
  * @brief Assignment 5 Problem 1
  * @author Travis Shands
  */

#ifndef MYCOMPLEX_H
#define MYCOMPLEX_H

#include <iostream>

const double EPSILON = 0.000001;

class MyComplex{
private:
    double real;
    double imaginary;
public:

    /**
     * @brief Basic no argument constructor that sets both real and imaginary to 0
     */
    MyComplex();

    /**
     * @brief One argument constructor that sets real as defined and imaginary to 0
     * @param newReal Defines a double to be set as real
     */
    MyComplex(double newReal);

    /**
     * @brief Two argument constructor that sets real and imaginary as defined
     * @param newReal Defines a double to be set as real
     * @param newImaginary Defines a double to be set as imaginary
     */
    MyComplex(double newReal, double newImaginary);

    /**
     * @brief Returns the real value of the given object
     * @return Returns real as a double
     */
    double getRealPart() const;

    /**
     * @brief Returns the imaginary value of the given object
     * @return Returns imaginary as a double
     */
    double getComplexPart() const;

    /**
     * @brief Provides the sum of two objects to be used in the construction of a third
     * @param Passes in a refference to the other object to be used
     * @return Returns MyComplex
     */
    MyComplex operator+(const MyComplex& other);

    /**
     * @brief Provides the difference of two objects to be used in the construction of a third
     * @param Passes in a refference to the other object to be used
     * @return Returns MyComplex
     */
    MyComplex operator-(const MyComplex& other);

    /**
     * @brief Provides the product of two objects to be used in the construction of a third
     * @param Passes in a refference to the other object to be used
     * @return Returns MyComplex
     */
    MyComplex operator*(const MyComplex& other);

    /**
     * @brief Provides the quotient of two objects to be used in the constrion of a third
     * @param Passes in a refference to the other object to be used
     * @return Returns MyComplex
     */
    MyComplex operator/(const MyComplex& other);

    /**
     * @brief Increases the values of this object by those of other
     * @param other Provides object to be added
     * @return Returns MyComplex
     */
    MyComplex& operator+=(const MyComplex& other);

    /**
     * @brief Decreases the values of this object by those of other
     * @param other Provides object to be added
     * @return Returns MyComplex
     */
    MyComplex& operator-=(const MyComplex& other);

    /**
     * @brief Multiplies the values of this object by those of other
     * @param other Provides object to be added
     * @return Returns MyComplex
     */
    MyComplex& operator*=(const MyComplex& other);

    /**
     * @brief Divides the values of this object by those of other
     * @param other Provides object to be added
     * @return Return MyComplex
     */
    MyComplex& operator/=(const MyComplex& other);

    /**
     * @brief Pre-increments the real value of the given object
     * @return Returns this object
     */
    MyComplex& operator++();

    /**
     * @brief Post-increments the real value of the given object
     * @param dummy Serves only the purpose of distinction from Pre-incement
     * @return Returns unincremented object
     */
    MyComplex operator++(int dummy);

    /**
     * @brief Pre-decrements the real value of the given object
     * @return Returns this object
     */
    MyComplex& operator--();

    /**
     * @brief Post-decrements the real value of the given object
     * @param dummy Serves only the purpose of distrinction from Pre-decrement
     * @return Returns undecremented object
     */
    MyComplex operator--(int dummy);

    /**
     * @brief Negates the values of the given object
     * @return Returns negated object
     */
    MyComplex operator-();

    /**
     * @brief Determines if two objects are equal
     * @param Passes in object to be compared
     * @return Returns true if the values are equal
     */
    MyComplex operator==(const MyComplex other);

    /**
     * @brief Determines if two objects are not equal
     * @param Passes in object to be compared
     * @return Returns true if the values are not equal
     */
    MyComplex operator!=(const MyComplex other);

    /**
     * @brief Outputs the contents of an object to a stream
     * @param stream Provides a stream object into which to pass values for output
     * @param complex Provides values to be passed into stream
     * @return Returns the stream
     */
    friend std::ostream& operator<<(std::ostream& stream, const MyComplex& complex);

    /**
     * @brief Passes a given stream into a given object
     * @param stream Provides a stream of values to be passed into a given object
     * @param complex Provides an object into which stream values are passed
     * @return Returns the stream
     */
    friend std::istream& operator>>(std::istream& stream, MyComplex& complex);

};

#endif // MYCOMPLEX_H
