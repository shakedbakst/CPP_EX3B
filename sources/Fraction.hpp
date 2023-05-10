#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <stdexcept>

using namespace std; 

namespace ariel {

class Fraction {
private:
    int numerator;
    int denominator;

    int getGCD(int numerator, int denominator);
    void reduce();

public:
    Fraction();
    Fraction(int numerator, int denominator);
    Fraction(float number);
    Fraction(const Fraction& other);

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;
    bool operator==(const Fraction& other) const;
    bool operator>(const Fraction& other) const;
    bool operator>=(const Fraction& other) const;
    bool operator<(const Fraction& other) const;
    bool operator<=(const Fraction& other) const;
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);

    friend Fraction operator+(const Fraction& fraction, float num);
    friend Fraction operator+(float num, const Fraction& fraction);
    friend Fraction operator-(const Fraction& fraction, float num);
    friend Fraction operator-(float num, const Fraction& fraction);
    friend Fraction operator*(const Fraction& fraction, float num);
    friend Fraction operator*(double num, const Fraction& fraction);
    friend Fraction operator/(float num, const Fraction& fraction);
    friend Fraction operator/(const Fraction& fraction, float num);
    friend std::ostream& operator<<(std::ostream& oss, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& iss, Fraction& frc);
};


};// namespace ariel

#endif // FRACTION_HPP
