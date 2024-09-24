//      Exercise 4.
//      Skills: IO on files, manipulation of characters.
//      Category: encoding problems with texts/characters
//              A file contains a text with unknown number of characters. The aim of the program is to create a
//              second file where the characters of the original file are re-encoded as follows.
//      Numeric characters:
//      •Numeric characters (‘0’..’9’) should be re-encoded into the numeric character that is k
//      positions later in the ASCII table, with k starting from 0 and incremented by 1 each time
//      a new numeric character is re-encoded. (NB: it is a 10 MODULE: the count starts again
//      from 0 after 9).
//      For example, if the file starts as follows: “Number 248 is even”:
//      - ‘2’ (k starts from 0) should be re-encoded as ‘2’+0 = ‘2’ (k becomes 1)
//      - ‘4’ should become ‘4’+1 = ‘5’ (k becomes 2)
//      - ‘8’ should become ‘8’+2 = ‘0’ (after ‘9’ we start again from ‘0’).
//      Alphabetic characters:
//      • If the alphabetic character is preceded by a non-alphabetic character, it should remain
//      unchanged
//      • If it is preceded by another alphabetic character (c0), the code should be incremented by
//       h positions within the set of alphabetic characters (with h = c0-‘A’if c0 is uppercase, h=c0-
//      ‘a’ if c0 is lowercase). The h increment should be a 26 MODULE (that is, after reaching
//      the code of ‘z’ or ‘Z’ (respectively in case of lowercase or uppercase characters) we start
//      again from ‘a’ or ‘A’.
//      The encoding result should be stored in a second file (the names of the input and output files are
//      acquired from keyboard).







#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int encode(FILE *fin, FILE *fout);
int decode(FILE *fin, FILE *fout);

int main() {
    FILE *fp_in, *fp_out;
    int num_car;
    char choice, file_in[50], file_out[50];

    printf("encode (C) or decode (D):");
    scanf("%c", &choice);

    switch (choice) {
        case 'C':
            printf("Input file name for encoding:");
            scanf("%s", &file_in);

            printf("Output file name for encoding:");
            scanf("%s", &file_out);

            if ((fp_in = fopen(file_in, "r")) == NULL) {
                printf("Error opening file\n");
                return 1;
            }
            if ((fp_out = fopen(file_out, "w")) == NULL) {
                printf("Error opening file\n");
                return 3;
            }
            num_car = encode(fp_in, fp_out);
            fclose(fp_in);
            fclose(fp_out);
            break;
        case 'D':
            printf("Input file name for decode:");
            scanf("%s", &file_in);

            printf("Output file name for decode:");
            scanf("%s", &file_out);

            if ((fp_in = fopen(file_in, "r")) == NULL) {
                printf("Error opening file\n");
                return 2;
            }
            if ((fp_out = fopen(file_out, "w")) == NULL) {
                printf("Error opening file\n");
                return 4;
            }
            num_car = decode(fp_in, fp_out);
            fclose(fp_in);
            fclose(fp_out);
            break;
        default:
            printf("Wrong choice\n");
            return 2;
    }

    if(num_car == 0){
        printf("Error");
    }
    else {
        printf("Characters printed: %d", num_car);
    }

    return 0;
}

int encode(FILE *fin, FILE *fout){
    char ch, ch_prec;
    int num, flag, ch_cod;
    int counter=0, num_car=0;

    ch_prec = '\n';

    while(!feof(fin)){
        ch = fgetc(fin);
        flag = 0;
        if (!feof(fin)){
            if(isdigit(ch)){
                num = (int)(ch) + counter;
                counter++;
                while(num > 9){
                    num = num - 10;
                }
                fputc(num, fout);
                num_car++;
                ch_prec = ch;
            }
            else if(isalpha(ch)) {
                if(isalpha(ch_prec)) {
                    if(islower(ch_prec)){
                        ch_cod = ch + ch_prec - 'a';
                    }
                    else {
                        ch_cod = ch + ch_prec - 'A';
                    }
                    if (islower(ch) && ch_cod > 122){
                        flag = 1;
                    }
                    else if (isupper(ch) && ch_cod > 90){
                        flag = 1;
                    }
                    if(flag){
                        ch_cod = ch_cod - 26;
                    }
                    fprintf(fout,"%c", ch_cod);
                    num_car++;
                    ch_prec = ch_cod;
                }
                else {
                    fputc(ch, fout);
                    num_car++;
                    ch_prec = ch;
                }
            }
            else {
                fputc(ch, fout);
                num_car++;
                ch_prec = ch;
            }
        }
    }
    return num_car;
}

int decode(FILE *fin, FILE *fout){
    char ch, ch_prec;
    int num, flag, ch_cod;
    int counter=0, num_car=0;

    ch_prec = '\n';

    while(!feof(fin)){
        ch = fgetc(fin);
        flag = 0;
        if (!feof(fin)){
            if(isdigit(ch)){
                num = (int)(ch) - counter;
                counter++;
                while(num < 0){
                    num = num + 10;
                }
                fputc(num, fout);
                num_car++;
                ch_prec = ch;
            }
            else if(isalpha(ch)) {
                if(isalpha(ch_prec)) {
                    if(islower(ch_prec)){
                        ch_cod = ch - ch_prec + 'a';
                    }
                    else {
                        ch_cod = ch - ch_prec + 'A';
                    }
                    if (islower(ch) && ch_cod < 97){
                        flag = 1;
                    }
                    else if (isupper(ch) && ch_cod > 65){
                        flag = 1;
                    }
                    if(flag){
                        ch_cod = ch_cod + 26;
                    }
                    fprintf(fout,"%c", ch_cod);
                    num_car++;
                    ch_prec = ch;
                }
                else {
                    fputc(ch, fout);
                    num_car++;
                    ch_prec = ch;
                }
            }
            else {
                fputc(ch, fout);
                num_car++;
                ch_prec = ch;
            }
        }
    }
    return num_car;
}