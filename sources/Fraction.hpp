/*#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath>
#include <climits>
#include <cstdlib>
#include <stdexcept>

using namespace std; 

namespace ariel {}

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

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    Fraction operator+(const Fraction& other) const;
    friend Fraction operator+(const Fraction& fraction , float num);
    friend Fraction operator+(float num, const Fraction& fraction);
    Fraction operator-(const Fraction& other) const;
    friend Fraction operator-(const Fraction& fraction , float num);
    friend Fraction operator-(float num, const Fraction& fraction);
    Fraction operator*(const Fraction& other) const;
    friend Fraction operator*(const Fraction &frac, float num);
    friend Fraction operator*(float num, const Fraction &frc);
    Fraction operator/(const Fraction& other) const;
    friend Fraction operator/(float num, const Fraction &frac);
    friend Fraction operator/(const Fraction &frac, float num);


    bool operator==(const Fraction& other) const;
    bool operator==(const float& num) const;
    bool operator>(const Fraction& other) const;
    friend bool operator>(const Fraction& fraction, float num);
    friend bool operator>(float num, const Fraction& fraction);
    bool operator>=(const Fraction& other) const;
    friend bool operator>=(float num, const Fraction& frac);
    friend bool operator>=(const Fraction& fraction, float num);
    bool operator<(const Fraction& other) const;
    friend bool operator<(const Fraction& fraction, float num);
    friend bool operator<(float num, const Fraction& fraction);
    bool operator<=(const Fraction& other) const;
    friend bool operator<=(float num, const Fraction& frac);
    friend bool operator<=(const Fraction& fraction, float num);
    Fraction& operator++();
    Fraction operator++(int);
    Fraction& operator--();
    Fraction operator--(int);


    friend std::ostream& operator<<(std::ostream& oss, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& iss, Fraction& frc);
};


// namespace ariel

#endif // FRACTION_HPP*/

#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <iostream>
#include <cmath>
#include <stdexcept>

namespace ariel {}

    class Fraction {
    private:
        int numerator;
        int denominator;

        int getGCD(int a, int b);
        void reduce();

    public:
        Fraction();
        Fraction(int numerator, int denominator);
        Fraction(float numerator);

        int getNumerator() const;
        int getDenominator() const;
        void setNumerator(int newNumerator);
        void setDenominator(int newDenominator);

        Fraction operator+(const Fraction& frc) const;
        Fraction operator+(float num);
        friend Fraction operator+(float num, const Fraction& frc);

        Fraction operator-(const Fraction& frc);
        float operator-(float num);
        friend Fraction operator-(float num, const Fraction& frc);
        friend Fraction operator-(const Fraction& frc, float num);

        Fraction operator*(const Fraction& frc);
        float operator*(float num);
        friend Fraction operator*(float num, const Fraction& frc);
        friend Fraction operator*(const Fraction& frc, float num);

        Fraction operator/(const Fraction& frc);
        float operator/(float num);
        friend Fraction operator/(float num, const Fraction& frc);

        bool operator==(const Fraction& frc) const;
        bool operator==(const float& num) const;
        bool operator<=(const Fraction& frc) const;
        bool operator<=(float num) const;
        friend bool operator<=(const float& num, const Fraction& frc);
        bool operator<(const Fraction& frc) const;
        bool operator<(float num) const;
        friend bool operator<(const float& num, const Fraction& frc);
        bool operator>=(const Fraction& frc) const;
        bool operator>=(float num) const;
        friend bool operator>=(const float& num, const Fraction& frc);
        bool operator>(const Fraction& frc) const;
        bool operator>(float num) const;
        friend bool operator>(const float& num, const Fraction& frc);

        Fraction& operator++();
        Fraction operator++(int);
        Fraction& operator--();
        Fraction operator--(int);

        friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);
        friend std::istream& operator>>(std::istream& input, Fraction& frc);
    };

 
// namespace ariel

#endif // FRACTION_HPP


