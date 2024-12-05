/*CONTAINER METHOD IN C++*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
   
    vector<int> vec;

    vec.push_back(10); 
    vec.push_back(20);
    vec.push_back(30); 
    
   
    cout << "First element: " << vec[0] << endl; 
    cout << "Second element: " << vec.at(1) << endl; 


    cout << "Elements in vector: ";
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << " ";
    }
    cout << endl;

    
    vec.pop_back(); 

    cout << "After pop_back, size: " << vec.size() << endl;

   
    vec.insert(vec.begin() + 1, 15); 

   
    vec.erase(vec.begin() + 1); 

    
    if (vec.empty()) {
        cout << "Vector is empty" << endl;
    } else {
        cout << "Vector is not empty" << endl;
    }

  
    vec.clear();
    cout << "After clear, size: " << vec.size() << endl;

    return 0;
}
