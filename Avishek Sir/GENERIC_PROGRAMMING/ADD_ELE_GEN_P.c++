/*WRITE A C++ PROGRAM TO ADD TWO ELEMENTS USING CONCEPT OF GENERIC PROGRAMMING*/
#include <iostream>
using namespace std;


template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
  
    int int1, int2;
    cout << "Enter two integers: ";
    cin >> int1 >> int2;
    cout << "Sum of integers: " << add(int1, int2) << endl;

    float float1, float2;
    cout << "Enter two floats: ";
    cin >> float1 >> float2;
    cout << "Sum of floats: " << add(float1, float2) << endl;

 
    double double1, double2;
    cout << "Enter two doubles: ";
    cin >> double1 >> double2;
    cout << "Sum of doubles: " << add(double1, double2) << endl;

    return 0;
}
