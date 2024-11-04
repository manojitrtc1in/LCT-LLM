



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>




void add(int* ct, int array[*ct], int nr) {

    for(int i = 0; i < *ct; i++)
        if(array[i] == nr)
            return;

    array[*ct] = nr;
    (*ct)++;


}

int main() {

    FILE* in = fopen("input.txt", "r");
    FILE* out = fopen("output.txt", "w");
    int n;
    scanf("%d", &n);
    int x[100001];
    int y[100001];
    int ct1 = 0, ct2 =0;
    for(int i = 0, a, b; i < n; i++) {

        scanf("%d %d", &a, &b);
        add(&ct1, x, a);
        add(&ct2, y, b);


    }

    printf("%d", (ct1 < ct2) ? ct1 : ct2);
    return 0;

}
