// ID: 315310250
// EMAIL: IDOIZHAR.Mangadi@msmail.ariel.ac.il
// GMAIL: idomangadi@gmail.com

#include "Complex.hpp"

using namespace std;

namespace myComplex{
    
        Complex::Complex(double real, double imag) : real(real), imag(imag){}
    
        double Complex::getReal() const{
            return this->real;
        }
    
        double Complex::getImag() const{
            return this->imag;
        }
    
        Complex Complex::operator+(const Complex c2) const{
            return Complex(this->real + c2.real, this->imag + c2.imag);
        }
    
        Complex Complex::operator-(const Complex c2) const{
            return Complex(this->real - c2.real, this->imag - c2.imag);
        }

        Complex Complex::operator*(const Complex c2) const{
            return Complex(this->real * c2.real - this->imag * c2.imag, this->real * c2.imag + this->imag * c2.real);
        }

        Complex Complex::operator/(const Complex c2) const{
            double denominator = c2.real * c2.real + c2.imag * c2.imag;
            return Complex((this->real * c2.real + this->imag * c2.imag) / denominator, (this->imag * c2.real - this->real * c2.imag) / denominator);
        }
    
        bool Complex::operator==(const Complex& c2) const{
            return this->real == c2.real && this->imag == c2.imag;
        }
    
        bool Complex::operator!=(const Complex c2) const{
            return !(*this == c2);
        }
    
        bool Complex::operator<(const Complex c2) const{ 
            return this->real < c2.real || (this->real == c2.real && this->imag < c2.imag);
        }
    
        bool Complex::operator>(const Complex c2) const{
            return this->real > c2.real || (this->real == c2.real && this->imag > c2.imag);
        }
    
        bool Complex::operator<=(const Complex c2) const{
            return *this < c2 || *this == c2;
        }
    
        bool Complex::operator>=(const Complex c2) const{
            return *this > c2 || *this == c2;
        }
    
        ostream& operator<<(ostream& os, const Complex c){
            os << c.real << " + " << c.imag << "i";
            return os;
        }
}