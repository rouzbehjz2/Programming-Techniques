//      Exercise 2.
//      Category: text processing problems and text encoding.
//      Re-encoding of a text based on a conversion table.
//      A file (source.txt) contains a text made up of an indefinite number of lines, each with a maximum
//      length of 200 characters. A second file (dictionary.txt) is organized as follows:
//      - in the first line there is a positive integer number S (≤ 30), which indicates the number of possible
//      re-encodings (i.e., string replacements) that are contained in the dictionary
//      - in the following S lines of the file, one per line, there is a <replaced> <original> pair,
//      representing a possible re-encoding: more specifically, <original> is the original sequence of
//      characters and <replaced> the corresponding replacement, in a $<integer>$ format.
//      The purpose of the program is to re-encode the first text file (source.txt), by replacing the original
//      sequences of characters with the corresponding replacements, based on the conversion table specified by
//      dictionary.txt. In case there is more than one replacement possible for a given sequence of
//      characters, the program should apply the first replacement that is found in the dictionary file. The result
//      of the re-encoding should be saved on a third file, output.txt.
//      Example
//
//      Content of the file source.txt:
//      apelle figlio di apollo
//      fece una palla di pelle di pollo
//      tutti i pesci vennero a galla
//      per vedere la palla di pelle di pollo
//      fatta da apelle figlio di apollo
//      Content of the file dictionary.txt:
//      9
//      $11$    pelle
//      $2$     pollo
//      $333$   palla
//      $41$    alla
//      $5078$  tta
//      $6$     tti
//      $7$     ll
//      $81$    er
//      $900$   ere
//
//      The file output.txt should be:
//      a$11$ figlio di a$2$
//      fece una $333$ di $11$ di $2$
//      tu$6$ i pesci venn$81$o a g$41$
//      p$81$ ved$81$e la $333$ di $11$ di $2$
//      fa$5078$ da a$11$ figlio di a$2$

#include <stdio.h>
#include <string.h>

typedef struct dictionary {
    char key[50];
    char value[50];
} dictionary;

void dict(char *, char *, char *);

int main() {
    FILE *my_file_source;
    FILE *my_file_dictionary;
    FILE *my_file_output;
    char letter;
    char final_word[100];

    if ((my_file_source = fopen("./source.txt", "r")) == NULL) {
        perror("ERROR READING FILE SOURCE");
        return 1;
    }
    if ((my_file_dictionary = fopen("./dictionary.txt", "r")) == NULL) {
        perror("ERROR READING FILE DICTIONARY");
        fclose(my_file_source);
        return 2;
    }
    if ((my_file_output = fopen("./output.txt", "w")) == NULL) {
        perror("ERROR OPENING FILE OUTPUT");
        fclose(my_file_source);
        fclose(my_file_dictionary);
        return 3;
    }

    int number;
    if (fscanf(my_file_dictionary, "%d", &number) != 1) {
        perror("ERROR READING DICTIONARY COUNT");
        fclose(my_file_source);
        fclose(my_file_dictionary);
        fclose(my_file_output);
        return 4;
    }

    dictionary array[number];
    char key[100];
    char value[100];
    int counter = 0;

    while (counter < number && fscanf(my_file_dictionary, "%s%s", key, value) == 2) {
        strcpy(array[counter].key, key);
        strcpy(array[counter].value, value);
        counter++;
    }

    while ((letter = fgetc(my_file_source)) != EOF) {
        int j = 0;
        while (letter != EOF && letter != '\n' && letter != ' ' && letter != '\'') {
            final_word[j++] = letter;
            letter = fgetc(my_file_source);
        }
        final_word[j] = '\0';

        for (int i = 0; i < counter; i++) {
            dict(final_word, array[i].key, array[i].value);
        }

        fputs(final_word, my_file_output);
        if (letter != EOF)
            fputc(letter, my_file_output);
    }

    fclose(my_file_source);
    fclose(my_file_dictionary);
    fclose(my_file_output);
    return 0;
}

void dict(char *word, char *key, char *value) {
    char final_word[100];
    char *ptr = strstr(word, value);
    if (ptr == NULL)
        return;
    int len = strlen(value);
    strncpy(final_word, word, ptr - word);
    final_word[ptr - word] = '\0';
    strcat(final_word, key);
    strcat(final_word, ptr + len);
    strcpy(word, final_word);
}
