//      Exercise 3.
//      Category: problems numerical matrixes
//      Iterations on matrixes
//      A text file contains an array of integers with the following format:
//      • the first line of the file specifies the dimensions of the matrix (number of rows nr and number of
//      columns nc), separated by spaces. Assume that both values are <= 20.
//      • each of the subsequent lines contains the nc values corresponding to a row of the matrix, with one or
//      more spaces as separators.
//      Write a C program that:
//      • reads this matrix from the input file (the name of the file, maximum 20 characters, is read from the
//      keyboard)
//      • repeatedly asks the user for a dim value between 1 and the minimum between nr and nc, and
//      prints all the square sub-matrixes of size dim that are contained in the input matrix
//      • prints the square sub-matrix, among those previously identified, that has the maximum sum of elements
//      • terminates the iterations if the user enters a value that is inconsistent with the size of the matrix
//      Example
//             If the content of the input file is the following:
//      3 4
//      1 2 3 4
//      5 6 7 8
//      9 0 1 1
//      and dim=2, the program should print on the screen:
//      The square sub-matrixes of dimension 2 are:
//      1 2
//      5 6

//      2 3
//      6 7

//      3 4
//      7 8

//      5 6
//      9 0

//      6 7
//      0 1

//      7 8
//      1 1

//      The submatrix with maximum sum of elements (22) is:

//      3 4
//      7 8




#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 20


void printSubMatrix(int matrix[MAX_SIZE][MAX_SIZE], int startRow, int startCol, int dim) {
    for (int i = 0; i < dim; i++) {
        for (int j = 0; j < dim; j++) {
            printf("%d ", matrix[startRow + i][startCol + j]);
        }
        printf("\n");
    }
}

int main() {
    int matrix[MAX_SIZE][MAX_SIZE];
    int nr, nc;
    int dim;

    FILE *file = fopen("mat.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &nr, &nc);

    for (int i = 0; i < nr; i++) {
        for (int j = 0; j < nc; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);

    int minDim;

    while (1) {
        if (nr < nc){
            minDim = nr;
        }else
            minDim = nc;
        //printf("Enter the dimension (1 to %d): ", nr < nc ? nr : nc);
        printf("Enter the dimension (1 to %d): ", minDim);

        scanf("%d", &dim);

        if (dim < 1 || dim > nr || dim > nc) {
            printf("Invalid dimension. Exiting.\n");
            break;
        }

        printf("The square sub-matrixes of dimension %d are:\n", dim);
        int maxSum = INT_MIN;
        int maxStartRow = 0;
        int maxStartCol = 0;

        for (int i = 0; i <= nr - dim; i++) {
            for (int j = 0; j <= nc - dim; j++) {
                int currentSum = 0;
                for (int k = 0; k < dim; k++) {
                    for (int l = 0; l < dim; l++) {
                        currentSum += matrix[i + k][j + l];
                    }
                }

                printSubMatrix(matrix, i, j, dim);
                printf("\n");

                if (currentSum > maxSum) {
                    maxSum = currentSum;
                    maxStartRow = i;
                    maxStartCol = j;
                }
            }
        }

        printf("The submatrix with maximum sum of elements (%d) is:\n", maxSum);
        printSubMatrix(matrix, maxStartRow, maxStartCol, dim);
        printf("\n");
    }

    return 0;
}
