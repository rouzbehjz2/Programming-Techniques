//      Exercise 1.
//      Category: problems with numerical matrixes, verification, and selection problems.
//      Championship
//      In a championship n (max 20) teams play for m (max 20) days. The outcome of the matches is stored a
//      matrix of n × m integers, each of which can only be either 0, 1 or 3. Each i-th row of the matrix
//      represents the points acquired by the i-th team in the m days of the championship. Each j-th column
//      of the matrix represents the points acquired by the n teams in the matches of the j-th day. The points
//      acquired are 3 for a won game, 1 for tied and 0 for a defeat, respectively.
//      Write a program C that:
//      - acquires the content of the matrix from a text file whose name (20 characters maximum) is read from
//      the keyboard, defining a suitable format for the file. For example, you may assume that the first line
//      reports the values n and m, separated by a space, and each following line reports a row of the matrix,
//      with spaces as separators:
//
//      6 4
//      0 1 1 0
//      3 1 0 1
//      1 0 1 1
//      1 3 1 0
//      1 0 1 3
//      1 3 3 3
//
//      - for each matchday of the championship, print the index (i.e., the corresponding row number) of the
//      team that is currently leading the championship (i.e., the team that has the highest sum of points since
//      the beginning of the championship). In case there is more than one leading team, the program should
//      print the first that is found.


#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;

    FILE *file = fopen("champ.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fscanf(file, "%d %d", &n, &m);

    int matrix[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            fscanf(file, "%d", &matrix[i][j]);
        }
    }

    fclose(file);

    int points[n];

    for (int i = 0; i < n; i++) {
        points[i] = 0;
    }

    int max_points = 0;
    int leader = -1;

    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            points[i] += matrix[i][j];
            if (points[i] > max_points) {
                max_points = points[i];
                leader = i + 1;
            }
        }
        printf("Day %d: Leader is Team %d\n", j + 1, leader);
    }

    return 0;
}
