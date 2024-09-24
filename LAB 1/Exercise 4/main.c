//      Exercise 4:
//      Compute the area of a circle or square based on user input
//      The user is requested to type a set of characters and numbers from the keyboard.
//      The first character should be Q for square or I for circle.
//      In case of a square, the user can decide whether the area should be computed given the value of the diagonal (D) or the side (S).
//      In case of a circle, the user can decide whether the area should be computed given the value of the diameter (D) or the radius (R).
//      All values inserted by the user should be integers, and the computed area should be a float.
//
//      For example, if the user types Q D10, the program should compute the area of a square with
//      diagonal equal to 10 and print the following on the screen:
//      The area of the square with diagonal 10 is 50.0
//
//      Suggestions:
//      a) Define a constant PI for the value 3.14 with #define. Remember: with #define there are
//      no ‘=’ and no ‘;’
//      b) Acquire the input of the user. Careful: you need to acquire single characters and numeric
//      values from keyboard...
//      c) Compute the value of the area (float) based on the acquired input.
//      d) Print the result on screen.
//      Remember:
//      Square: Area = S*S = D*D/2, Circle: Area = pi*R*R = pi*D*D/4

#include <stdio.h>

// Define a constant PI for the value 3.14
#define PI 3.14

// Function to compute the area of a square
float computeSquareArea(float side) {
    return side * side;
}

// Function to compute the area of a circle
float computeCircleArea(float radius) {
    return PI * radius * radius;
}

int main() {
    char shape;
    float length, area;

    // Prompt the user for input
    printf("Enter Q for square or I for circle: ");
    scanf(" %c", &shape); // Read a single character (Q or I)

    if (shape == 'Q' || shape == 'q') {
        char choice;
        printf("Enter D for diagonal or S for side: ");
        scanf(" %c", &choice); // Read a single character (D or S)

        if (choice == 'D' || choice == 'd') {
            printf("Enter the diagonal length: ");
            scanf("%f", &length);
            area = computeSquareArea(length * length / 2);
        } else if (choice == 'S' || choice == 's') {
            printf("Enter the side length: ");
            scanf("%f", &length);
            area = computeSquareArea(length);
        } else {
            printf("Invalid choice for square.\n");
            return 1;
        }
    } else if (shape == 'I' || shape == 'i') {
        char choice;
        printf("Enter D for diameter or R for radius: ");
        scanf(" %c", &choice); // Read a single character (D or R)

        if (choice == 'D' || choice == 'd') {
            printf("Enter the diameter: ");
            scanf("%f", &length);
            area = computeCircleArea(length * length / 4);
        } else if (choice == 'R' || choice == 'r') {
            printf("Enter the radius: ");
            scanf("%f", &length);
            area = computeCircleArea(length);
        } else {
            printf("Invalid choice for circle.\n");
            return 1;
        }
    } else {
        printf("Invalid shape choice.\n");
        return 1;
    }

    // Print the result
    printf("The area is %.2f\n", area);

    return 0;
}
