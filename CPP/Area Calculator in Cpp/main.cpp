#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int choice;
    cout << "Area Calculator\n";
    cout << "1. Square\n";
    cout << "2. Rectangle\n";
    cout << "3. Circle\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            double side;
            cout << "Enter the side length of the square: ";
            cin >> side;
            double area = side * side;
            cout << "Area of the square: " << area << endl;
            break;
        }
        case 2: {
            double length, width;
            cout << "Enter the length of the rectangle: ";
            cin >> length;
            cout << "Enter the width of the rectangle: ";
            cin >> width;
            double area = length * width;
            cout << "Area of the rectangle: " << area << endl;
            break;
        }
        case 3: {
            double radius;
            cout << "Enter the radius of the circle: ";
            cin >> radius;
            double area = M_PI * pow(radius, 2);
            cout << "Area of the circle: " << area << endl;
            break;
        }
        default:
            cout << "Invalid choice\n";
            break;
    }

    return 0;
}
