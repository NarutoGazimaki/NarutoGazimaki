/*
write a menu driven program in c++ to perform LIFO algorithm using the concept of oop*/

#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;     
    int top;       
    int capacity;  

public:
  
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; 
    }

   
    ~Stack() {
        delete[] arr;
    }

   
    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

   
    void push(int value) {
        if (isFull()) {
            cout << "Stack overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

 
    void pop() {
        if (isEmpty()) {
            cout << "Stack underflow! Cannot pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

   
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is " << arr[top] << endl;
        }
    }


    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; --i) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }
};


void menu() {
    cout << "\n----- Stack Menu -----\n";
    cout << "1. Push element to stack\n";
    cout << "2. Pop element from stack\n";
    cout << "3. Peek top element\n";
    cout << "4. Display stack\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    int size, choice, value;

    cout << "Enter the size of the stack: ";
    cin >> size;


    Stack stack(size);

    while (true) {
        menu();
        cin >> choice;

        switch (choice) {
            case 1: 
                cout << "Enter the value to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3: 
                stack.peek();
                break;
            case 4: 
                stack.display();
                break;
            case 5: 
                cout << "Exiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
