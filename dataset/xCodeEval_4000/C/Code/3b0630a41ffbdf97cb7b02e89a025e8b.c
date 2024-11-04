



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int freq[10];
int main() {

    int n, k;
    scanf("%d %d", &n, &k);

    int** matrix = (int**)malloc(4 * n);

    for(int i = 0; i < n; i++)
        matrix[i] = (int*)malloc(4 * n);

    matrix[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j)
                matrix[i][j] = k;
            else
                matrix[i][j] = 0;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            printf("%d ", matrix[i][j]);

        }
        printf("\n");
    }
    return 0;

}
