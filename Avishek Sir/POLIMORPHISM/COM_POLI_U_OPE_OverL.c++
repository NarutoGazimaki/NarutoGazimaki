/*
COMPILETIME POLIMORPHISM USING OPERATOR OVERLOADING
*/
#include<iostream>
using namespace std;

class student {
private:
    int roll; 

public:
 
    student() {}

    
    student(int r) {
        this->roll = r;
        cout << "\nRoll = " << roll << endl;
    }

 
    void getroll() {
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "\nRoll = " << roll << endl;
    }

 
    void getroll(int r) {
        this->roll = r;
        cout << "\nRoll = " << roll << endl;
    }
};

int main() {
   
    student s1, s2(1);

   
    s1.getroll();

   
    s1.getroll(3);

    return 0;
}
