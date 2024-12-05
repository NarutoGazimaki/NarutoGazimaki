/*
CONSTRUCTOR OVERLOADING IN ARRAY OF OBJECTS 
*/


#include <iostream>
using namespace std;

class student {
private:
    int roll;
    int courseid;

public:
   
    student() { }

 
    student(int r, int c) {
        roll = r;
        courseid = c;
        cout << "\nRoll = " << roll;
        cout << "\nCourseid = " << courseid << endl;
    }


    void getdata() {
        cout << "\nEnter roll: ";
        cin >> roll;
        cout << "\nEnter courseid: ";
        cin >> courseid;
    }

  
    void showdata();

  
    ~student(); 
};

void student::showdata() {
    cout << "\nRoll = " << roll
         << "\nCourseid = " << courseid << endl;
}


student::~student() {
    cout << "\nCall to Destructor" << endl;
}

int main() {
    student s[2];
    int loop;

   
    for (loop = 0; loop < 2; loop++) {
        s[loop].getdata();
    }

  
    for (loop = 0; loop < 2; loop++) {
        s[loop].showdata();
    }

    return 0;
}

