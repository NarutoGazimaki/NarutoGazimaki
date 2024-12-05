/*
MULTILEVEL INHERITANCE WITH CONSTRUCTOR AND DESTRUCTOR CALLS AND ARGUMENT PASSING
*/

#include <iostream>
using namespace std;


class grandparent {
private:
    int a; 

public:
    
    grandparent() {}

 
    grandparent(int aa) {
        a = aa;
        cout << "\nGrandparent Constructor: a = " << a << endl;
    }

  
    ~grandparent() {
        cout << "\nGrandparent Destructor" << endl << endl;
    }
};

class parent : protected grandparent {
protected:
    int b;

public:
  
    parent() {}

   
    parent(int aa, int bb) : grandparent(aa) {
        b = bb;
        cout << "\nParent Constructor: b = " << b << endl;
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

   
    child(int x, int y, int z) : parent(x, y) {
        c = z;
        cout << "\nChild Constructor: c = " << c << endl;
    }

  
    ~child() {
        cout << "\nChild Destructor";
    }
};

int main() {
   
    child c(1, 2, 3);
    return 0;
}
