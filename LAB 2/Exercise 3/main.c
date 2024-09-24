//      Exercise 3
//      Skills: IO on files, manipulation of characters
//      Category: encoding problems with texts/characters
//      A text file (for example: source.txt) contains a text with unknown number of lines. Assume
//      that the file DOES NOT contain the character ‘$’.
//      The aim of the program is to compress the file, by replacing any sequence of repeated characters
//      (with a minimum of 2 and a maximum of 9 repetitions) with the following triplet of characters:
//      <repeated character>$<number of repetitions>.
//      NB: the number of repetitions should not consider the first occurrence of the character: for
//      example, AA contains 1 repetition, BBB contains 2 repetitions, etc. In case a character is repeated
//      more than 9 times, the sequence should be broken into multiple sub-sequences. For example:
//      “AAAAAAAAAAAAA” should be encoded as “A$9A$2”
//      “the number 1000000 is large” should be encoded as “the number 10$5 is large”
//      “there are 15 repeated = : =============== and 4 dots….” should be encoded as “there
//      are 15 repeated = : =$9=$4 and 4 dots.$3”
//      The compressed text should be stored in a second file (for example: compressed.txt).




#include <stdio.h>

int compress(FILE *fin, FILE *fout);
int decompress(FILE *fin, FILE *fout);

int main() {
    FILE *fp_read, *fp_dec, *fp_com;
    int num_car;
    char choice;

    printf("Compression (C) or Decompression (D):");
    scanf("%c", &choice);

    switch (choice) {
        case 'C':
            if ((fp_read = fopen("source.txt", "r")) == NULL) {
                printf("Error opening file\n");
                return 1;
            }
            if ((fp_com = fopen("compressed.txt", "w")) == NULL) {
                printf("Error opening file\n");
                return 3;
            }
            num_car = compress(fp_read, fp_com);
            fclose(fp_read);
            fclose(fp_com);
            break;
        case 'D':
            if ((fp_dec = fopen("decompressed.txt", "w")) == NULL) {
                printf("Error opening file\n");
                return 2;
            }
            if ((fp_com = fopen("compressed.txt", "r")) == NULL) {
                printf("Error opening file\n");
                return 4;
            }
            num_car = decompress(fp_com, fp_dec);
            fclose(fp_dec);
            fclose(fp_com);
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

int compress(FILE *fin, FILE *fout){
    char ch, ch1;
    int counter=0, num_car=0;
    int i=0;

    ch = fgetc(fin);
    while (!feof(fin)) {
        ch1 = fgetc(fin);
        if (ch==ch1 && counter < 9){
            counter++;
        }
        else {
            if (counter >= 2){
                fprintf(fout,"%c$%d", ch, counter);
                num_car=num_car+3;
                counter = 0;
            }
            else{
                for(i=0;i<counter+1;i++){
                    fputc(ch, fout);
                    num_car++;
                }
                counter = 0;
            }
        }
        ch=ch1;
    }
    return num_car;
}

int decompress(FILE *fin, FILE *fout){
    char ch, ch1;
    int counter=0, num_car=0;
    int i=0;

    ch = fgetc(fin);
    while (!feof(fin)) {
        ch1 = fgetc(fin);
        if (ch1=='$') {
            counter = fgetc(fin) - '0';
            for(i=0;i<counter+1;i++){
                fputc(ch, fout);
                num_car++;
            }
            ch=fgetc(fin);
        }
        else {
            fputc(ch, fout);
            num_car++;
            ch=ch1;
        }

    }
    return num_car;
}



