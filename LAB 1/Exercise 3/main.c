//      Exercise 3:
//      Using the IDE create a new project and create a text file by the name of “Bronte.txt” inside
//      the project folder. The content of the file may be the following:
//      Ho sognato nella mia vita,
//      sogni che son rimasti sempre con me,
//      e che hanno cambiato le mie idee;
//      son passati attraverso il tempo e attraverso di me,
//      come il vino attraverso l'acqua,
//      ed hanno alterato il colore della mia mente
//      Write/build the following program in C language. Check that there are no errors when you run
//      the program.
//

#include <stdio.h>
int main() {
    FILE *fp_read, *fp_write_odd, *fp_write_even;
    char file_string[100], name[20];
    int counter = 0;
    if ((fp_read = fopen("./Bronte.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    if ((fp_write_odd = fopen("../Output_odd.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }
    if ((fp_write_even = fopen("../Output_even.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 3;
    }
    printf("What's your name?");
    gets(name);
    while (!feof(fp_read)) {
        counter++;
        if (counter%2==0) {
            fscanf(fp_read, "%s", file_string);
            if (!feof(fp_read)) {
                printf("%s\nI am reading:\n%s\n\n", name, file_string);
                fprintf(fp_write_even, "%s", file_string);
            }
        }
        else {
            fgets(file_string, 100, fp_read);
            if (!feof(fp_read)) {
                puts(name);
                puts("I am reading:");
                puts(file_string);
                fputs(file_string, fp_write_odd);
            }
        }
    }
    fclose(fp_read);
    fclose(fp_write_even);
    fclose(fp_write_odd);
    return 0;
}

//  What happens when the counter is odd? What happens when the counter is even? Which is the
//  difference between fgets and fscanf?
//

/*
Behavior When the Counter Is Odd (Odd Line Numbers):
When the counter is odd, the program reads a line from the input file (“Bronte.txt”) using fgets().
The line is stored in the file_string buffer.
The program then prints the name entered by the user and displays the read line using puts().
Additionally, it writes the line to the “Output_odd.txt” file using fputs().

 Behavior When the Counter Is Even (Even Line Numbers):
When the counter is even, the program reads a word (sequence of non-whitespace characters) from the input file using fscanf() with the %s specifier.
The word is stored in the file_string buffer.
The program prints the name entered by the user and displays the read word using printf().
It also writes the word to the “Output_even.txt” file using fprintf().

Difference Between fgets() and fscanf():

fgets():
Reads an entire line (up to a newline character) from the input stream.
Includes leading whitespace (if any) and stores the newline character.
Suitable for reading entire lines of text.
Safer because it specifies the maximum number of characters to read.

fscanf() with %s:
Reads a sequence of non-whitespace characters (a word) until it encounters whitespace (space, tab, newline, etc.).
Skips leading whitespace.
Does not store the newline character.
Suitable for reading individual words.
Can potentially overrun the target buffer if not used carefully.
Remember to adjust the file paths (../Bronte.txt, ../Output_odd.txt, and ../Output_even.txt) based on the actual location of your input and output files.

*/
