/*WRITE A CASE STDY C++ PROGRAM TO IMPLEMENT HOSPITAL MANAGEMENT SYSTEM*/
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  
using namespace std;


class Patient {
private:
    int patientID;
    string name;
    int age;
    string gender;
    string ailment;
    string doctorAssigned;

public:
  
    Patient(int id, string name, int age, string gender, string ailment, string doctorAssigned)
        : patientID(id), name(name), age(age), gender(gender), ailment(ailment), doctorAssigned(doctorAssigned) {}


    int getPatientID() const { return patientID; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    string getAilment() const { return ailment; }
    string getDoctorAssigned() const { return doctorAssigned; }

   
    void display() const {
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Ailment: " << ailment << endl;
        cout << "Assigned Doctor: " << doctorAssigned << endl;
    }
};


class Doctor {
private:
    int doctorID;
    string name;
    string specialization;
    string contact;

public:

    Doctor(int id, string name, string specialization, string contact)
        : doctorID(id), name(name), specialization(specialization), contact(contact) {}

    // Getter functions
    int getDoctorID() const { return doctorID; }
    string getName() const { return name; }
    string getSpecialization() const { return specialization; }
    string getContact() const { return contact; }

  
    void display() const {
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Name: " << name << endl;
        cout << "Specialization: " << specialization << endl;
        cout << "Contact: " << contact << endl;
    }
};


class HospitalManagementSystem {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;

public:

    void addPatient(int id, string name, int age, string gender, string ailment, string doctorAssigned) {
        Patient newPatient(id, name, age, gender, ailment, doctorAssigned);
        patients.push_back(newPatient);
        cout << "Patient added successfully!" << endl;
    }


    void addDoctor(int id, string name, string specialization, string contact) {
        Doctor newDoctor(id, name, specialization, contact);
        doctors.push_back(newDoctor);
        cout << "Doctor added successfully!" << endl;
    }

   
    void scheduleAppointment(int patientID, int doctorID) {
       
        Patient* patient = nullptr;
        for (auto& p : patients) {
            if (p.getPatientID() == patientID) {
                patient = &p;
                break;
            }
        }

      
        Doctor* doctor = nullptr;
        for (auto& d : doctors) {
            if (d.getDoctorID() == doctorID) {
                doctor = &d;
                break;
            }
        }

        if (patient && doctor) {
          
            patient->display();
            cout << "Appointment scheduled with Dr. " << doctor->getName() << endl;
        } else {
            cout << "Invalid patient or doctor ID." << endl;
        }
    }


    void displayAllPatients() const {
        if (patients.empty()) {
            cout << "No patients in the system." << endl;
            return;
        }
        for (const auto& p : patients) {
            p.display();
            cout << "----------------------\n";
        }
    }

  
    void displayAllDoctors() const {
        if (doctors.empty()) {
            cout << "No doctors in the system." << endl;
            return;
        }
        for (const auto& d : doctors) {
            d.display();
            cout << "----------------------\n";
        }
    }

   
    void viewPatientDetails(int patientID) const {
        for (const auto& p : patients) {
            if (p.getPatientID() == patientID) {
                p.display();
                return;
            }
        }
        cout << "Patient with ID " << patientID << " not found!" << endl;
    }


    void viewDoctorDetails(int doctorID) const {
        for (const auto& d : doctors) {
            if (d.getDoctorID() == doctorID) {
                d.display();
                return;
            }
        }
        cout << "Doctor with ID " << doctorID << " not found!" << endl;
    }
};


int main() {
    HospitalManagementSystem hms;
    int choice, id, patientID, doctorID, age;
    string name, gender, ailment, doctorAssigned, specialization, contact;

    do {
        cout << "\nHospital Management System Menu:\n";
        cout << "1. Add New Patient\n";
        cout << "2. Add New Doctor\n";
        cout << "3. Schedule Appointment\n";
        cout << "4. View All Patients\n";
        cout << "5. View All Doctors\n";
        cout << "6. View Patient Details\n";
        cout << "7. View Doctor Details\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
             
                cout << "Enter Patient ID: ";
                cin >> id;
                cin.ignore();  
                cout << "Enter Patient Name: ";
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter Gender (M/F): ";
                getline(cin, gender);
                cout << "Enter Ailment: ";
                getline(cin, ailment);
                cout << "Enter Doctor Assigned: ";
                getline(cin, doctorAssigned);
                hms.addPatient(id, name, age, gender, ailment, doctorAssigned);
                break;
            }

            case 2: {
             
                cout << "Enter Doctor ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Doctor Name: ";
                getline(cin, name);
                cout << "Enter Specialization: ";
                getline(cin, specialization);
                cout << "Enter Contact: ";
                getline(cin, contact);
                hms.addDoctor(id, name, specialization, contact);
                break;
            }

            case 3: {
               
                cout << "Enter Patient ID: ";
                cin >> patientID;
                cout << "Enter Doctor ID: ";
                cin >> doctorID;
                hms.scheduleAppointment(patientID, doctorID);
                break;
            }

            case 4: {
             
                hms.displayAllPatients();
                break;
            }

            case 5: {
             
                hms.displayAllDoctors();
                break;
            }

            case 6: {
              
                cout << "Enter Patient ID: ";
                cin >> patientID;
                hms.viewPatientDetails(patientID);
                break;
            }

            case 7: {
            
                cout << "Enter Doctor ID: ";
                cin >> doctorID;
                hms.viewDoctorDetails(doctorID);
                break;
            }

            case 8:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
