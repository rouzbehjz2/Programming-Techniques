//      Exercise 5.
//      Write a “calculator” in C, that performs basic arithmetic operations (addition, subtraction,
//      division and multiplication) on two given inputs op1 and op2.
//
//      Write a C program that:
//      a) Acquires a character from keyboard using getchar (either ‘+’, ‘-‘, ‘*’ or ‘/’) to decide
//      which should be the arithmetic operation to perform;
//      b) Acquires two float operands (ex. 21.0 and 2.0) from keyboard, using scanf.
//      c) Prints the selected operator on the screen, followed by the result of the operation (for
//
//      example: / 10.50).
//      Careful: What happens if op2 is 0? How do you handle the problem?

#include <stdio.h>

int main() {
    char operator;
    float op1, op2, result;

    // Prompt the user for the operator
    printf("Enter an operator (+, -, *, or /): ");
    operator = getchar(); // Read a single character

    // Prompt the user for the operands
    printf("Enter two float operands (op1 op2): ");
    scanf("%f %f", &op1, &op2);

    // Perform the operation based on the operator
    switch (operator) {
        case '+':
            result = op1 + op2;
            printf("%.2f + %.2f = %.2f\n", op1, op2, result);
            break;
        case '-':
            result = op1 - op2;
            printf("%.2f - %.2f = %.2f\n", op1, op2, result);
            break;
        case '*':
            result = op1 * op2;
            printf("%.2f * %.2f = %.2f\n", op1, op2, result);
            break;
        case '/':
            if (op2 != 0) {
                result = op1 / op2;
                printf("%.2f / %.2f = %.2f\n", op1, op2, result);
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        default:
            printf("Invalid operator. Please use +, -, *, or /.\n");
            break;
    }

    return 0;
}

/*
         What happens if op2 is 0? How do you handle the problem?
         Division by zero is undefined in mathematics. Attempting to divide any number by zero results in an error.
         In the provided program, we check if op2 is zero before performing division:
         If op2 is not zero, we calculate the result normally.
         If op2 is zero, we display an error message: “Error: Division by zero is not allowed.”

         Here’s how the program handles the division by zero problem:

        case '/':
            if (op2 != 0) {
        result = op1 / op2;
        printf("%.2f / %.2f = %.2f\n", op1, op2, result);
        } else {
        printf("Error: Division by zero is not allowed.\n");
        }
        break;

        In summary, the program correctly identifies the division by zero scenario and provides an appropriate error message to the user.
        It ensures that the program does not crash or produce incorrect results when op2 is zero.

 */
