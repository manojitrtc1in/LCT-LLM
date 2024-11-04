#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

const int N = 18000;
const int M = 18000;
bool is[N]; 
int prm[M], cntp;

int getprm(int n) {
    int i, j, k = 0;
    int s, e = (int)(sqrt(0.0 + n) + 1);
    memset(is, 1, sizeof(is));
    prm[k++] = 2; 
    is[0] = is[1] = 0;
    for (i = 4; i < n; i += 2) is[i] = 0;
    for (i = 3; i < e; i += 2) 
        if (is[i]) {
            prm[k++] = i;
            for (s = i * 2, j = i * i; j < n; j += s)
                is[j] = 0;
        }
    for (; i < n; i += 2) 
        if (is[i]) prm[k++] = i;
    return k; 
}

