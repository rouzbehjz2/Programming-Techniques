//     Exercise 2:
//     Using the IDE create a new project and create a text file by the name of “Guide.txt” inside
//     the project folder. The content of the file may be the following:
//     "Quarantadue!" urlo' Loonquawl. "Questo e' tutto cio' che sai dire dopo un lavoro di sette
//     milioni e mezzo di anni?"
//     "Ho controllato molto approfonditamente," disse il computer, "e questa e' sicuramente la
//     risposta. Ad essere sinceri, penso che il problema sia che voi non abbiate mai saputo
//     veramente qual e' la domanda."
//     Write/build the following program in C language. Check that there are no errors when you run
//     the program
//     After building the program, try to run it and test the different cases.
//     In depth: What happens if you omit the line if (!feof(fp_read))? Why?


#include <stdio.h>

int main() {
    FILE *fp_read, *fp_write;
    char file_char, choice;

    if ((fp_read = fopen("./Guide.txt", "r")) == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    if ((fp_write = fopen("../Output.txt", "w")) == NULL) {
        printf("Error opening file\n");
        return 2;
    }

    printf("Print on console (C) or on file (F):");
    choice = getchar();

    while (!feof(fp_read)) {
        file_char = fgetc(fp_read);
        if (!feof(fp_read)) {
            switch (choice) {
                case 'C':
                    printf("\nChar printed on the console: %c", file_char);
                    break;
                case 'F':
                    fputc(file_char, fp_write);
                    printf("\nChar saved on file: ");
                    putchar(file_char);
                    break;
                default:
                    printf("Wrong choice\n");
                    return 3;
            }
        }
    }

    fclose(fp_read);
    fclose(fp_write);
    return 0;
}
/*   Explain the difference between inserting F and C :
In the provided code, when you insert 'F', the program reads characters from the file "Guide.txt" and writes them to the file "Output.txt". On the other hand, when you insert 'C', the program reads characters from "Guide.txt" and prints them on the console.
So, the difference lies in where the output is directed:
'F': Characters are saved to the file "Output.txt".
'C': Characters are printed on the console.
*/

/*
If you omit the line if (!feof(fp_read)), the program will behave incorrectly when reading characters from the file.

Here’s what would happen:
The loop would continue even after reaching the end of the file.
The last character read (which is EOF) would be processed incorrectly as a regular character.
The program might print “End of file reached” prematurely or not at all, leading to incorrect behavior.

 */
