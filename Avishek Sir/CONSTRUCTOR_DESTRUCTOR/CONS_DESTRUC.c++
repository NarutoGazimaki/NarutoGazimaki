/*CONSTRUCTOR AND DESTRUCTOR EXAMPLE IN C++
*/


#include <iostream>
#include <string> 
using namespace std;

class student {
private:
    int roll;          
    string name;      
    char course[50];   
public:
    student();         
    ~student();        
};


student::student() {
    cout << "\nEnter name: ";
  
    getline(cin, name);

    cout << "\nEnter roll number: ";
    cin >> roll;

    cout << "\nEnter course: ";
    cin >> course;

    cout << "\nRoll = " << roll
         << "\nName = " << name
         << "\nCourse name = " << course << endl;
}


student::~student() {
    cout << "\nDestructor called: Object is being destroyed" << endl;
}

int main() {
    student s; 
    
    return 0;
}
