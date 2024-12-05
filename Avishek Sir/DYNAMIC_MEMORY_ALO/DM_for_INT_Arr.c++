/*DYNAMIC MEMORY ALLOCATION FOR INTEGER ARRAY*/
#include <iostream>
using namespace std;

int main() {
    int size;

    
    cout << "Enter the size of the array: ";
    cin >> size;

   
    int* arr = new int[size]; 

    
    cout << "Enter " << size << " integers: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i]; 
    }

   
    cout << "You entered: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " "; 
    }
    cout << endl;

   
    delete[] arr; 

    return 0;
}
