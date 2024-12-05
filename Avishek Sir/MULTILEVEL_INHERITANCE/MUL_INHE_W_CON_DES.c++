/*
MULTILEVEL INHERITANCE WITH CONSTRUCTOR AND DESTRUCTOR CALLS
*/

#include <iostream>
using namespace std;


class grandparent {
public:
   
    grandparent() {
        cout << "\nGrandparent Constructor";
    }

    
    ~grandparent() {
        cout << "\nGrandparent Destructor" << endl << endl;
    }
};


class parent : protected grandparent {
public:
  
    parent() {
        grandparent(); 
        cout << "\nParent Constructor";
    }

  
    ~parent() {
        cout << "\nParent Destructor";
    }
};


class child : private parent {
public:
   
    child() {
        parent(); 
        cout << "\nChild Constructor" << endl;
    }

    
    ~child() {
        cout << "\nChild Destructor";
    }
};

int main() {
   
    child c;
    return 0;
}
