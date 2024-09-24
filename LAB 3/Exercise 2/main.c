//      Exercise 2.
//      Category: Verification problems with texts - Verification of expressions
//      Atext file expr.txt contains a mathematical expression in each line, consisting of positive integer numbers
//      (unsigned), arithmetic operators (+, -, *, / and %) and opened/closed round brackets.
//      Write a C program to verify the syntactic correctness of the expressions that are contained in the file,
//      according to the following rules:
//      1. Brackets need to be balanced: there should be an equal total number of opened and closed brackets,
//      and each closed bracket should correspond to a preceding opened bracket.
//      2. There cannot be spaces between numbers. On the other hand, spaces are admitted (and to be
//      neglected) if they are placed in any other position within the expression.
//      3. There should be a correct succession of operands and operators. Each operation should be a sequence
//      consisting of at least two operands, with operators (one of +, -, *, / and %) in between. An operand
//      could be either a number or another expression within round brackets.
//      In practice, to verify rule 3 you should verify the following:
//      • After an opened bracket there can only be an operand (in other words, there can only be either a
//      number or another opened bracket). There cannot be an operator.
//      • After an operand (in other words, after either a closed bracket or a number) there can only be
//      either another closed bracket (if rule 1 is verified), an operator, or the end of the expression.
//      • After an operator there has to be another operand (that is, either an opened bracket or a number)
//      Alternatively, to verify rule 3 you can verify the following:
//      • Before an operand (that is, before either an opened bracket or a number) there can only be an
//      opened bracket, an operator, or the beginning of the expression.
//      • Before a closed bracket there can only be an operand (that is, either another closed bracket or a
//      number).
//      • Before an operator there can only be an operand (either a closed bracket or a number).
//      The program should read the input file and verify the expressions one by one. Whenever the program
//      finds an error in an expression, it should print a message on the screen including the progressive line
//      number that identifies the expression. Then, the rest of the expression should be ignored, and the program
//      should pass to the following one.
//      Example:
//
//      Content of expr.txt Messages printed on the screen:
//      (3 + 2) / 7                                     Error in expression 2
//      ((3 - 7) 4)                                     Error in expression 3
//      (3 - 2) +                                       Error in expression 4
//      (8 * 9 1) * 4
//      ((4*(2+23)) / (7-3))



//      Suggestions: you may use a counter to keep track of the number of opened brackets, and use two char
//        variables to store the last two characters that were read













#include <stdio.h>
#include  <string.h>

#define MAX 100

int rule_1(char[]);
int rule_2(char[]);
int rule_3(char[]);



int main() {
    FILE*my_file;
    char LINE;
    char buffer[MAX];
    int scale=1;
    char letter;
    int i=0 , j=0;


    my_file=fopen("./expr.txt","r");

    if(my_file==NULL){
        printf("ERROR HANDLING");
        return 1;
    }
    while((letter = fgetc(my_file))!=EOF){
        if (letter!='\n'){
        buffer[i++]=letter ;
        }
        else if (letter=='\n'){
            buffer[i]='\0';
            if((rule_1(buffer))==1)
                printf("ERROR IN EXPRESSION %d\n",scale);
            else if((rule_2(buffer))==1)
                printf("ERROR IN EXPRESSION %d\n",scale);
            else if ((rule_3(buffer))==1)
                printf("ERROR IN EXPRESSION %d\n",scale);


            scale++;
            i=0;
            buffer[i]='\0';
        }




    }

    fclose(my_file);
    return 0;
}

int rule_1(char input[]){
    int i ;
    char open='(';
    char close=')';
    int scale=0;

    for(i=0;input[i]!='\0';i++){
        if (input[i]==open)
            scale++;
        else if (input[i]==close)
            scale--;
    }

    if (scale!=0)
        return 1;
    else
        return 0;
}
int rule_2(char input[]) {
    int i;
    int j = 0;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= '0' && input[i] <= '9') {
            if (input[i + 1] == ' ' && input[i + 2] <= '9' && input[i + 2] >= '0')
                return 1;
        }
    }

    return 0;

}

int rule_3(char input[]){
    int i=0;
    char open='(';
    char close=')';

    for(i=0;input[i]!='\0';i++){
        if(input[i]==close){
            if (input[i+1]==' '){
                i++;
                while(input[i+1]==' ')
                    i++;
            }
        //CRITERIA 1
        if (input[i+1]=='+' || input[i+1]=='-'  || input[i+1]=='%' || input[i+1]=='*' || input[i+1]=='/'){}

        else if(input[i+1]=='\0') {}

        else if (input[i+1]=='\n'){}

        else if (input[i+1]==close){}

        else
            return 1;
        }
        //CRITERIA 2
        else if (input[i]=='+' || input[i]=='-'  || input[i]=='%' || input[i]=='*' || input[i]=='/'){
            if (input[i+1]==' '){
                i++;
                while(input[i+1]==' ')
                    i++;
            }
            if(input[i+1]<='9' && input[i+1]>='0'){}

            else if(input[i+1]==open){}

            else
                return 1;
        }
        //CRITERIA 4
        else if (input[i]<='9' && input[i]>='0'){
            if (input[i+1]==' '){
                i++;
                while(input[i+1]==' ')
                    i++;
            }
            if (input[i+1]==open)
                return 1;


        }






    }

    return 0;
}
