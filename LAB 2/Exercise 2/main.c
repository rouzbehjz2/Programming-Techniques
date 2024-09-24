//      Exercise 2.
//      Skills: Formatted IO, manipulation of numbers
//      Category: numerical problems
//      Write a C program that prints on the screen the first N numbers of Fibonacci series (N should be
//      acquired from keyboard).
//      Suggestion: Fibonacci series is 0 1 1 2 3 5 8 … It can be developed by applying the following:
//      Xi = Xi-1 + Xi-2, where X0 = 0 and X1 = 1.
//      In-depth:
//      Modify the series as follows: Xi = Xi-1 * Xi-2, with X0 = 1 and X1 = 2
//      Try to determine experimentally (i.e., by analysing the results that you obtain with increasingly
//      larger number of elements of the series) how many elements can be represented without error if
//      you use int variables or if you use unsigned int variables, respectively.

#include <stdio.h>

int main(){
    int number;
    printf("please insert the number of the series you would like to print:\n(please write a reasonable and positive integer.)\n");
    scanf("%d",&number);
    int small=0;
    int big=1;
    int temp;


    if((number%1)!=0){
        printf("you should write a positive and non-zero integer ");
        return 1;}
    else if(number<=0){
        printf("you should write a positive and non-zero integer ");
        return 1;
    }
    if(number==1){
        printf("the fibonacci-sequence is 0 ");
        return 0;
    }
    if(number==2){
        printf("the fibonacci-sequence is 0 1 ");
        return 0;
    }

    printf("the fibonacci sequence is : 0 1 ");
    for(int i=0;i<number-2;i++){
        temp=big+small;
        printf("%d ",temp);
        small=big;
        big=temp;
    }

    return 0;
}