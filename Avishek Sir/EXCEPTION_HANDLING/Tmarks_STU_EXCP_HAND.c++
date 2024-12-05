#include <iostream>
#include <stdexcept> // For exception handling
#include <limits>    // For std::numeric_limits
using namespace std;

class InvalidMarksException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid marks entered. Marks should be between 0 and 100.";
    }
};


class InvalidNumberOfSubjectsException : public exception {
public:
    const char* what() const noexcept override {
        return "Number of subjects should be greater than 0.";
    }
};


int calculateTotalMarks(int numSubjects) {
    int totalMarks = 0;
    int marks;

    for (int i = 0; i < numSubjects; ++i) {
        cout << "Enter marks for subject " << i + 1 << ": ";
        cin >> marks;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            throw InvalidMarksException();
        }

       
        if (marks < 0 || marks > 100) {
            throw InvalidMarksException();
        }

        totalMarks += marks;
    }

    return totalMarks;
}

int main() {
    int numSubjects;

    try {
  
        cout << "Enter the number of subjects: ";
        cin >> numSubjects;

      
        if (numSubjects <= 0) {
            throw InvalidNumberOfSubjectsException();
        }

       
        int total = calculateTotalMarks(numSubjects);

       
        cout << "Total Marks: " << total << endl;
    }
    catch (const InvalidMarksException& e) {
        
        cout << "Error: " << e.what() << endl;
    }
    catch (const InvalidNumberOfSubjectsException& e) {
      
        cout << "Error: " << e.what() << endl;
    }
    catch (const exception& e) {

        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}
