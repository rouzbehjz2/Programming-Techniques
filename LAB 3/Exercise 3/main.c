//      Exercise 3.
//      Category: verification of numerical sequences
//      A text file (named numbers.txt, defined with #define) reports a sequence of integer numbers, with either
//      spaces or ‘\n’ as separators.
//      Write a C program to verify that each i-th value xi (with i ≥2) can obtained by the previous two values
//      (xi-2 and xi-1) by applying a single arithmetic operator. In other words, you should verify that each xi is
//      either the sum (xi-2 + xi-1), the difference (xi-2 - xi-1), the product (xi-2 * xi-1) or the division (xi-2 / xi-1) of
//      the previous two (NB careful to avoid divisions by 0!).
//      If a value does not verify the acceptance criteria, the program needs to discard it and pass to the next one.
//      The program should also identify the maximum and minimum values of the sequence, excluding the
//      non-valid data from the computation.
//      At the end of the verification, the program should print on the screen:
//      1. the final result of the verification. In case the sequence contained only valid values, the program
//      should print a corresponding message. Otherwise, it should print how many values have been
//      discarded.
//      2. the maximum and minimum values of the sequence, excluding the discarded values from the
//      computation.
//
//      Example:
//
//Content of numbers.txt Messages on the screen Comment
//12                               # of discarded values: 2              The program should discard the
//3                                Maximum value: 12                     following values:
//4                                Minimum value: -3                     • 0 (it cannot be obtained
//7 -3                                                                   by any operation on 7
//0                                                                      and -3)
//4                                                                      • 11 (it cannot be
//1                                                                      obtained by any
//3                                                                      operation on 3 and 9)
//3 9
//11








#include <stdio.h>
#define MAX 100

int operation(int,int,int);

int main(void ){
    FILE*my_file;
    int Number[MAX];
    int i=0;
    int j=0;
    int first,second,result;
    int max,min;
    int scale=0;

    my_file= fopen("./Numbers.txt","r");

    if (my_file==NULL){
        printf("FILE ERROR");
        return 1;
    }

    while((fscanf(my_file,"%d",&Number[i]))!=EOF)
        i++;

    for(j=0;j<i;j++){
        if (j==0){
            first=Number[j];
            max=Number[j];
            min=Number[j];
        }
        else if(j==1){
            second=Number[j];
            if(max<Number[j])
                max=Number[j];
            if(min>Number[j])
                min=Number[j];
        }
        else{
        result=Number[j];

        if((operation(first,second,result))==0){
            if(max<Number[j])
                max=Number[j];
            if(min>Number[j])
                min=Number[j];
            first=second;
            second=result;
        }
        else {

            scale++;
        }



        }

    }

    printf("# of discarded values: %d\n",scale);
    printf("Maximum value: %d\n",max);
    printf("Minimum value: %d",min);
    fclose(my_file);
    return 0;
}

int operation(int number1,int number2 , int result){

    if(number1 + number2 == result)
        return 0;

    else if (number1 - number2 ==result)
        return 0;

    else if (number1 * number2 ==result)
        return 0;

    else if (number2 != 0 && number1/number2 ==result)
        return 0;

    else
        return 1;




}
