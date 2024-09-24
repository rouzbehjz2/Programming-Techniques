//      A text file contains only alphabetic characters, numeric characters, punctuation characters (. , ; : ! ? ’),
//      spaces and ‘\n’ characters.
//      Write a C program that generates a second file containing the same text of the input one, modified as
//      follows:
//      • Replace all the numerical characters with ‘*’.
//      • Add a space after each punctuation character (unless it is already followed by a space or a ‘\n’ or
//      another punctuation character).
//      • Make sure that the first alphabetic character after either a ‘.’, a ‘!’ or a ‘?’ character is uppercase
//      (even if there are spaces or ‘\n’ characters in between). If it is a lowercase character, transform it to
//      uppercase.
//      • Each line should be of 25 characters maximum, without considering the ‘\n’. If a line is longer than
//      25, it needs to be truncated after exactly 25 characters (it does not matter if this splits a word into
//      two).
//      • To align the text, add spaces at the end of each line that is shorter than 25 (as many they are needed
//      to reach the fixed 25 characters length)
//      • Each line should end with a printout of the number of characters of the corresponding line in the
//      original file, in the format: “ | c:%d \n” (see example below).
//      The names of the files are constant (“input.txt” and “output.txt”) defined with #define.
//Example:
//Content of input.txt Content of output.txt

//Caratterizzata da un passato turbolento, in                    Caratterizzata da un pass| c:25
//epoca medievale Rouen fu devastata piu' volte                  ato turbolento, in       | c:18
//da incendi ed epidemie e durante la Guerra                     epoca medievale Rouen fu | c:25
//dei Cent'Anni fu occupata dagli inglesi.                       devastata piu' volte     | c:20
//nel 1431 nella sua piazza centrale la giovane                  da incendi ed epidemie e | c:25
//Giovanna d'Arco (Jeanne d'Arc) fu processata                   durante la Guerra        | c:17
//per eresia e arsa sul rogo!durante la seconda                  dei Cent' Anni fu occupat| c:25
//guerra mondiale gli Alleati bombardarono                       a dagli inglesi.         | c:16
//ampie zone della citta', soprattutto il                        Nel **** nella sua piazza| c:25
//quartiere che si estende a sud della cattedrale.               centrale la giovane      | c:20
//                                                               Giovanna d' Arco ( Jeanne| c:25
//                                                               d' Arc) fu processata    | c:22
//                                                               per eresia e arsa sul rog| c:25
//                                                               o! Durante la seconda    | c:21
//                                                               guerra mondiale gli Allea| c:25
//                                                               ti bombardarono          | c:15
//                                                               ampie zone della citta', | c:25
//                                                               soprattutto il           | c:14
//                                                               quartiere che si estende | c:25
//                                                               a sud della cattedrale.  | c:23












#include <stdio.h>
#include "ctype.h"
#define FILE_INPUT "./input.txt"
#define FILE_OUTPUT "./text.txt"


int main() {
    FILE *fp_in, *fp_out;
    char ch, ch_prec;
    int counter, flag, flag1, count_read, myvar;

    if ((fp_in = fopen(FILE_INPUT, "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if ((fp_out = fopen(FILE_OUTPUT, "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }

    ch_prec = 'a';
    counter = 0;
    count_read = 0;
    flag1 = 0;
    while(!feof(fp_in)){
        flag = 0;
        ch = fgetc(fp_in);
        count_read++;
        if (!feof(fp_in)){
            if (flag1 == 1 && islower(ch)){
                // put comment
                fprintf(fp_out, "%c", toupper(ch));
                counter++;
                flag1 = 0;
            }
            else{
                if (ch=='\r'){
                    myvar=42;
                    count_read--;
                    counter--;
                    continue;
                }


                if (ispunct(ch_prec)){
                    if (!isspace(ch)){
                        fputc(' ', fp_out);
                        counter++;
                        count_read++;
                    }

                    if ((ch_prec == '.' || ch_prec == '!' || ch_prec == '?') && islower(ch)){
                        fputc(toupper(ch), fp_out);
                        counter++;
                        flag = 1;
                    }
                    if ((ch_prec == '.' || ch_prec == '!' || ch_prec == '?') && ch == '\n'){
                        flag1 = 1;
                    }
                }

                if (isdigit(ch)){
                    fprintf(fp_out, "*");
                    flag = 1;
                    counter++;
                }


                if (flag == 0 && ch != '\n'){
                    // put comment
                    fprintf(fp_out, "%c", ch);
                    counter++;
                }


                if (ch == '\n' && count_read < 25){
                    count_read--;
                    counter++;
                    for (;counter<25;counter++){
                        fprintf(fp_out," ");
                    }
                }
                if (counter==25){
                    fprintf(fp_out, "| c:%d\n", count_read);
                    counter = 0;
                    count_read = 0;
                }

                ch_prec = ch;
            }

        }
        else{
            if (count_read < 25){
                count_read--;
                for (;counter<25;counter++){
                    fprintf(fp_out," ");
                }
            }
            if (counter==25){
                fprintf(fp_out, "| c:%d\n", count_read);
                counter = 0;
                count_read = 0;
            }
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    return 0;
}
