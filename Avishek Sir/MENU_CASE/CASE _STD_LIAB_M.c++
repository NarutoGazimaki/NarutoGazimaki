/* liabrary management system*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Book {
public:
    int id;
    string title;
    string author;
    bool isAvailable;

    Book(int i, string t, string a, bool avail = true) : id(i), title(t), author(a), isAvailable(avail) {}

    void displayBook() const {
        cout << "ID: " << id << ", Title: " << title << ", Author: " << author
             << ", Status: " << (isAvailable ? "Available" : "Not Available") << endl;
    }
};


class LibraryManagementSystem {
private:
    vector<Book> books;

public:
  
    void addBook() {
        int id;
        string title, author;
        cout << "Enter Book ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Book Author: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "Book added successfully!" << endl;
    }

  
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "No books available in the library.\n";
            return;
        }
        cout << "\nLibrary Books:\n";
        for (const auto& book : books) {
            book.displayBook();
        }
    }


    void borrowBook() {
        int id;
        cout << "Enter the Book ID to borrow: ";
        cin >> id;

  
        auto it = find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.id == id;
        });

        if (it != books.end() && it->isAvailable) {
            it->isAvailable = false;
            cout << "You have borrowed: " << it->title << endl;
        } else {
            cout << "Book is either unavailable or doesn't exist.\n";
        }
    }

   
    void returnBook() {
        int id;
        cout << "Enter the Book ID to return: ";
        cin >> id;

       
        auto it = find_if(books.begin(), books.end(), [id](const Book& book) {
            return book.id == id;
        });

        if (it != books.end() && !it->isAvailable) {
            it->isAvailable = true;
            cout << "You have returned: " << it->title << endl;
        } else {
            cout << "Book is either not borrowed or doesn't exist.\n";
        }
    }


    void menu() {
        int choice;
        do {
            cout << "\nLibrary Management System Menu\n";
            cout << "1. Add Book\n";
            cout << "2. Display All Books\n";
            cout << "3. Borrow Book\n";
            cout << "4. Return Book\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addBook();
                    break;
                case 2:
                    displayAllBooks();
                    break;
                case 3:
                    borrowBook();
                    break;
                case 4:
                    returnBook();
                    break;
                case 5:
                    cout << "Exiting the system...\n";
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    LibraryManagementSystem lms;
    lms.menu();
    return 0;
}
