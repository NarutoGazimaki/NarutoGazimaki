/*SIMPLE INTEGER ADDITION PROGRAM USING CLASS AND ITS MEMBER FUNCTION IN C++
*/



#include <iostream>
using namespace std;


class Adder {
    private:
        int num1, num2; 

    public:
       
        void setValues(int n1, int n2) {
            num1 = n1;
            num2 = n2;
        }

       
        int add() {
            return num1 + num2;  
        }
};

int main() {
    Adder adder; 

    int x, y;
    cout << "Enter two integers to add: ";
    cin >> x >> y;

   
    adder.setValues(x, y);

   
    cout << "The sum is: " << adder.add() << endl;

    return 0;
}
