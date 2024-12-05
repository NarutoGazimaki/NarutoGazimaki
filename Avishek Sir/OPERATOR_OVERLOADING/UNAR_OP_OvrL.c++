/*UNARY OPERATOR OVERLOADING
*/
#include <iostream>
using namespace std;

class Counter {
private:
    int value;

public:
    Counter() : value(0) {}


    Counter& operator++() {
        ++value; 
        return *this; 
    }

  
    Counter operator++(int) {
        Counter temp = *this;  
        ++value; 
        return temp; 
    }


    Counter& operator--() {
        --value; 
        return *this;  
    }

  
    Counter operator--(int) {
        Counter temp = *this;  
        --value; 
        return temp;  
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c1;

    c1.display();  
    ++c1;  
    c1.display(); 

    c1++;  
    c1.display();  

    --c1; 
    c1.display();  

    c1--; 
    c1.display(); 

    return 0;
}
