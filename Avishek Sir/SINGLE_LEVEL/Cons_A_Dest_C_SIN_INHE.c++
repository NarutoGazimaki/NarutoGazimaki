/*
CONSTRUCTOR AND DESTRUCTOR CALL IN SINGLE LEVEL INHERITANCE
*/


#include <iostream>
using namespace std;


class parent {
public:

    parent() {
        cout << "\nCall to Parent class constructor";
    }


    ~parent();
};


parent::~parent() {
    cout << "\nCall to Parent class destructor" << endl;
}


class child : public parent {
public:
  
    child() {
        cout << "\nCall to Child class constructor";
    }

    ~child();
};

child::~child() {
    cout << "\nCall to Child class destructor" << endl;
}

int main() {
    child c;
    cout << endl; 
    return 0;
}
