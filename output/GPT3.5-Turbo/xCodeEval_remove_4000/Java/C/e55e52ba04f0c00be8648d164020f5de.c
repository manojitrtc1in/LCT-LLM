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

void getFactorization(int x) {
    while (x != 1) {
        printf("%d ", spf[x]);
        x = x / spf[x];
    }
}

int main() {
    sieve();

    long n;
    scanf("%ld", &n);

    long x = n;

    while (x % 2 == 0) {
        printf("2 ");
        x = x / 2;
    }

    for (int i = 3; i <= sqrt(x); i += 2) {
        while (x % i == 0) {
            printf("%d ", i);
            x = x / i;
        }
    }

    if (x > 2)
        printf("%ld", x);

    return 0;
}
