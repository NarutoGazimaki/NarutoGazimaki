/*
ARRAY OF OBJECTS INPUT OF MULTIWORD STRINGS AND DYNAMIC MEMORY MANAGEMENT
*/

#include<iostream>
using namespace std;

class student {
private:
    int roll;
    string name;

public:
    // Constructor
    student() {
        cout << "\nCall to Constructor:";
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "\nEnter name: ";
        cin.ignore(); 
        getline(cin, name); 
    }

   
    void showdata() {
        cout << "\nRoll = " << roll << " Name : " << name;
    }

   
    ~student() {
        cout << "\nCall to Destructor";
    }
};

int main() {
   
    student* list = new student[3];
    
   
    for (int loop = 0; loop < 3; loop++) {
        list[loop].showdata(); 
    }

   
    delete[] list;

    cout << "\nSuccess" << endl;
    return 0;
}
