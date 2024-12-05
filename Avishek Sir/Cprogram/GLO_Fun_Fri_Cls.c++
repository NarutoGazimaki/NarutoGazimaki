/*GLOBAL FUNCTION AS A FRIEND TO A CLASS
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

   
    friend void globalfriendmethod(student &s);
};


void globalfriendmethod(student &s3) {
    
    cout << "\nRoll : " << s3.roll << " Marks: " << s3.marks << endl;
}

int main() {
   
    student s1(200, 2);

   
    globalfriendmethod(s1);

    cout << "\nSuccess" << endl;
    return 0;
}
