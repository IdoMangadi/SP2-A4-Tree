
#include "Complex.hpp"

using namespace std;

namespace myComplex{
    
        Complex::Complex(double real, double imag) : real(real), imag(imag){}
    
        double Complex::getReal(){
            return this->real;
        }
    
        double Complex::getImag(){
            return this->imag;
        }
    
        Complex Complex::operator+(Complex c2){
            return Complex(this->real + c2.real, this->imag + c2.imag);
        }
    
        Complex Complex::operator-(Complex c2){
            return Complex(this->real - c2.real, this->imag - c2.imag);
        }
    
        bool Complex::operator==(Complex c2){
            return this->real == c2.real && this->imag == c2.imag;
        }
    
        bool Complex::operator!=(Complex c2){
            return !(*this == c2);
        }
    
        bool Complex::operator<(Complex c2){
            return this->real < c2.real || (this->real == c2.real && this->imag < c2.imag);
        }
    
        bool Complex::operator>(Complex c2){
            return this->real > c2.real || (this->real == c2.real && this->imag > c2.imag);
        }
    
        bool Complex::operator<=(Complex c2){
            return *this < c2 || *this == c2;
        }
    
        bool Complex::operator>=(Complex c2){
            return *this > c2 || *this == c2;
        }
    
        ostream& operator<<(ostream& os, Complex c){
            os << c.real << " + " << c.imag << "i";
            return os;
        }
}