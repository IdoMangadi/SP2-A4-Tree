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
            double getReal();
            double getImag();

            Complex operator+(Complex c2);
            Complex operator-(Complex c2);
            bool operator==(Complex c2);
            bool operator!=(Complex c2);
            bool operator<(Complex c2);
            bool operator>(Complex c2);
            bool operator<=(Complex c2);
            bool operator>=(Complex c2);

            friend ostream& operator<<(ostream& os, Complex c);
    };



}