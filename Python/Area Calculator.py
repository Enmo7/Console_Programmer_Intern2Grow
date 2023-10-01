import math

print("Area Calculator")
print("1. Square")
print("2. Rectangle")
print("3. Circle")

choice = int(input("Enter your choice: "))

if choice == 1:
    side = float(input("Enter the side length of the square: "))
    area = side * side
    print("Area of the square:", area)
elif choice == 2:
    length = float(input("Enter the length of the rectangle: "))
    width = float(input("Enter the width of the rectangle: "))
    area = length * width
    print("Area of the rectangle:", area)
elif choice == 3:
    radius = float(input("Enter the radius of the circle: "))
    area = math.pi * radius ** 2
    print("Area of the circle:", area)
else:
    print("Invalid choice")