#include <iostream>
#include "Fraction.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
#include <stdexcept>

using namespace ariel;
using namespace std;


// Constructors - final
Fraction::Fraction(){
    this->numerator = 0;
    this->denominator = 1;
}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("The denominator can not be 0");
    }
    if (denominator < 0){
        if(numerator < 0){
            numerator = abs(numerator);
            denominator = abs(denominator);
        }
        if(numerator > 0){
            numerator = numerator * -1;
            denominator = abs(denominator);
        }
    } else {
        this -> numerator = numerator;
        this -> denominator = denominator;
    }
    reduce();
}

 Fraction::Fraction(float number) {
    int num = static_cast<int>(std::round(numerator * 1000));
    int denom = 1000;
    reduce();
}

Fraction::Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {}


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
    int gcd = -getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}



// Getters and Setters - final
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


//arithmetic operators - final
Fraction Fraction::operator+(const Fraction& other) const{
    long num = static_cast<long>(this->numerator) * other.denominator + static_cast<long>(other.numerator) * this->denominator;
    long denom = static_cast<long>(this->denominator) * other.denominator;
    if (num < INT_MIN || denom < INT_MIN || num > INT_MAX || denom > INT_MAX) {
        throw std::overflow_error("One of the numerator or denominator are too short or too long");
    }
   return Fraction((int)num, (int)denom);
}

Fraction operator+(const Fraction& fraction , float num){
    Fraction ans(num);
    return fraction + ans;  
}

Fraction operator+(float num, const Fraction& fraction){
    int numNumerator = static_cast<int>(num * fraction.getDenominator());
    int numDenominator = fraction.getDenominator();
    return Fraction(fraction.getNumerator() + numNumerator, numDenominator);
}

Fraction Fraction::operator-(const Fraction& other) const{
    long num = static_cast<long>(this->numerator) * other.denominator + static_cast<long>(other.numerator) * this->denominator;
    long denom = static_cast<long>(this->denominator) * other.denominator;
    if (num < INT_MIN || denom < INT_MIN || num > INT_MAX || denom > INT_MAX) {
        throw std::overflow_error("One of the numerator or denominator are too short or too long");
    }
   return Fraction((int)num, (int)denom);
}

Fraction operator-(const Fraction& fraction , float num){
    Fraction ans(num);
    return fraction - ans;  
}

Fraction operator-(float num, const Fraction& fraction){
    int numNumerator = static_cast<int>(num * fraction.getDenominator());
    int numDenominator = fraction.getDenominator();
    return Fraction(fraction.getNumerator() - numNumerator, numDenominator);
}

Fraction Fraction::operator*(const Fraction& other) const{
    long num = static_cast<long>(this->numerator) * other.numerator;
    long denom = static_cast<long>(this->denominator) * other.denominator;
    if (num < INT_MIN || denom < INT_MIN || num > INT_MAX || denom > INT_MAX) {
        throw std::overflow_error("One of the numerator or denominator are too short or too long");
    }
   return Fraction((int)num, (int)denom);
}

Fraction operator*(const Fraction &frac, float num){
    Fraction ans(num);
    return frac*ans;
}

Fraction operator*(double num, const Fraction &frac){
    Fraction ans(num);
    return ans * frac;
}

Fraction Fraction::operator/(const Fraction& other) const{
    if(other.numerator == 0){
        throw std:: runtime_error("The denominator can not be 0");
    }
    long num = static_cast<long>(this->numerator) * static_cast<long>(other.numerator);
    long denom = static_cast<long>(this->denominator) * static_cast<long>(other.numerator);
    if (num < INT_MIN || denom < INT_MIN || num > INT_MAX || denom > INT_MAX) {
        throw std::overflow_error("One of the numerator or denominator are too short or too long");
    }
   return Fraction((int)num, (int)denom);
}

Fraction operator/(float num, const Fraction &frac){
    if(frac.getNumerator() == 0){
        throw std:: runtime_error("The denominator can not be 0");
    }
    Fraction ans(num); 
    return ans/frac;
}

Fraction operator/(const Fraction &frac, float num){
    if(num == 0){
        throw std :: runtime_error ("The denominator can not be 0");
    } 
    Fraction ans(num); 
    return frac/ans;
}

//comparison operators - final
bool Fraction::operator==(const Fraction& other) const {
    double thisValue = static_cast<double>(numerator) / denominator;
    double otherValue = static_cast<double>(other.numerator) / other.denominator;
    return std::abs(thisValue - otherValue) < 0.001;
}

/*bool Fraction::operator==(float num) const {
    double thisValue = static_cast<double>(numerator) / denominator;
    return std::abs(thisValue - num) < 0.001;
}*/

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


//increment and decrement methods - final
Fraction& Fraction::operator++(){
    numerator = this->numerator + this->denominator;
    return *this;
}
Fraction Fraction::operator++(int){
    Fraction result(*this);
    numerator = this->numerator + this->denominator;
    return result;
}

Fraction& Fraction::operator--(){
    numerator = this->numerator - this->denominator;
    return *this;
}
Fraction Fraction::operator--(int){
    Fraction result(*this);
    numerator = this->numerator - this->denominator;
    return result;
}

///////////

std::ostream& operator<<(std::ostream& oss, const Fraction& fraction){
    oss << fraction.getNumerator() << "/" << fraction.getDenominator();
    return oss;

}
std::istream& operator>>(std::istream& iss, Fraction& frc) {
    int numerator, denominator;
    
    if (iss.peek() == EOF) {
        throw std::runtime_error("No numbers entered!");
    }
    
    iss >> numerator;
    
    if (iss.peek() == EOF) {
        throw std::runtime_error("Please add another number");
    }
    
    iss >> denominator;
    
    if (denominator < 0) {
        numerator = -1 * numerator;
        denominator = -1 * denominator;
    }
    
    frc.setNumerator(numerator);
    frc.setDenominator(denominator);
    
    return iss;
}








