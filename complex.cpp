// Scott Ferguson
// CSS 342
// Assignment 1
// A weight object holds two doubles, real and imaginary
#include "complex.h"
#include <iostream>

//---------------------------------------------------------
// constructor
complex::complex(double x, double y) : Real(x), Imaginary(y){ // initialize

}

//---------------------------------------------------------
//returns real number
double complex::getReal(){
    return Real;
}

//returns imaginary number
double complex::getImaginary(){
    return Imaginary;
}

//---------------------------------------------------------
// operator+
// addition of two complex numbers, current object and parameter
complex complex::operator+(const complex& a) const {
    complex sum;

    sum.Real = Real + a.Real;
    sum.Imaginary = Imaginary + a.Imaginary;

    return sum;
}

// operator-
// subtraction of two complex numbers, current object and parameter
complex complex::operator-(const complex& s) const {
    complex sub;

    sub.Real = Real - s.Real;
    sub.Imaginary = Imaginary - s.Imaginary;

    return sub;
}

// operator*
// multiplication of two complex numbers, current object and parameter
complex complex::operator*(const complex& m) const {
    complex multi;
    //(a + bi)(c + di)
    //(ac - bd) + (ad + bc)i

    multi.Real = (Real * m.Real) - (Imaginary * m.Imaginary);
    multi.Imaginary = (Real * m.Imaginary) + (Imaginary * m.Real);

    return multi;
}

// operator/
// division of two complex numbers, current object and parameter
complex complex::operator/(const complex& d) const {
    complex div;
    if (d.Real == 0 || d.Imaginary == 0) {
        std::cout << "Divide by zero Error "; // error message
        return 0;
    } else{
        //variables hold the values after foiling the terms
        double numerator1 = Real * d.Real;
        double numerator2 = Imaginary * d.Real;
        double numerator3 = Real * (d.Imaginary * -1); // (i)
        double numerator4 = Imaginary * (d.Imaginary * -1); //(i^2)
        double denominator1 = d.Real * d.Real;
        double denominator4 = d.Imaginary * (d.Imaginary * -1);
        //combining like terms
        numerator2 += numerator3;
        numerator4 *= -1;
        denominator4 *= -1;
        numerator1 += numerator4;
        denominator1 += denominator4;
        //setting the object to the values after simplifying
        div.Real = numerator1 / denominator1;
        div.Imaginary = numerator2 / denominator1;
        return div;
    }

}

//---------------------------------------------------------
// returns the conjugate of a complex number defined as Yi * -1
complex complex::conjugate() {
    complex conj;
    conj.Real = Real;
    conj.Imaginary = Imaginary * -1;

    return conj;

}

//---------------------------------------------------------
// operator ==
// true if current object is == parameter, otherwise false
 bool complex::operator== (const complex& r) const {
    return (Real == r.Real && Imaginary == r.Imaginary);
 }

// operator !=
// true if current object is != parameter, otherwise false
 bool complex::operator!= (const complex& r) const {
    return !(*this == r);
 }

//---------------------------------------------------------
// operator +=
// current object = current object + parameter
 complex& complex::operator+= (const complex& a) {
    Real = Real + a.Real;
    Imaginary = Imaginary + a.Imaginary;

    return *this;
 }

// operator -=
// current object = current object - parameter
 complex& complex::operator-= (const complex& s) {
    Real = Real - s.Real;
    Imaginary = Imaginary - s.Imaginary;

    return *this;
 }

// operator *=
// current object = current object * parameter
 complex& complex::operator*= (const complex& m) {
    double temp = Real;
    Real = (Real * m.Real) - (Imaginary * m.Imaginary);
    Imaginary = (temp * m.Imaginary) + (Imaginary * m.Real);

    return *this;
 }

// operator /=
// current object = current object / double
 complex& complex::operator/= (const double& d) {
    Real = Real / d;
    Imaginary = Imaginary / d;

    return *this;
 }

// operator /=
// current object = current object / object
 complex& complex::operator/= (const complex& d) {
        double numerator1 = Real * d.Real;
        double numerator2 = Imaginary * d.Real;
        double numerator3 = Real * (d.Imaginary * -1); // (i)
        double numerator4 = Imaginary * (d.Imaginary * -1); //(i^2)
        double denominator1 = d.Real * d.Real;
        double denominator4 = d.Imaginary * (d.Imaginary * -1);
        numerator2 += numerator3;
        numerator4 *= -1;
        denominator4 *= -1;
        numerator1 += numerator4;
        denominator1 += denominator4;
        Real = numerator1 / denominator1;
        Imaginary = numerator2 / denominator1;
        return *this;
 }

//---------------------------------------------------------
// operator <<
// if both 0 prints 0
// if one is 0 prints the other
// if Y is 1 or -1 prints i or -i respectively
 ostream& operator<<(ostream &output, const complex &r) {
     if (r.Real == 0 && r.Imaginary == 0){
        output << 0;
     }
     //non-actual-number(nan) case
     else if (r.Real != r.Real || r.Imaginary != r.Imaginary) {
        output << 0;
     }
     else if (r.Real == 0 && r.Imaginary == 1){
        output << "i";
     }
     else if (r.Real == 0 && r.Imaginary == -1){
        output << "-i";
     }
     else if (r.Real == 1){
        output << r.Real << " + " << r.Imaginary << "i";
     }
     else if (r.Imaginary == 1) {
        output << r.Real << " + i";
     }
     else if (r.Real == 0) {
        output << r.Imaginary << "i";
     }
     else if (r.Imaginary == 0) {
        output << r.Real;
     }
     else if(r.Real == 1 && r.Imaginary == 0){
        output << 1;
     }
     else if (r.Imaginary < 0) {
        output << r.Real << " " << r.Imaginary << "i";
     }
     else {
        output << r.Real << " + " << r.Imaginary << "i";
     }
     return output;
 }

//operator >>
//takes two doubles as real and imaginary respectively
 istream& operator>>(istream &input, complex &r) {
     input >> r.Real >> r.Imaginary;

     return input;
 }
