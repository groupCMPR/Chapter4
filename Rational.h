//done by Alexis
#pragma once
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Rational
{
private:
    int numerator;
    int denominator;
    //Finds GCD for numerator and denominator
    int gcd(int, int);
    void normalize();

public:
    class ZeroDenominator
    {
    private:
        string rational;

    public:
        //Default
        ZeroDenominator();
        //Exception message
        ZeroDenominator(Rational);
        //converts to string
        string toString();
    };
    //Default Constructor
    Rational();
    //converts to string
    string toString();
    // will throw and exception
    Rational(int, int);

    //getter for numerator
    int getNumerator() const;
    //setter for numerator
    void setNumerator(int);
    //getter for denominator
    int getDenominator() const;
    //setter for denominator throws exception if 0
    void setDenominator(int);

    //allows addition between two rational objects
    friend Rational operator +(const Rational&, const Rational&);
    //allows subtraction between two rational objects
    friend Rational operator -(const Rational&, const Rational&);
    //allows multiplication between two rational objects
    friend Rational operator *(const Rational&, const Rational&);
    //allows division between two rational objects
    friend Rational operator /(const Rational&, const Rational&);
    Rational& operator=(const Rational&);
    //allows the Rationals to be compared -- see if they are equal
    friend bool operator ==(const Rational&, const Rational&);
    //allows the Rationals to be compared -- if one is less than the other
    friend bool operator <(const Rational&, const Rational&);
    // overloaded  cout << 
    friend ostream& operator <<(ostream&, Rational);
    //allows multiplication with a constant
    friend Rational operator *(const Rational&, int);
    //allows addition with a constant
    friend Rational operator +(const Rational&, int);
    //allows subtraction with a constant
    friend Rational operator -(const Rational&, int);
    //allows division with a constant
    friend Rational operator /(const Rational&, int);
    //allows multiplication with a constant
    friend Rational operator *(int, const Rational&);
    //allows addition with a constant
    friend Rational operator +(int, const Rational&);
    //allows subtraction with a constant
    friend Rational operator -(int, const Rational&);
    //allows division with a constant
    friend Rational operator /(int, const Rational&);
    //allows the Rationals to be compared -- see if they are not equal
    friend bool operator !=(const Rational&, const Rational&);
    //allows the Rationals to be compared -- if one is greater than or equal to the other
    friend bool operator >=(const Rational&, const Rational&);
    //allows the Rationals to be compared -- if one is greater than the other
    friend bool operator >(const Rational&, const Rational&);
    //allows the Rationals to be compared -- if one is less than or equal to the other
    friend bool operator <=(const Rational&, const Rational&);
};


