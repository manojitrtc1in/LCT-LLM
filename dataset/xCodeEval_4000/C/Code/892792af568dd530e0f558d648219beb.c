



#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <limits.h>




int clothes[101];

int main() {

    int n;
    scanf("%d", &n);
    int studL, studR;
    for(int i = 0, l, r; i < n; i++) {

        scanf("%d %d", &l, &r);

        if(i == 0) {

            studL = l;
            studR = r;
            continue;

        }

        for(int j = l; j < r; j++)
            clothes[j] = 1;

    }

    int ct = 0;

    for(int i = studL; i < studR; i++)
        if(clothes[i] == 0 )
            ct++;

    printf("%d", ct);
    return 0;

}
