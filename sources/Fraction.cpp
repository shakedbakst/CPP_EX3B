#include <iostream>
#include "Fraction.hpp"
#include <cmath>
//#include <climits>
//#include <cstdlib>
//#include <stdexcept>

using namespace ariel;
using namespace std;

#include <iostream>
#include "Fraction.hpp"



// Constructors
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
    num = static_cast<int>(std::round(numerator * 1000));
    denom = 1000;
    reduce(num, denom);
}

Fraction::Fraction(const Fraction& other): numerator(other.numerator), denominator(other.denominator) {}


//help function
/*int Fraction :: getGCD (int numerator, int denominator){
    if (numerator < 0){
        numerator = abs(numerator);
    }
    if (denominator < 0){
        denominator = abs(denominator);
    }
    if (denominator == 0){
        return numerator;
    }
    return (this -> getGCD(denominator, numerator%denominator));
}*/

void Fraction :: reduce(){
    int gcd = std::__gcd(numerator, denominator);
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
}//

Fraction operator+(const float num, const Fraction& frac){
    Fraction ans(num);
    return frac + ans; 
}//

Fraction Fraction::operator-(const Fraction& other) const{
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
}//

Fraction operator+(const float num, const Fraction& frac){
    Fraction ans(num);
    return ans + frac; 
}//

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
}//

Fraction operator*(double num, const Fraction &frac){
    Fraction ans(num);
    return ans * frac;
}//

Fraction Fraction::operator/(const Fraction& other) const{
    if(other.numerator == 0){
        throw std:: runtime_error("The denominator can not be 0");
    }
    long num = static_cast<long>(this->numerator) * static_cast<long>other.numerator;
    long denom = static_cast<long>(this->denominator) * static_cast<long>other.numerator;
    if (num < INT_MIN || denom < INT_MIN || num > INT_MAX || denom > INT_MAX) {
        throw std::overflow_error("One of the numerator or denominator are too short or too long");
    }
   return Fraction((int)num, (int)denom);
}

Fraction operator/(float num, const Fraction &frac){
    if(frac.numerator == 0){
        throw std:: runtime_error("The denominator can not be 0");
    }
    Fraction ans(num); 
    return ans/frac;
}//

Fraction operator/(const Fraction &frac, float num){
    if(num == 0){
        throw std :: runtime_error ("The denominator can not be 0");
    } 
    Fraction ans(num); 
    return frac/ans;
}//

//comparison operators 
bool Fraction::operator==(const Fraction& other) const{
    if (this ->numerator == 0 && other.numerator == 0){
        return true;
    }
    float frac1 = static_cast<float>(this->numerator) / this->denominator;
    float frac2 = static_cast<float>(other.numerator) / other.denominator;
    return round(frac1 * 1000)/1000 == round(frac2 * 1000)/1000;
}

bool Fraction :: operator==(float num) const{
    float frac1 = static_cast<float>this->numerator/this->denominator;
    return round(frac1*1000)/1000 == round(num*1000)/1000;
}

bool Fraction::operator!=(const Fraction& other) const{
    return true;
}
bool Fraction::operator>(const Fraction& other) const{
    return true;
}
bool Fraction::operator>=(const Fraction& other) const{
    return true;
}
bool Fraction::operator<(const Fraction& other) const{
    return true;
}
bool Fraction::operator<=(const Fraction& other) const{
    return true;
}

//increment and decrement methods
Fraction& Fraction::operator++(){
    this -> numerator += this -> denominator;
    return *this;
}
Fraction Fraction::operator++(int){
    return Fraction();
}
Fraction& Fraction::operator--(){
    return *this;
}
Fraction Fraction::operator--(int){
    return Fraction();
}



std::ostream& operator<<(std::ostream& oss, const Fraction& fraction){
    oss << fraction.getNumerator() << "/" << fraction.getDenominator();
    return oss;
}
std::istream& operator>>(std::istream& iss, const Fraction& fraction){
    return iss;
}







