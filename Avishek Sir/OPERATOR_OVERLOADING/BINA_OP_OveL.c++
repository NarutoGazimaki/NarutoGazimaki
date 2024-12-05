#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    Complex operator+(const Complex& obj) {
        Complex temp;
        temp.real = this->real + obj.real;
        temp.imag = this->imag + obj.imag;
        return temp;
    }


    void display() const {
        cout << "Real: " << real << ", Imag: " << imag << endl;
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    Complex c3 = c1 + c2;  

    c3.display(); 
    return 0;
}
