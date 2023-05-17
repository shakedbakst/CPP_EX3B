#include <iostream>
#include "Fraction.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
#include <stdexcept>

using namespace ariel;
using namespace std;


// Constructors 
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("The denominator can not be 0");
    }
    if (denominator < 0){
        this ->numerator = -1* numerator;
        this ->denominator = -1 * denominator;
    }
    else{
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    reduce();

}

Fraction::Fraction(float number) : numerator(std::round(number * 1000)), denominator(1000) {
    reduce();
}


//Help functions
int Fraction::getGCD(int numerator, int denominator) {
    int absNumerator = std::abs(numerator);
    int absDenominator = std::abs(denominator);

    while (absDenominator != 0) {
        int temp = absDenominator;
        absDenominator = absNumerator % absDenominator;
        absNumerator = temp;
    }

    return absNumerator;
}


void Fraction :: reduce(){
    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}



// Getters and Setters 
int Fraction::getNumerator() const{
    return this->numerator;
}
int Fraction::getDenominator() const{
    return this->denominator;
}
void Fraction::setNumerator(int numerator){
    this->numerator = numerator;
    reduce();
}
void Fraction::setDenominator(int denominator){
    if(denominator == 0){
        throw std:: invalid_argument("The denominator can not be 0");
    }
    this->denominator = denominator;
    reduce();
}


//arithmetic operators 
Fraction Fraction::operator+(const Fraction& other) const {
    long long num = static_cast<long long>(numerator) * other.denominator + static_cast<long long>(other.numerator) * denominator;
    long long denom = static_cast<long long>(denominator) * other.denominator;

    if (num < std::numeric_limits<int>::min() || denom < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max() || denom > std::numeric_limits<int>::max()) {
        throw std::overflow_error("One of the numerator or denominator is too short or too long");
    }

    return Fraction(static_cast<int>(num), static_cast<int>(denom));
}

Fraction operator+(const Fraction& fraction, float num) {
    return fraction + Fraction(num);
}

Fraction operator+(float num, const Fraction& fraction) {
    return Fraction(num) + fraction;
}

Fraction Fraction::operator-(const Fraction& other) const {
    long long num = static_cast<long long>(numerator) * other.denominator - static_cast<long long>(other.numerator) * denominator;
    long long denom = static_cast<long long>(denominator) * other.denominator;

    if (num < std::numeric_limits<int>::min() || denom < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max() || denom > std::numeric_limits<int>::max()) {
        throw std::overflow_error("One of the numerator or denominator is too short or too long");
    }

    return Fraction(static_cast<int>(num), static_cast<int>(denom));
}

Fraction operator-(const Fraction& fraction , float num){
    return fraction - Fraction(num);  
}

Fraction operator-(float num, const Fraction &fraction) {
    return Fraction(num) - fraction;
}

Fraction Fraction::operator*(const Fraction& other) const {
    long long num = static_cast<long long>(numerator) * other.numerator;
    long long denom = static_cast<long long>(denominator) * other.denominator;

    if (num < std::numeric_limits<int>::min() || denom < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max() || denom > std::numeric_limits<int>::max()) {
        throw std::overflow_error("One of the numerator or denominator is too short or too long");
    }

    return Fraction(static_cast<int>(num), static_cast<int>(denom));
}

Fraction operator*(const Fraction &frac, float num){
    return frac * Fraction(num);
}

Fraction operator*(double num, const Fraction &frac){
    return Fraction(num) * frac;
}

Fraction Fraction::operator/(const Fraction& other) const {
    if (other.numerator == 0) {
        throw std::runtime_error("The denominator cannot be 0");
    }

    long long num = static_cast<long long>(numerator) * static_cast<long long>(other.denominator);
    long long denom = static_cast<long long>(denominator) * static_cast<long long>(other.numerator);

    if (num < std::numeric_limits<int>::min() || denom < std::numeric_limits<int>::min() || num > std::numeric_limits<int>::max() || denom > std::numeric_limits<int>::max()) {
        throw std::overflow_error("One of the numerator or denominator is too short or too long");
    }

    return Fraction(static_cast<int>(num), static_cast<int>(denom));
}

Fraction operator/(float num, const Fraction &frac) {
    if (frac.getNumerator() == 0) {
        throw std::runtime_error("The denominator cannot be 0");
    }
    return Fraction(num) / frac;
}

Fraction operator/(const Fraction &frac, float num) {
    if (num == 0) {
        throw std::runtime_error("The denominator can not be 0");
    }
    return frac / Fraction(num);
}


//comparison operators 
bool Fraction::operator==(const Fraction& frc) const {
    if (numerator == 0 && frc.numerator == 0) {
        return true;
    }
    return (numerator * frc.denominator == frc.numerator * denominator);
}

bool Fraction::operator==(const float& num) const {
    double thisValue = static_cast<double>(numerator) / denominator;
    double numRounded = std::round(num * 1000) / 1000.0;
    return (std::abs(thisValue - numRounded) < 0.0001);
}

bool Fraction::operator>(const Fraction& other) const {
    float thisValue = static_cast<float>(numerator) / static_cast<float>(denominator);
    float otherValue = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
    return thisValue > otherValue;
}

bool operator>(const Fraction& fraction, float num) {
    float fracValue = static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator());
    return fracValue > num;
}

bool operator>(float num, const Fraction& fraction) {
    float fracValue = static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator());
    return num > fracValue;
}

bool Fraction::operator>=(const Fraction& other) const {
    float thisValue = static_cast<float>(numerator) / static_cast<float>(denominator);
    float otherValue = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
    return thisValue >= otherValue;
}

bool operator>=(float num, const Fraction& frac) {
    float fracValue = static_cast<float>(frac.getNumerator()) / static_cast<float>(frac.getDenominator());
    return num >= fracValue;
}

bool operator>=(const Fraction& fraction, float num) {
    float fracValue = static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator());
    return fracValue >= num;
}

bool Fraction::operator<(const Fraction& other) const {
    float thisValue = static_cast<float>(numerator) / static_cast<float>(denominator);
    float otherValue = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
    return thisValue < otherValue;
}

bool operator<(const Fraction& fraction, float num) {
    float fracValue = static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator());
    return fracValue < num;
}

bool operator<(float num, const Fraction& fraction) {
    float fracValue = static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator());
    return num < fracValue;
}

bool Fraction::operator<=(const Fraction& other) const {
    float thisValue = static_cast<float>(numerator) / static_cast<float>(denominator);
    float otherValue = static_cast<float>(other.numerator) / static_cast<float>(other.denominator);
    return thisValue <= otherValue;
}

bool operator<=(float num, const Fraction& frac) {
    float fracValue = static_cast<float>(frac.getNumerator()) / static_cast<float>(frac.getDenominator());
    return num <= fracValue;
}

bool operator<=(const Fraction& fraction, float num) {
    float fracValue = static_cast<float>(fraction.getNumerator()) / static_cast<float>(fraction.getDenominator());
    return fracValue <= num;
}


//increment and decrement methods 
Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction result(*this);
    operator++();
    return result;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction result(*this);
    operator--();
    return result;
}


//String operators
std::ostream& operator<<(std::ostream& oss, const Fraction& fraction){
    oss << fraction.getNumerator() << "/" << fraction.getDenominator();
    return oss;
}

std::istream& operator>>(std::istream& iss, Fraction& frc) {
    int numerator, denominator;
    
    if (!(iss >> numerator)) {
        throw std::runtime_error("No numbers entered!");
    }
    
    if (!(iss >> denominator)) {
        throw std::runtime_error("Please add another number");
    }
    
    if (denominator == 0) {
        throw std::runtime_error("The denominator cannot be 0");
    }
    
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
    
    frc.setNumerator(numerator);
    frc.setDenominator(denominator);
    
    return iss;
}
