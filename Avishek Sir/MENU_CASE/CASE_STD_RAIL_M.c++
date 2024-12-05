#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // for formatting output
using namespace std;


class Passenger {
private:
    string name;
    int age;
    string gender;
    int seatNumber;

public:
  
    Passenger(string name, int age, string gender, int seatNumber)
        : name(name), age(age), gender(gender), seatNumber(seatNumber) {}

  
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGender() const { return gender; }
    int getSeatNumber() const { return seatNumber; }

    
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "Seat Number: " << seatNumber << endl;
    }
};


class Train {
private:
    int trainNumber;
    string trainName;
    string source;
    string destination;
    int availableSeats;
    vector<Passenger> passengers;

public:
 
    Train(int trainNumber, string trainName, string source, string destination, int availableSeats)
        : trainNumber(trainNumber), trainName(trainName), source(source), destination(destination), availableSeats(availableSeats) {}

  
    int getTrainNumber() const { return trainNumber; }
    string getTrainName() const { return trainName; }
    string getSource() const { return source; }
    string getDestination() const { return destination; }
    int getAvailableSeats() const { return availableSeats; }


    void addPassenger(const Passenger& passenger) {
        if (availableSeats > 0) {
            passengers.push_back(passenger);
            availableSeats--; 
            cout << "Passenger added successfully!" << endl;
        } else {
            cout << "Sorry, no seats available!" << endl;
        }
    }


    void display() const {
        cout << "\nTrain Number: " << trainNumber << endl;
        cout << "Train Name: " << trainName << endl;
        cout << "Source: " << source << endl;
        cout << "Destination: " << destination << endl;
        cout << "Available Seats: " << availableSeats << endl;
        cout << "Passengers List:\n";
        for (const auto& passenger : passengers) {
            passenger.display();
            cout << "-------------------\n";
        }
    }

  
    bool hasAvailableSeats() const {
        return availableSeats > 0;
    }
};


class RailManagementSystem {
private:
    vector<Train> trains;

public:
    
    void addTrain(int trainNumber, string trainName, string source, string destination, int totalSeats) {
        Train newTrain(trainNumber, trainName, source, destination, totalSeats);
        trains.push_back(newTrain);
        cout << "Train added successfully!" << endl;
    }


    void displayAllTrains() const {
        if (trains.empty()) {
            cout << "No trains available in the system." << endl;
            return;
        }
        for (const auto& train : trains) {
            train.display();
            cout << "-------------------\n";
        }
    }


    void bookTicket(int trainNumber, string name, int age, string gender) {
        for (auto& train : trains) {
            if (train.getTrainNumber() == trainNumber) {
                if (train.hasAvailableSeats()) {
                    int seatNumber = train.getAvailableSeats();  
                    Passenger passenger(name, age, gender, seatNumber);
                    train.addPassenger(passenger);
                    return;
                } else {
                    cout << "No available seats in this train." << endl;
                    return;
                }
            }
        }
        cout << "Train with the given number not found!" << endl;
    }

    
    void displayTrainDetails(int trainNumber) const {
        for (const auto& train : trains) {
            if (train.getTrainNumber() == trainNumber) {
                train.display();
                return;
            }
        }
        cout << "Train with the given number not found!" << endl;
    }
};


int main() {
    RailManagementSystem rms;
    int choice, trainNumber, age, availableSeats;
    string name, gender, trainName, source, destination;

    do {
        cout << "\nRail Management System Menu:\n";
        cout << "1. Add Train\n";
        cout << "2. View All Trains\n";
        cout << "3. Add Passenger\n";
        cout << "4. Book Ticket\n";
        cout << "5. View Train Details\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
           
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cin.ignore(); 
                cout << "Enter Train Name: ";
                getline(cin, trainName);
                cout << "Enter Source Station: ";
                getline(cin, source);
                cout << "Enter Destination Station: ";
                getline(cin, destination);
                cout << "Enter Total Seats: ";
                cin >> availableSeats;
                rms.addTrain(trainNumber, trainName, source, destination, availableSeats);
                break;
            }

            case 2: {
         
                rms.displayAllTrains();
                break;
            }

            case 3: {
        
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cin.ignore();
                cout << "Enter Passenger Name: ";
                getline(cin, name);
                cout << "Enter Passenger Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter Gender (M/F): ";
                getline(cin, gender);
                rms.bookTicket(trainNumber, name, age, gender);
                break;
            }

            case 4: {
          
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                cin.ignore();
                cout << "Enter Passenger Name: ";
                getline(cin, name);
                cout << "Enter Passenger Age: ";
                cin >> age;
                cin.ignore();
                cout << "Enter Gender (M/F): ";
                getline(cin, gender);
                rms.bookTicket(trainNumber, name, age, gender);
                break;
            }

            case 5: {
      
                cout << "Enter Train Number: ";
                cin >> trainNumber;
                rms.displayTrainDetails(trainNumber);
                break;
            }

            case 6:
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 6);

    return 0;
}
