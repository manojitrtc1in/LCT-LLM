



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int main() {

    int n, m;
    scanf("%d %d", &n, &m);

    int array[n + 1];
    int pos = 0, neg = 0;
    for(int i = 1 ;i <= n; i++) {

        scanf("%d", &array[i]);
        if(array[i] > 0)
            pos++;
        else
            neg++;

    }

    for(int i = 0, a, b; i < m; i++) {

        scanf("%d %d", &a, &b);

        if(a == b || (b - a + 1) % 2 == 1)
            printf("0\n");
        else {

            printf((pos >= (b - a + 1) / 2 && neg >= (b - a + 1) / 2) ? "1\n" : "0\n");

        }

    }
    return 0;

}
