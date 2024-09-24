//      Exercise 2.
//      Skills: iterative sorting algorithms, empirical complexity analysis
//              Evaluation of sorting algorithms
//              Consider the following sorting algorithms to sort vectors of integers in ascending order:
//      • Selection Sort
//      • Insertion Sort
//      • Shell Sort
//      Write a C program that acquires numerical sequences from a file (sort.txt) and calls all the
//      above-mentioned sorting algorithms on each sequence, printing the following output on the screen:
//      • the number of swaps
//      • the number of iterations of the outer loop
//      • per each iteration of the outer loop, the number of iterations of the inner loop
//      • the total number of iterations.
//      The file sort.txt has the following format:
//      • the first line reports the number S of numerical sequences that will follow
//      • in the following S lines, one per line:
//      <length> <sequence>
//              where <length> is a positive integer (at most 100) representing the length of the sequence
//      reported in the current line, and <sequence> is a sequence of <length> integer values
//              separated by a space.
//      Example of file sort.txt:
//      4
//      5 1 2 3 4 5
//      5 1 2 3 4 0
//      5 5 4 3 2 1
//      5 1 5 2 4 3




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void selectionsort(int [], int);
void insertionsort(int [], int);
void shellsort(int [], int);

int main() {
    FILE *my_file;
    if ((my_file = fopen("./sort.txt", "r")) == NULL) {
        printf("ERROR READING FILE");
        return 1;
    }

    int ROW;
    fscanf(my_file, "%d", &ROW);

    for (int i = 0; i < ROW; i++) {
        int length;
        fscanf(my_file, "%d", &length);

        int array[length];
        for (int j = 0; j < length; j++) {
            fscanf(my_file, "%d", &array[j]);
        }

        printf("Selection sort information for the %d array is :\n", i + 1);
        int temp_array[length];
        memcpy(temp_array, array, sizeof(array));
        selectionsort(temp_array, length);
        printf("\n");

        printf("Insertion sort information for the %d array is :\n", i + 1);
        memcpy(temp_array, array, sizeof(array));
        insertionsort(temp_array, length);
        printf("\n");

        printf("Shell sort information for the %d array is :\n", i + 1);
        memcpy(temp_array, array, sizeof(array));
        shellsort(temp_array, length);
        printf("\n");
    }

    fclose(my_file);
    return 0;
}

void selectionsort(int array[], int N) {
    int swap = 0;
    int out_iteration = 0;
    int inner_iteration = 0;
    int total_iteration = 0;

    for (int i = 0; i < N - 1; i++) {
        int min = i;
        out_iteration++;
        inner_iteration = 0;
        for (int j = i + 1; j < N; j++) {
            inner_iteration++;
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (min != i) {
            swap++;
            int temp = array[i];
            array[i] = array[min];
            array[min] = temp;
        }
        printf("For the %d outer iteration, the number of inner iterations is %d \n", out_iteration, inner_iteration);
        total_iteration += inner_iteration;
    }
    printf("The number of outer iterations is %d\n", out_iteration);
    printf("The number of total iterations is %d\n", total_iteration);
    printf("The number of total swaps is %d\n", swap);
}

void insertionsort(int array[], int N) {
    int swap = 0;
    int out_iteration = 0;
    int inner_iteration = 0;
    int total_iteration = 0;

    for (int i = 1; i < N; i++) {
        int key = array[i];
        int j = i - 1;
        out_iteration++;
        inner_iteration = 0;

        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
            inner_iteration++;
            swap++;
        }
        array[j + 1] = key;

        printf("For the %d outer iteration, the number of inner iterations is %d \n", out_iteration, inner_iteration);
        total_iteration += inner_iteration;
    }
    printf("The number of outer iterations is %d\n", out_iteration);
    printf("The number of total iterations is %d\n", total_iteration);
    printf("The number of total swaps is %d\n", swap);
}

void shellsort(int array[], int N) {
    int swap = 0;
    int out_iteration = 0;
    int inner_iteration = 0;
    int total_iteration = 0;

    for (int gap = N / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < N; i++) {
            int temp = array[i];
            int j;
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
                inner_iteration++;
                swap++;
            }
            array[j] = temp;
            out_iteration++;
            printf("For the %d outer iteration with gap %d, the number of inner iterations is %d \n", out_iteration, gap, inner_iteration);
            total_iteration += inner_iteration;
            inner_iteration = 0;
        }
    }
    printf("The number of outer iterations is %d\n", out_iteration);
    printf("The number of total iterations is %d\n", total_iteration);
    printf("The number of total swaps is %d\n", swap);
}
