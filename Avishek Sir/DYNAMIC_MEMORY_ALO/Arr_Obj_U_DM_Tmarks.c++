/*
ARRY OF OBJECTS USING DYNAMIC MEMORY ALLOCATION FOR TOTAL MARKS CALCULATION
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int marks1, marks2, marks3;

public:
   
    Student() {
        name = "";
        marks1 = marks2 = marks3 = 0;
    }

   
    Student(string studentName, int m1, int m2, int m3) {
        name = studentName;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }

   
    int totalMarks() {
        return marks1 + marks2 + marks3;
    }

   
    void display() {
        cout << "Name: " << name << endl;
        cout << "Marks: " << marks1 << ", " << marks2 << ", " << marks3 << endl;
        cout << "Total Marks: " << totalMarks() << endl;
    }


    void setDetails(string studentName, int m1, int m2, int m3) {
        name = studentName;
        marks1 = m1;
        marks2 = m2;
        marks3 = m3;
    }
};

int main() {
    int n;

   
    cout << "Enter the number of students: ";
    cin >> n;

    
    Student* students = new Student[n];

   
    for (int i = 0; i < n; ++i) {
        string name;
        int m1, m2, m3;

       
        cout << "\nEnter details for student " << i + 1 << ":" << endl;
        cout << "Name: ";
        cin.ignore();  
        getline(cin, name);
        cout << "Enter marks for 3 subjects: ";
        cin >> m1 >> m2 >> m3;

       
        students[i].setDetails(name, m1, m2, m3);
    }

   
    cout << "\nStudent Details and Total Marks:" << endl;
    for (int i = 0; i < n; ++i) {
        students[i].display();
    }

    
    delete[] students;

    return 0;
}
