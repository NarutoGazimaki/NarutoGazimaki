/*
SINGLE LEVEL INHERITANCE CONSTRUCTOR AND DESTRUCTOR CALS WITH ARGUMENT PASSING FROM CHILD TO PARENT
*/

#include <iostream>
using namespace std;

class parent {
private:
    int a;

protected:
    int b;

public:
   
    parent() { }

   
    parent(int x) {
        cout << "\nCall to parent constructor";
        a = x;
        cout << "\nParent: a = " << a << endl;
    }


    ~parent() {
        cout << "\nCall to parent class destructor" << endl;
    }
};

class child : private parent {
private:
    int c;

protected:
    int d;

public:

    child(int x) : parent(x) {  
        cout << "\nCall to child constructor";
       
    }

   
    ~child() {
        cout << "\nCall to child class destructor" << endl;
    }
};

int main() {
    child obj(10); 
    return 0;
}
