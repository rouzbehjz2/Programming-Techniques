//      Exercise 2.
//      Category: problems with ordered numerical sequences
//
//      Rotation of arrays
//
//      Write a function C capable of rotating the content of an array of n integers to the right or to the left by
//      a number of positions p. The array is to be understood as a circular array, in the sense that the element
//      to the right of the index cell N-1 is the one with index 0 and the element to the left of the index 0 is the
//      index N-1. The following figure illustrates a right rotation by 3 positions:
//
//                1  2  3  4  5  6  ===>   4  5  6  1  2  3
//
//      The function should have the following prototype:
//            void rotate(int v[maxN], int n, int p, int dir);
//
//      The main should:
//      1. acquire n from keyboard (n <= maxN with #define maxN 30)
//      2. acquire the values of the array v from keyboard
//      3. perform repeated rotations of the input array, where at each iteration the user decides the value of
//        p (p < n, p=0 to terminate the program) as well as the direction of the rotation (dir =-1 for right,
//        dir = 1 for left) and the resulting rotated array is printed on the screen.



#include <stdio.h>
#include <stdlib.h>

#define maxN 30

void rotate(int v[maxN], int n, int p, int dir) {
    int temp[maxN];

    if (dir == -1) { // Right rotation
        for (int i = 0; i < n; i++) {
            temp[(i + p) % n] = v[i];
            // [0] [1] [2] [3] [4]
        }
    } else{
        if (dir == 1) { // Left rotation
            for (int i = 0; i < n; i++) {
                temp[(i - p + n) % n] = v[i];
                // [0] [1] [2] [3] [4]
            }
        }
    }

    for (int i = 0; i < n; i++) {
        v[i] = temp[i];
    }
}

int main() {
    int n;
    printf("Enter the size of the array (n <= %d): ", maxN);
    scanf("%d", &n);

    if (n > maxN) {
        printf("Size exceeds maximum limit.\n");
        return 1;
    }

    int v[maxN];
    printf("Enter %d integers for the array:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    int p, dir;
    do {
        printf("Enter the number of positions to rotate (p < %d, enter 0 to terminate): ", n);
        scanf("%d", &p);

        if (p == 0) break;

        printf("Enter the direction of rotation (-1 for right, 1 for left): ");
        scanf("%d", &dir);

        rotate(v, n, p, dir);

        printf("Rotated array:\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", v[i]);
        }
        printf("\n");
    } while (1);

    return 0;
}
