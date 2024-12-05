/*BOTH TYPES OF POLIMORPHISM*/

#include <iostream>
#include <cmath>
#include <memory> // For smart pointers
using namespace std;


class Shape {
public:
    virtual double area() const = 0;     
    virtual double perimeter() const = 0; 
    virtual ~Shape() {}                  
};


class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double area() const override {
        return width * height;
    }

    double perimeter() const override {
        return 2 * (width + height);
    }
};


class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return 3.14159 * radius * radius;
    }

    double perimeter() const override {
        return 2 * 3.14159 * radius;
    }
};


class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}

    double area() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c)); 
    }

    double perimeter() const override {
        return a + b + c;
    }
};


class Calculator {
public:
  
    double area(double length, double width) const {
        return length * width;
    }

  
    double area(double radius) const {
        return 3.14159 * radius * radius;
    }

    double area(double a, double b, double c) const {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c)); 
    }
};

void showMainMenu() {
    cout << "\nMain Menu:\n";
    cout << "1. Use Runtime Polymorphism\n";
    cout << "2. Use Compile-time Polymorphism\n";
    cout << "3. Exit\n";
    cout << "Enter your choice: ";
}


void showShapeMenu() {
    cout << "\nSelect Shape:\n";
    cout << "1. Rectangle\n";
    cout << "2. Circle\n";
    cout << "3. Triangle\n";
    cout << "Enter your choice: ";
}


unique_ptr<Shape> createShape(int choice) {
    double x, y, z;
    switch(choice) {
        case 1: // Rectangle
            cout << "Enter width and height of rectangle: ";
            cin >> x >> y;
            return make_unique<Rectangle>(x, y);
        case 2: // Circle
            cout << "Enter radius of circle: ";
            cin >> x;
            return make_unique<Circle>(x);
        case 3: // Triangle
            cout << "Enter sides of triangle (a, b, c): ";
            cin >> x >> y >> z;
            return make_unique<Triangle>(x, y, z);
        default:
            cout << "Invalid choice.\n";
            return nullptr;
    }
}


void calculateCompileTimeArea(Calculator& calc) {
    int shapeChoice;
    cout << "Choose shape for compile-time polymorphism:\n";
    cout << "1. Rectangle\n";
    cout << "2. Circle\n";
    cout << "3. Triangle\n";
    cout << "Enter your choice: ";
    cin >> shapeChoice;

    if (shapeChoice == 1) {
        double length, width;
        cout << "Enter length and width of rectangle: ";
        cin >> length >> width;
        cout << "Area of Rectangle (Compile-time polymorphism): " << calc.area(length, width) << endl;
    }
    else if (shapeChoice == 2) {
        double radius;
        cout << "Enter radius of circle: ";
        cin >> radius;
        cout << "Area of Circle (Compile-time polymorphism): " << calc.area(radius) << endl;
    }
    else if (shapeChoice == 3) {
        double a, b, c;
        cout << "Enter sides of triangle: ";
        cin >> a >> b >> c;
        cout << "Area of Triangle (Compile-time polymorphism): " << calc.area(a, b, c) << endl;
    } else {
        cout << "Invalid shape choice.\n";
    }
}

int main() {
    int mainChoice;
    Calculator calc; 

    do {
        showMainMenu(); 
        cin >> mainChoice;

        switch(mainChoice) {
            case 1: {
               
                int shapeChoice;
                showShapeMenu();
                cin >> shapeChoice;

                auto shape = createShape(shapeChoice);
                if (shape) {
                    cout << "Area: " << shape->area() << endl;
                    cout << "Perimeter: " << shape->perimeter() << endl;
                }
                break;
            }

            case 2: {
               
                calculateCompileTimeArea(calc);
                break;
            }

            case 3:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (mainChoice != 3);

    return 0;
}
