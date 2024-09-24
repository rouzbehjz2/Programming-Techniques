//      Exercise 6.
//      Starting from the code of Exercise 5, write a C program that reads a set of operations from
//      a text file, reported one per line. The program should create a second file, reporting in each
//      line the operator and the result of the corresponding operation in the input file. The result
//      should be written with two digits after the decimal point, as in the example below.
//
//
//

#include <stdio.h>

int main() {
    FILE *input_file;
    FILE *output_file;
    char operator;
    float num1,num2;


    if((input_file=fopen("./Operations.txt" ,"r"))==NULL){
        perror("ERROR HANDLING");
        return 1;
    }

    if((output_file=fopen("../Results.txt" ,"w"))==NULL){
        perror("ERROR HANDLING");
        return 1;
    }

    while((fscanf(input_file," %c %f %f\n",&operator,&num1,&num2))==3){
        if(operator=='+')
            fprintf(output_file,"%c %f\n",operator,num1+num2);
        else if(operator=='*')
            fprintf(output_file,"%c %f\n",operator,num1*num2);
        else if (operator=='-')
            fprintf(output_file,"%c %f\n",operator,num1-num2);
        else if (operator =='/')
            fprintf(output_file,"%c %f\n",operator,num1/num2);
    }


    fclose(input_file);
    fclose(output_file);

    return 0;
}
