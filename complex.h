// Scott Ferguson
// CSS 342
// Assignment 1
// A weight object holds two doubles, real and imaginary
#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

//---------------------------------------------------------
//Complex numbers: numbers dealing with -1^(1/2) otherwise known as i
//Assumptions:
// -- Numbers are doubles
// -- The real number is the first parameter
// -- The Imaginary number is the second parameter
// -- Dividing by zero returns zero
//---------------------------------------------------------
class complex
{
    // overloaded <<: prints error message upon dividing by 0
    // prints in the form real, + or - imaginary except in certain cases(i.e. one or both numbers is 0,1 or negative)
    friend ostream& operator<<(ostream&, const complex&);

    // overloaded >>: takes 2 doubles as real and imaginary respectively
    friend istream& operator>>(istream&, complex&);
//---------------------------------------------------------

    // public functions
    public:

        // default constructor
        complex(double x = 0, double y = 0);

        // arithmetic operators
        complex operator+(const complex &) const;
        complex operator-(const complex &) const;
        complex operator*(const complex &) const;
        complex operator/(const complex &) const;

        // boolean operators
        bool operator== (const complex&) const;
        bool operator!= (const complex&) const;

        // assignment operators
        complex& operator+= (const complex&);
        complex& operator-= (const complex&);
        complex& operator*= (const complex&);
        complex& operator/= (const double&);
        complex& operator/= (const complex&);

        // get methods that allow access to real and imaginary objects
        double getReal();
        double getImaginary();

        //returns the conjugate of an object (x + (-y)i)
        complex conjugate();
//---------------------------------------------------------

    // private variables
    private:
        double Real;
        double Imaginary;
};

#endif // COMPLEX_H
