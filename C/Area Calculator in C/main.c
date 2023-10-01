#include <stdio.h>
#include <math.h>

int main() {
    int choice;
    printf("Area Calculator\n");
    printf("1. Square\n");
    printf("2. Rectangle\n");
    printf("3. Circle\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            double side;
            printf("Enter the side length of the square: ");
            scanf("%lf", &side);
            double area = side * side;
            printf("Area of the square: %lf\n", area);
            break;
        }
        case 2: {
            double length, width;
            printf("Enter the length of the rectangle: ");
            scanf("%lf", &length);
            printf("Enter the width of the rectangle: ");
            scanf("%lf", &width);
            double area = length * width;
            printf("Area of the rectangle: %lf\n", area);
            break;
        }
        case 3: {
            double radius;
            printf("Enter the radius of the circle: ");
            scanf("%lf", &radius);
            double area = M_PI * pow(radius, 2);
            printf("Area of the circle: %lf\n", area);
            break;
        }
        default:
            printf("Invalid choice\n");
            break;
    }

    return 0;
}
