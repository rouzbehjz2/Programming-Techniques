//      Exercise 1.
//      Skills: Formatted IO, manipulation of numbers
//      Category: numerical problems, problems of numerical encoding
//      Write a C program that, after acquiring 2 positive integer numbers A and B from keyboard,
//      computes the greatest common factor (GCF) of A and B by applying the Euler’s method.
//      Euler methods (remainders method): the method repeatedly applies divisions of the greater number
//      by the smaller one, replacing at each step the greater value with the smaller and
//      the smaller with the remainder of the division, respectively. The iterations end
//      when the remainder is 0.
//      Example: A = 34, B = 18
//      iteration 1: 34 % 18 = 16
//      iteration 2: 18 % 16 = 2
//      iteration 3: 16 % 2 = 0  stop!
//      Result: GCF = 2

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int A, B, min, max;
    int mod;

    while(1){

    printf("Please Enter the first and second number: \n");
    scanf(" %d %d", &A, &B);
    if( A <= 0 || B <= 0)
        printf("Please Enter a positive number. \n");
    else
        break;
    }


    if (A > B){
        min = B;
        max = A;
    }else{
        min = A;
        max = B;
        }


    do{
        mod = max % min;
        max = min;
        min = mod;
    }while(mod != 0);

    printf("The GCF is equal to %d ", max);
    return 0;
}
