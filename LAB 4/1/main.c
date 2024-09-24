//      Exercise 1.

//      Category: problems with numerical sequences
//      Numerical sequences in arrays
//      v is a mono-dimensional array of n integers (with n30). Write a C program that, after acquiring the
//      values of the array from keyboard, calls a function with the following prototype:
//      subSequences(int v[], int n);
//      The function should print on the screen all the sub-vectors of maximum size formed by contiguous elements, containing non-zero values.
//      Example
//      If v is [1 3 4 0 1 0 9 4 2 0], the two sub-vectors of maximum dimension (3) with non-zero
//      contiguous elements are [1 3 4] and [9 4 2].

//      Tips:
//      Note that the problem can be addressed by solving two sub-problems:
//      • identify sub-vectors of non-zero elements
//      - it is sufficient to "recognize" the beginning and the end of these sub-vectors
//      • select those with maximum length:
//      - a simple method consists in “trying” all the possible lengths in descending order, stopping at the
//      first length for which there exists a sub-vector
//      - a more efficient method is to first determine the maximum length, and then search for the corresponding sub-vectors
//      - alternatively, one could also try to do a single iteration on the main vector to recognize the sub-vectors, determine the maximum length and "remember" (using another vector) the beginnings
//      of the sub-vectors: but the complexity / efficiency would not change (you would still need a further
//      iteration to print the sub-vectors) and (probably) the program would be more complicated than
//      in the previous version.
//


#include <stdio.h>

int main() {
    // Define the array
    int first_array[10];
    int j=0;

    for(j;j<10;j++){
        printf("enter the %d member of the array : ",j+1);
        fscanf(stdin,"%d",&first_array[j]);
    }



    // Initialize variables to store the lengths of the two longest subsets
    int first_scale = 0;
    int second_scale = 0;

    // Initialize loop variables
    int i, counter = 0;
    int first_start_index = -1, second_start_index = -1;

    // Calculate the size of the array
    int size = sizeof(first_array) / sizeof(first_array[0]);

    // Iterate through the array
    for (i = 0; i < size; i++) {
        // If the current element is non-zero, increment the counter
        if (first_array[i] != 0)
            counter++;
        else {
            // If the current subset is longer than the longest, update both first_scale and second_scale
            if (first_scale < counter) {
                second_scale = first_scale;
                first_scale = counter;
                first_start_index = i - counter; // Update start index of first longest subset
            }
                // If the current subset is longer than the second longest, update second_scale only
            else if (second_scale < counter) {
                second_scale = counter;
                second_start_index = i - counter; // Update start index of second longest subset
            }
            // Reset the counter for the next subset
            counter = 0;
        }
    }

    // Check if the last subset extends to the end of the array and update scales accordingly
    if (first_scale < counter) {
        second_scale = first_scale;
        first_scale = counter;
        first_start_index = size - counter; // Update start index of first longest subset
    }
    else if (second_scale < counter) {
        second_scale = counter;
        second_start_index = size - counter; // Update start index of second longest subset
    }

    // Print the lengths of the two longest subsets
    printf("Lengths of the two longest subsets: %d %d\n", first_scale, second_scale);

    // Print the two longest subsets
    printf("First longest subset: ");
    for (i = first_start_index; i < first_start_index + first_scale; i++) {
        printf("%d ", first_array[i]);
    }
    printf("\n");

    printf("Second longest subset: ");
    for (i = second_start_index; i < second_start_index + second_scale; i++) {
        printf("%d ", first_array[i]);
    }
    printf("\n");

    return 0;
}
