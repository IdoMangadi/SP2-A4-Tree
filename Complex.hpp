// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#include <iostream>
#include <string>


using namespace std;

namespace myComplex{

    class Complex{
        private:
            double real;
            double imag;
        
        public: 
            Complex(double real, double imag);
            double getReal() const;
            double getImag() const;

            Complex operator+(const Complex c2) const;
            Complex operator-(const Complex c2) const;
            Complex operator*(const Complex c2) const;
            Complex operator/(const Complex c2) const;
            bool operator==(const Complex& c2) const;
            bool operator!=(const Complex c2) const;
            bool operator<(const Complex c2) const;
            bool operator>(const Complex c2) const;
            bool operator<=(const Complex c2) const;
            bool operator>=(const Complex c2) const;

            friend ostream& operator<<(ostream& os, const Complex c);
    };



}