/*
MULTILEVEL INHERITANCE WITH ACCESS CONTROL AND ARGUMENT PASSING
*/

#include <iostream>
using namespace std;


class grandparent {
protected:
    int a;

public:
    
    grandparent() {
        cout << "\nGrandparent Constructor";
    }

   
    ~grandparent() {
        cout << "\nGrandparent Destructor" << endl << endl;
    }
};


class parent : protected grandparent {
protected:
    int b; 

public:
   
    parent() {
        
        cout << "\nParent Constructor";
    }

    ~parent() {
        cout << "\nParent Destructor";
    }
};


class child : private parent {
private:
    int c; 

public:
   
    child() {}

   
    child(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
        cout << "\nChild Constructor: ";
        cout << "\nValue = " << endl
             << a << endl
             << b << endl
             << c << endl;
    }

   
    ~child() {
        cout << "\nChild Destructor";
    }
};

int main() {
    
    child c(1, 2, 3);
    return 0;
}

