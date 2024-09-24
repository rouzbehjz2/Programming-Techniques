// Exercise 1: Using the IDE create a new project and write/build the following program in C language.
// Check that there are no errors when you run the program.


#include <stdio.h>
int main(void)
{
    int x, y;
    float z;
    printf("Insert an integer number:");
    scanf("%d", &x);
    y = 3;
    z = (float)(x)/y;
    printf("%d/%d=%.3f\n", x, y, z);
    return 0;
}
 // Try executing the program with different input values from keyboard: 0, 9, 15, 20. Using the
 // debugger, check the content of the variables x, y e z.