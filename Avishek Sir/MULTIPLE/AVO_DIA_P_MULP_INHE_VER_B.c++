/*
AVOIDING THE DIAMOND PROBLEM IN MULTIPLE INHERITANCE WITH VIRTUAL BASE CLASSES
*/


#include <iostream>
using namespace std;


class grandparent {
protected:
    int gp; 

public:
   
    grandparent() {}
};


class parent1 : public virtual grandparent {
protected:
    int p1; 

public:
   
    parent1() {}
};


class parent2 : virtual public grandparent {
protected:
    int p2; 

public:
   
    parent2() {}
};

class child : private parent1, private parent2 {
private:
    int c;

public:

    child() {}

    
    child(int aa, int bb, int cc, int dd) {
        gp = aa; 
        p1 = bb; 
        p2 = cc; 
        c = dd;  
    
        cout << "\nGrandparent class parameter: gp = " << gp << endl
             << "Parent1 class parameter: p1 = " << p1 << endl
             << "Parent2 class parameter: p2 = " << p2 << endl
             << "Child class parameter: c = " << c << endl;
    }
};

int main() {
    // Create an object of the 'child' class with arguments for the constructor
    child mychild(1, 2, 3, 4);

    // Output success message
    cout << "\nSuccess" << endl;
    return 0;
}








