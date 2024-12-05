/* WRITE A CASE STDY C++ PROGRAM TO IMPLEMENT STAFF MANAGEMENT SYSTEM*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class Staff {
private:
    int id;
    string name;
    string position;
    double salary;

public:

    Staff(int id, string name, string position, double salary) 
        : id(id), name(name), position(position), salary(salary) {}

 
    int getId() const { return id; }
    string getName() const { return name; }
    string getPosition() const { return position; }
    double getSalary() const { return salary; }


    void setName(string newName) { name = newName; }
    void setPosition(string newPosition) { position = newPosition; }
    void setSalary(double newSalary) { salary = newSalary; }

   
    void display() const {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Position: " << position << endl;
        cout << "Salary: " << salary << endl;
    }
};


class StaffManagementSystem {
private:
    vector<Staff> staffList; 

public:

    void addStaff(int id, string name, string position, double salary) {
        Staff newStaff(id, name, position, salary);
        staffList.push_back(newStaff);
        cout << "Staff added successfully!" << endl;
    }


    void displayAllStaff() const {
        if (staffList.empty()) {
            cout << "No staff records available!" << endl;
            return;
        }
        for (const auto& staff : staffList) {
            staff.display();
            cout << "-------------------" << endl;
        }
    }

  
    Staff* findStaffById(int id) {
        for (auto& staff : staffList) {
            if (staff.getId() == id) {
                return &staff;
            }
        }
        return nullptr; 
    }

  
    void updateStaff(int id) {
        Staff* staff = findStaffById(id);
        if (staff != nullptr) {
            string name, position;
            double salary;

            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new position: ";
            getline(cin, position);
            cout << "Enter new salary: ";
            cin >> salary;

            staff->setName(name);
            staff->setPosition(position);
            staff->setSalary(salary);

            cout << "Staff details updated successfully!" << endl;
        } else {
            cout << "Staff with ID " << id << " not found!" << endl;
        }
    }

   
    void deleteStaff(int id) {
        auto it = find_if(staffList.begin(), staffList.end(), [id](const Staff& staff) {
            return staff.getId() == id;
        });

        if (it != staffList.end()) {
            staffList.erase(it);
            cout << "Staff deleted successfully!" << endl;
        } else {
            cout << "Staff with ID " << id << " not found!" << endl;
        }
    }
};


int main() {
    StaffManagementSystem sms;
    int choice, id;
    string name, position;
    double salary;

    do {
        cout << "\nStaff Management System Menu:\n";
        cout << "1. Add Staff\n";
        cout << "2. Display All Staff\n";
        cout << "3. Update Staff\n";
        cout << "4. Delete Staff\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
         
            cout << "Enter Staff ID: ";
            cin >> id;
            cout << "Enter Staff Name: ";
            cin.ignore(); 
            getline(cin, name);
            cout << "Enter Staff Position: ";
            getline(cin, position);
            cout << "Enter Staff Salary: ";
            cin >> salary;
            sms.addStaff(id, name, position, salary);
            break;

        case 2:
   
            sms.displayAllStaff();
            break;

        case 3:
  
            cout << "Enter Staff ID to update: ";
            cin >> id;
            sms.updateStaff(id);
            break;

        case 4:
          
            cout << "Enter Staff ID to delete: ";
            cin >> id;
            sms.deleteStaff(id);
            break;

        case 5:
            cout << "Exiting the system. Goodbye!" << endl;
            break;

        default:
            cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 5);

    return 0;
}
