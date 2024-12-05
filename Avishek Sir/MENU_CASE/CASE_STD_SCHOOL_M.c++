#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iomanip> 
using namespace std;


class Student {
private:
    int studentID;
    string name;
    int age;
    unordered_map<string, string> courses; 

public:
    Student(int id, string name, int age)
        : studentID(id), name(name), age(age) {}


    int getStudentID() const { return studentID; }
    string getName() const { return name; }
    int getAge() const { return age; }


    void enrollCourse(const string& courseName, const string& grade) {
        courses[courseName] = grade;
    }

   
    void display() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        if (courses.empty()) {
            cout << "No courses enrolled." << endl;
        } else {
            cout << "Courses and Grades:\n";
            for (const auto& course : courses) {
                cout << course.first << ": " << course.second << endl;
            }
        }
    }
};


class Teacher {
private:
    int teacherID;
    string name;
    string department;
    vector<string> courses;  

public:
    Teacher(int id, string name, string department)
        : teacherID(id), name(name), department(department) {}

    // Getter functions
    int getTeacherID() const { return teacherID; }
    string getName() const { return name; }
    string getDepartment() const { return department; }

    void addCourse(const string& courseName) {
        courses.push_back(courseName);
    }


    void display() const {
        cout << "Teacher ID: " << teacherID << endl;
        cout << "Name: " << name << endl;
        cout << "Department: " << department << endl;
        if (courses.empty()) {
            cout << "No courses taught." << endl;
        } else {
            cout << "Courses taught:\n";
            for (const auto& course : courses) {
                cout << course << endl;
            }
        }
    }
};


class SchoolManagementSystem {
private:
    vector<Student> students;
    vector<Teacher> teachers;
    unordered_map<string, vector<int>> courseEnrollments; 

public:
    
    void addStudent(int id, string name, int age) {
        Student newStudent(id, name, age);
        students.push_back(newStudent);
        cout << "Student added successfully!" << endl;
    }

 
    void addTeacher(int id, string name, string department) {
        Teacher newTeacher(id, name, department);
        teachers.push_back(newTeacher);
        cout << "Teacher added successfully!" << endl;
    }

   
    void enrollStudentInCourse(int studentID, const string& courseName) {
        for (auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.enrollCourse(courseName, "Not graded yet");
                courseEnrollments[courseName].push_back(studentID);
                cout << "Student enrolled in course: " << courseName << endl;
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found!" << endl;
    }

   
    void assignGradeToStudent(int studentID, const string& courseName, const string& grade) {
        for (auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.enrollCourse(courseName, grade);
                cout << "Grade " << grade << " assigned to student " << student.getName() << " for course " << courseName << endl;
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found!" << endl;
    }

  
    void viewStudentDetails(int studentID) const {
        for (const auto& student : students) {
            if (student.getStudentID() == studentID) {
                student.display();
                return;
            }
        }
        cout << "Student with ID " << studentID << " not found!" << endl;
    }

   
    void viewTeacherDetails(int teacherID) const {
        for (const auto& teacher : teachers) {
            if (teacher.getTeacherID() == teacherID) {
                teacher.display();
                return;
            }
        }
        cout << "Teacher with ID " << teacherID << " not found!" << endl;
    }

    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students in the system." << endl;
            return;
        }
        for (const auto& student : students) {
            student.display();
            cout << "----------------------\n";
        }
    }

  
    void displayAllTeachers() const {
        if (teachers.empty()) {
            cout << "No teachers in the system." << endl;
            return;
        }
        for (const auto& teacher : teachers) {
            teacher.display();
            cout << "----------------------\n";
        }
    }
};


int main() {
    SchoolManagementSystem sms;
    int choice, id, studentID, teacherID, age;
    string name, department, courseName, grade;

    do {
        cout << "\nSchool Management System Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Add Teacher\n";
        cout << "3. Enroll Student in Course\n";
        cout << "4. Assign Grade to Student\n";
        cout << "5. View Student Details\n";
        cout << "6. View Teacher Details\n";
        cout << "7. View All Students\n";
        cout << "8. View All Teachers\n";
        cout << "9. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
               
                cout << "Enter Student ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Student Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                sms.addStudent(id, name, age);
                break;
            }

            case 2: {
                
                cout << "Enter Teacher ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Teacher Name: ";
                getline(cin, name);
                cout << "Enter Department: ";
                getline(cin, department);
                sms.addTeacher(id, name, department);
                break;
            }

            case 3: {
               
                cout << "Enter Student ID: ";
                cin >> studentID;
                cin.ignore();
                cout << "Enter Course Name: ";
                getline(cin, courseName);
                sms.enrollStudentInCourse(studentID, courseName);
                break;
            }

            case 4: {
               
                cout << "Enter Student ID: ";
                cin >> studentID;
                cin.ignore();
                cout << "Enter Course Name: ";
                getline(cin, courseName);
                cout << "Enter Grade: ";
                getline(cin, grade);
                sms.assignGradeToStudent(studentID, courseName, grade);
                break;
            }

            case 5: {
           
                cout << "Enter Student ID: ";
                cin >> studentID;
                sms.viewStudentDetails(studentID);
                break;
            }

            case 6: {
               
                cout << "Enter Teacher ID: ";
                cin >> teacherID;
                sms.viewTeacherDetails(teacherID);
                break;
            }

            case 7: {
         
                sms.displayAllStudents();
                break;
            }

            case 8: {
                
                sms.displayAllTeachers();
                break;
            }

            case 9:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 9);

    return 0;
}
