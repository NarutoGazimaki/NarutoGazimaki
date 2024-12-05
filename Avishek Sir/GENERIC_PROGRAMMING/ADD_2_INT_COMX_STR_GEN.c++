/*WRITE A PROGRAM IN C++ TO PERFORM THE ADDITION OF 2 INTEGERS 2 COMPLEX NUMBERS AND 2 STRINGS USING THE CONCEPT OF GENERIC PROGRAMMING*/
#include <iostream>
#include <string>
using namespace std;


template <typename T>
T add(T a, T b) {
    return a + b;
}


class Complex {
private:
    double real;
    double imag;

public:
    
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

   
    Complex operator + (const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

  
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    
    int num1, num2;
    cout << "Enter two integers: ";
    cin >> num1 >> num2;
    cout << "Sum of integers: " << add(num1, num2) << endl;

    
    double real1, imag1, real2, imag2;
    cout << "Enter real and imaginary parts of first complex number: ";
    cin >> real1 >> imag1;
    cout << "Enter real and imaginary parts of second complex number: ";
    cin >> real2 >> imag2;

    Complex c1(real1, imag1), c2(real2, imag2);
    Complex c3 = c1 + c2;
    cout << "Sum of complex numbers: ";
    c3.display();

 
    string str1, str2;
    cout << "Enter two strings: ";
    cin >> str1 >> str2;
    cout << "Concatenated string: " << add(str1, str2) << endl;

    return 0;
}
