#include <iostream>
#include "Fraction.hpp"
#include <cmath>
#include <climits>
#include <cstdlib>
#include <stdexcept>

using namespace ariel;
using namespace std;

/*
// Constructors - final
Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("The denominator can not be 0");
    }
    if (numerator > INT_MAX || denominator > INT_MAX) {
        throw std::overflow_error("ERROR- overflow");
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


 Fraction::Fraction(float number) {
    this->numerator = static_cast<int>(std::round(numerator * 1000));
    this->denominator = 1000;
    reduce();
}



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

Fraction operator+(float num, const Fraction &fraction) {
    int numerator = std::round(num * fraction.getDenominator()) + fraction.getNumerator();
    int denominator = fraction.getDenominator();
    return Fraction(numerator, denominator);
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

Fraction operator-(float num, const Fraction &fraction) {
    int numerator = std::round(num * fraction.getDenominator()) - fraction.getNumerator();
    int denominator = fraction.getDenominator();
    return Fraction(numerator, denominator);
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

Fraction operator*(float num, const Fraction &frc) {
    int numerator = std::round(num * frc.getNumerator());
    int denominator = frc.getDenominator();
    return Fraction(numerator, denominator);
}

Fraction Fraction::Fraction::operator/(const Fraction& other) const{
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

Fraction operator/(float num, const Fraction &frac) {
    if (frac.getNumerator() == 0) {
        throw std::runtime_error("The denominator cannot be 0");
    }
    return Fraction(num * frac.getDenominator(), frac.getNumerator());
}

Fraction operator/(const Fraction &frac, float num) {
    if (num == 0) {
        throw std::runtime_error("The denominator can not be 0");
    }
    return Fraction(frac.getNumerator(), frac.getDenominator() * num);
}

//comparison operators - final
bool Fraction::operator==(const Fraction& frc) const {
    if (this->numerator == 0 && frc.getNumerator() == 0) {
        return true;
    }
    return (this->numerator * frc.getDenominator() == frc.getNumerator() * this->denominator);
}


bool Fraction::operator==(const float& num) const {
    double ans = std::round(static_cast<double>(this->numerator) / this->denominator * 1000) / 1000.0;
    double numRounded = std::round(num * 1000) / 1000.0;
    return (ans == numRounded);
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
}*/

//increment and decrement methods - final
/*Fraction& Fraction::operator++(){
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
}*/



/*Fraction& Fraction::operator++() {
    numerator += denominator;
    reduce();
    return *this;
}


Fraction Fraction::operator++(int) {
    Fraction frc(*this); // Create a copy of the current fraction
    numerator += denominator; // Increment the numerator
    reduce(); // Simplify the fraction
    return frc; // Return the copy (the original fraction)
}



Fraction& Fraction::operator--() {
    numerator -= denominator;
    reduce();
    return *this;
}



Fraction Fraction::operator--(int) {
    Fraction frc(*this); // Create a copy of the current fraction
    numerator -= denominator; // Increment the numerator
    reduce(); // Simplify the fraction
    return frc; // Return the copy (the original fraction)
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
   
}*/

Fraction::Fraction() : numerator(0), denominator(1) {}

Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    if (denominator == 0 && numerator != 0) {
        throw std::invalid_argument("Denominator can't be 0");
    }
    if (numerator > INT_MAX || denominator > INT_MAX) {
        throw std::overflow_error("Num is too large, should be an int");
    }
    if (denominator < 0) {
        this->numerator = -numerator;
        this->denominator = -denominator;
    }
    reduce();
}

Fraction::Fraction(float numerator) {
    int roundedNumerator = static_cast<int>(std::round(numerator * 1000));
    this->numerator = roundedNumerator;
    this->denominator = 1000;
    reduce();
}

int Fraction::getNumerator() const {
    return numerator;
}

int Fraction::getDenominator() const {
    return denominator;
}

void Fraction::setNumerator(int newNumerator) {
    numerator = newNumerator;
}

void Fraction::setDenominator(int newDenominator) {
    if (newDenominator == 0) {
        throw std::runtime_error("Denominator cannot be zero");
    }
    denominator = newDenominator;
}

int Fraction::getGCD(int a, int b) {
    a = abs(a);
    b = abs(b);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void Fraction::reduce() {
    int gcd = getGCD(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
}

Fraction Fraction::operator+(const Fraction& frc) const {
    long long check1 = static_cast<long long>(numerator) * frc.getDenominator() + static_cast<long long>(frc.getNumerator()) * denominator;
    long long check2 = static_cast<long long>(denominator) * frc.getDenominator();
    if (check1 > INT_MAX || check2 > INT_MAX || check1 < INT_MIN || check2 < INT_MIN) {
        throw std::overflow_error("Note we're using INTEGERS");
    }
    int num = numerator * frc.getDenominator() + frc.getNumerator() * denominator;
    int den = denominator * frc.getDenominator();
    return Fraction(num, den);
}

Fraction Fraction::operator+(float num) {
    Fraction ans(num);
    return *this + ans;
}

Fraction operator+(float num, const Fraction& frc) {
    Fraction ans(num);
    return ans + frc;
}

Fraction Fraction::operator-(const Fraction& frc) {
    long long check1 = static_cast<long long>(numerator) * frc.getDenominator() - static_cast<long long>(frc.getNumerator()) * denominator;
    long long check2 = static_cast<long long>(denominator) * frc.getDenominator();
    if (check1 > INT_MAX || check2 > INT_MAX || check1 < INT_MIN || check2 < INT_MIN) {
        throw std::overflow_error("Note we're using INTEGERS");
    }
    int num = numerator * frc.getDenominator() - frc.getNumerator() * denominator;
    int den = denominator * frc.getDenominator();
    return Fraction(num, den);
}

float Fraction::operator-(float num) {
    float numerator = this->numerator - num * this->denominator;
    return numerator / this->denominator;
}

Fraction operator-(float num, const Fraction& frc) {
    Fraction ans(num);
    return ans - frc;
}

Fraction operator-(const Fraction& frc, float num) {
    Fraction ans(num);
    return frc - ans;
}

Fraction Fraction::operator*(const Fraction& frc) {
    long long check1 = static_cast<long long>(numerator) * frc.getNumerator();
    long long check2 = static_cast<long long>(denominator) * frc.getDenominator();
    if (check1 > INT_MAX || check2 > INT_MAX || check1 < INT_MIN || check2 < INT_MIN) {
        throw std::overflow_error("Note we're using INTEGERS");
    }
    int num = numerator * frc.getNumerator();
    int den = denominator * frc.getDenominator();
    return Fraction(num, den);
}

float Fraction::operator*(float num) {
    double numer = static_cast<double>(numerator) * num;
    return numer / denominator;
}

Fraction operator*(float num, const Fraction& frc) {
    return frc * num;
}

Fraction operator*(const Fraction& frc, float num) {
    return frc * num;
}

Fraction Fraction::operator/(const Fraction& frc) {
    if (frc.getNumerator() == 0) {
        throw std::runtime_error("Dividing by 0 is illegal!");
    }
    long long check1 = static_cast<long long>(numerator) * frc.getDenominator();
    long long check2 = static_cast<long long>(denominator) * frc.getNumerator();
    if (check1 > INT_MAX || check2 > INT_MAX || check1 < INT_MIN || check2 < INT_MIN) {
        throw std::overflow_error("Note we're using INTEGERS");
    }
    int num = numerator * frc.getDenominator();
    int den = denominator * frc.getNumerator();
    return Fraction(num, den);
}

float Fraction::operator/(float num) {
    if (num == 0) {
        throw std::runtime_error("Dividing by 0 is illegal!");
    }
    float current = static_cast<float>(numerator) / denominator;
    float ans = current / num;
    return ans;
}

Fraction operator/(float num, const Fraction& frc) {
    if (frc.getNumerator() == 0) {
        throw std::runtime_error("Dividing by 0 is illegal!");
    }
    float frcValue = static_cast<float>(frc.getNumerator()) / frc.getDenominator();
    float ans = num / frcValue;
    return Fraction(ans);
}

bool Fraction::operator==(const Fraction& frc) const {
    if (this->numerator == 0 && frc.getNumerator() == 0) {
        return true;
    }
    double ans1 = std::round(static_cast<double>(numerator) / denominator * 1000) / 1000.0;
    double ans2 = std::round(static_cast<double>(frc.getNumerator()) / frc.getDenominator() * 1000) / 1000.0;
    return ans1 == ans2;
}

bool Fraction::operator==(const float& num) const {
    double ans1 = std::round(static_cast<double>(numerator) / denominator * 1000) / 1000.0;
    double ans2 = std::round(num * 1000) / 1000.0;
    return ans1 == ans2;
}

bool Fraction::operator<=(const Fraction& frc) const {
    return (numerator * frc.getDenominator()) <= (frc.getNumerator() * denominator);
}

bool Fraction::operator<=(float num) const {
    return numerator <= num * denominator;
}

bool operator<=(const float& num, const Fraction& frc) {
    return frc >= num;
}

bool Fraction::operator<(const Fraction& frc) const {
    return (numerator * frc.getDenominator()) < (frc.getNumerator() * denominator);
}

bool Fraction::operator<(float num) const {
    return numerator < num * denominator;
}

bool operator<(const float& num, const Fraction& frc) {
    return frc > num;
}

bool Fraction::operator>=(const Fraction& frc) const {
    return (numerator * frc.getDenominator()) >= (frc.getNumerator() * denominator);
}

bool Fraction::operator>=(float num) const {
    return numerator >= num * denominator;
}

bool operator>=(const float& num, const Fraction& frc) {
    return frc <= num;
}

bool Fraction::operator>(const Fraction& frc) const {
    return (numerator * frc.getDenominator()) > (frc.getNumerator() * denominator);
}

bool Fraction::operator>(float num) const {
    return numerator > num * denominator;
}

bool operator>(const float& num, const Fraction& frc) {
    return frc < num;
}

Fraction& Fraction::operator++() {
    numerator += denominator;
    return *this;
}

Fraction Fraction::operator++(int) {
    Fraction frc(*this); // Create a copy of the current fraction
    numerator += denominator;
    return frc;
}

Fraction& Fraction::operator--() {
    numerator -= denominator;
    return *this;
}

Fraction Fraction::operator--(int) {
    Fraction frc(*this); // Create a copy of the current fraction
    numerator -= denominator;
    return frc;
}

std::ostream& operator<<(std::ostream& output, const Fraction& fraction) {
    output << fraction.getNumerator() << '/' << fraction.getDenominator();
    return output;
}

std::istream& operator>>(std::istream& input, Fraction& frc) {
    std::string fractionString;
    input >> fractionString;

    std::istringstream iss(fractionString);
    int numerator, denominator;
    char separator;

    if (!(iss >> numerator)) {
        throw std::runtime_error("Invalid fraction format: missing numerator");
    }
    if (!(iss >> separator) || separator != '/') {
        throw std::runtime_error("Invalid fraction format: missing or incorrect separator");
    }
    if (!(iss >> denominator)) {
        throw std::runtime_error("Invalid fraction format: missing denominator");
    }

    if (denominator == 0) {
        throw std::runtime_error("Invalid fraction: denominator cannot be zero");
    }

    frc.setNumerator(numerator);
    frc.setDenominator(denominator);

    return input;
}











