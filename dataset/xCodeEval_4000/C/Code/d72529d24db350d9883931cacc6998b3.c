



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>

int vect[101];

int main() {

    int n;
    scanf("%d", &n);

    int x, y = 0, a = 0, b = 0;
    int ct = 0;

    for(int i = 0; i < n; i++) {

        scanf("%d", &x);
        if(x == 0 || x == 100)
            vect[ct++] = x;
        else
        if(x <= 9 && a == 0) {

            vect[ct++] = x;
            a = 1;

        } else if(x % 10 == 0 && b == 0) {

            vect[ct++] = x;
            b = 1;

        } else
            y = x;
    }

    if(!a && !b && y)
        vect[ct++] = y;

    printf("%d\n", ct);

    for(int i = 0; i < ct; i++)
        printf("%d ", vect[i]);
    return 0;

}
