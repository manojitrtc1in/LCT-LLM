#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 10000001

int spf[MAXN];

void sieve() {
    spf[1] = 1;
    for (int i = 2; i < MAXN; i++)
        spf[i] = i;

    for (int i = 4; i < MAXN; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int* getFactorization(int x, int* size) {
    int* ret = (int*)malloc(MAXN * sizeof(int));
    *size = 0;
    while (x != 1) {
        ret[*size] = spf[x];
        x = x / spf[x];
        (*size)++;
    }
    return ret;
}

void solve() {
    long n;
    scanf("%ld", &n);

    long x = n;

    int size;
    int* list = getFactorization(x, &size);

    if (n == 1) {
        printf("1\n");
        printf("0\n");
    } else if (size == 2) {
        printf("2\n");
    } else {
        printf("1\n");
        if (size == 1) {
            printf("0\n");
        } else {
            long ans = list[0] * list[1];
            printf("%ld\n", ans);
        }
    }

    free(list);
}

int main() {
    sieve();
    solve();
    return 0;
}
