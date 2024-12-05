/*
FRIEND CLASS OR ANOTHER CLASS 
*/
#include<iostream>
using namespace std;

class student {
private:
    int marks; 
protected:
    int roll; 
public:
   
    student() {}

   
    student(int m, int r) {
        this->marks = m;
        this->roll = r;
    }

   
    friend class classmate;
};

class classmate {
public:
   
    void showdata(student &s3) {
        cout << "\nRoll : " << s3.roll << " Marks: " << s3.marks << endl;
    }
};

int main() {
   
    student s1(100, 1);

   
    classmate s2;

   
    s2.showdata(s1);

    cout << "\nSuccess" << endl;
    return 0;
}
