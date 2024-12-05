/*WRITE A MENU DRIVEN C++ PROGRAM TO IMPLEMENT ALL TYPES OF INHERITANCE BASED ON CHOICE OF USER*/


#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    void showName() {
        cout << "Animal Name: " << name << endl;
    }
};


class Dog : public Animal {
public:
    Dog(string n) : Animal(n) {}

    void bark() {
        cout << name << " says Woof!" << endl;
    }
};


class Engine {
public:
    void startEngine() {
        cout << "Engine started." << endl;
    }
};


class Vehicle {
protected:
    string model;

public:
    Vehicle(string m) : model(m) {}

    void showModel() {
        cout << "Vehicle Model: " << model << endl;
    }
};


class Car : public Vehicle, public Engine {
public:
    Car(string m) : Vehicle(m) {}

    void drive() {
        cout << "Car is driving." << endl;
    }
};


class Person {
protected:
    string name;

public:
    Person(string n) : name(n) {}

    void showPersonName() {
        cout << "Person Name: " << name << endl;
    }
};


class Employee : public Person {
protected:
    int employeeID;

public:
    Employee(string n, int id) : Person(n), employeeID(id) {}

    void showEmployeeID() {
        cout << "Employee ID: " << employeeID << endl;
    }
};


class Manager : public Employee {
private:
    string department;

public:
    Manager(string n, int id, string dept) : Employee(n, id), department(dept) {}

    void showDepartment() {
        cout << "Department: " << department << endl;
    }
};


class Shape {
public:
    virtual void draw() {
        cout << "Drawing Shape." << endl;
    }
};


class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing Circle." << endl;
    }
};


class Rectangle : public Shape {
public:
    void draw() override {
        cout << "Drawing Rectangle." << endl;
    }
};


class PersonInfo {
protected:
    string name;

public:
    PersonInfo(string n) : name(n) {}

    void showInfo() {
        cout << "Name: " << name << endl;
    }
};


class Student {
protected:
    int studentID;

public:
    Student(int id) : studentID(id) {}

    void showStudentID() {
        cout << "Student ID: " << studentID << endl;
    }
};


class Graduate : public PersonInfo, public Student {
private:
    string degree;

public:
    Graduate(string n, int id, string deg) : PersonInfo(n), Student(id), degree(deg) {}

    void showDegree() {
        cout << "Degree: " << degree << endl;
    }
};


void showMenu() {
    cout << "\nMenu:\n";
    cout << "1. Single Inheritance\n";
    cout << "2. Multiple Inheritance\n";
    cout << "3. Multilevel Inheritance\n";
    cout << "4. Hierarchical Inheritance\n";
    cout << "5. Hybrid Inheritance\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: { 
                string name;
                cout << "Enter the name of the dog: ";
                cin >> name;

                Dog d(name);
                d.showName(); 
                d.bark();    
                break;
            }

            case 2: { 
                string model;
                cout << "Enter the model of the car: ";
                cin >> model;

                Car car(model);
                car.startEngine(); 
                car.showModel();   
                car.drive();       
                break;
            }

            case 3: { 
                string name;
                int empID;
                string dept;

                cout << "Enter the name of the person: ";
                cin >> name;
                cout << "Enter employee ID: ";
                cin >> empID;
                cout << "Enter department: ";
                cin >> dept;

                Manager m(name, empID, dept);
                m.showPersonName(); 
                m.showEmployeeID(); 
                m.showDepartment(); 
                break;
            }

            case 4: { 
                int shapeChoice;
                cout << "Choose a shape to draw:\n";
                cout << "1. Circle\n";
                cout << "2. Rectangle\n";
                cout << "Enter your choice: ";
                cin >> shapeChoice;

                if (shapeChoice == 1) {
                    Circle c;
                    c.draw(); 
                } else if (shapeChoice == 2) {
                    Rectangle r;
                    r.draw(); 
                } else {
                    cout << "Invalid choice.\n";
                }
                break;
            }

            case 5: { 
                string name, degree;
                int studentID;

                cout << "Enter name: ";
                cin >> name;
                cout << "Enter student ID: ";
                cin >> studentID;
                cout << "Enter degree: ";
                cin >> degree;

                Graduate g(name, studentID, degree);
                g.showInfo();     
                g.showStudentID(); 
                g.showDegree();   
                break;
            }

            case 6:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
