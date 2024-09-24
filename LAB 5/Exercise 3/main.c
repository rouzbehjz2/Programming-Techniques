//      Exercise 3.
//
//      Category: problems with numerical matrices and text processing.
//
//      Write a C program that allows the user to perform sequential rotation operations of P positions on
//      specified rows and / or columns of an input integer matrix. The rotations are to be interpreted as circular
//      both on the rows and on the columns (see definition given in Lab. 4 ex. 2). Consider the rows and
//      columns numbered starting from 1 (NB: in C, indexes of a matrix start from 0!).
//      The program should:
//      - read the initial matrix (max 30 x 30) from a file, whose name (20 characters maximum) is acquired
//      from the keyboard. The file should contain 2 integer values “nr nc” on the first line, indicating
//      the number of rows “nr” and columns “nc” of the matrix. The following nr lines of the file,
//      one per row of the matrix, should report nc integers each, separated by spaces.
//      - repeatedly acquire a command (string of maximum 100 characters, containing spaces) from the
//      keyboard, in the format
//      <selector> <index> <direction> <locations>
//      Where <selector> is either the string “row”, “column” or “end”, respectively indicating
//      whether the user wants to perform the rotation on a row ("row"), on a column ("column"), or
//      terminate the program ("end").
//      <index> is the index of the selected row/column, starting from 1
//      <direction> is either the string “right”, ”left”, ”up” or “down”, indicating the direction of
//      the rotation
//      <locations> is a positive integer indicating the number of positions P of the rotation.
//      The resulting matrix after each sequential rotation should be printed on the screen.
//      NB. To perform the rotation, implement a function that generalizes what you have already
//      implemented in Lab 4, ex.2.
//      Example of input file:
//      3 3
//      1 2 3
//      4 5 6
//      7 8 9
//      Example of sequential commands acquired from keyboard:
//      row 2 right 1
//      column 3 down 2
//      row 1 left 4
//      column 1 up 2
//      end


#include <stdio.h>
#include <stdlib.h>



void changing(int **,int,int ,char , int ,char, int);
int main() {
    FILE *my_file;

    if ((my_file = fopen("../Matrix.txt", "r")) == NULL) {
        perror("ERROR READING FILE");
        fclose(my_file);
        return 1;
    }
    int nr,nc;
    if ((fscanf(my_file,"%d%d",&nr,&nc))!=2){
        printf("ERROR READING FIRST LINE ");
        fclose(my_file);
        return 1;
    }

    int matrix[nr][nc];
    for(int  i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            fscanf(my_file, "%d",&matrix[i][j]);
        }
    }
    printf("the matrix is :\n");
    for(int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }

    /*printf("\n");
    char selector;
    printf("please insert the ROW or COLUMN :");
    scanf(" %c",&selector);
    int index;
    printf("please insert the index :");
    scanf("%d",&index);
    char direction;
    printf("please insert the direction you would like to go:");
    scanf(" %c",&direction);
    int dimension;
    printf("please insert the dimension you would like :");
    scanf("%d",&dimension);*/
    int final[nr][nc];
    int dim;
    char selector;
    printf("please insert how many location you would like to move :");
    scanf("%d",&dim);
    int index;
    printf("please insert the index you want to change ;");
    scanf("%d",&index);
    printf("please choose the row or column :(for choosing row just insert 'r' and for choosing column just insert 'c)\n");
    scanf(" %c",&selector);
    char direction;
    printf("please insert the direction you would like to meove.\n(for column just insert 'u' for up and 'd' for down.)\n(for row just insert 'r' for right abd 'l' for left.):");
    scanf(" %c",&direction);

    if((selector=='c' || selector=='C') && (direction=='d' || direction=='D')){
    for (int j=0;j<nc;j++){
        if(j==index)
            for(int i=0;i<nr;i++){
            final[(i+dim+nr)%nr][j]=matrix[i][j];
            }
        else
            for(int i=0;i<nr;i++) {
                for(int j=0;j<nc;j++)
                    if(j!=index)
                        final[i][j]=matrix[i][j];
            }}}

        printf("the second matrix is : \n");
            for (int i=0;i<nr;i++){
                for(int j=0;j<nc;j++){
                    printf("%d ",final[i][j]);
                }
                printf("\n");}


    if((selector=='c' || selector=='C') && (direction=='u' || direction=='U')){
        for (int j=0;j<nc;j++){
            if(j==index)
                for(int i=0;i<nr;i++){
                    final[(2*nr +i -dim)%nr][j]=matrix[i][j];
                }
            else
                for(int i=0;i<nr;i++) {
                    for(int j=0;j<nc;j++)
                        if(j!=index)
                            final[i][j]=matrix[i][j];
                }}}

    if((selector=='r' || selector=='R') && (direction=='r' || selector=='R')){
        for(int i=0;i<nr;i++)
            if(i==index)
                for(int j=0;j<nc;j++) {
                    final[i][(j + dim + nc) % nc] = matrix[i][j];
                }
        else
            for(int i=0;i<nr;i++)
                for(int j=0;j<nc;j++)
                    if(i!=index)
                        final[i][j]=matrix[i][j];

                }

    if((selector=='r' || selector=='R') && (direction=='l' || selector=='L')){
        for(int i=0;i<nr;i++)
            if(i==index)
                for(int j=0;j<nc;j++) {
                    final[i][(j - dim + nc*2) % nc] = matrix[i][j];
                }
            else
                for(int i=0;i<nr;i++)
                    for(int j=0;j<nc;j++)
                        if(i!=index)
                            final[i][j]=matrix[i][j];

    }


    printf("the second matrix is : \n");
    for (int i=0;i<nr;i++){
        for(int j=0;j<nc;j++){
            printf("%d ",final[i][j]);
        }
        printf("\n");}





    fclose(my_file);
    return 0 ;
    }