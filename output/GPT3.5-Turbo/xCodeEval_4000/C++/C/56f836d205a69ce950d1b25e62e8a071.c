#include <stdio.h>
#include <stdbool.h>
#include <math.h>

#define MAXN 300000005

bool isLucky(int n) {
    if (n == 2) {
        return true;
    }
    if (n < 3) {
        return false;
    }
    if (n % 4 != 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int get(int border) {
    int solved = 0;
    int result = 0;
    for (int i = 2; i <= border; ++i) {
        result += isLucky(i);
    }
    return result;
}

int main() {
    int precalc[MAXN];
    for (int i = 0; i < MAXN; ++i) {
        precalc[i] = get(i);
        if (i && i % 300000 == 0) {
            printf("res[%d] = %d;\n", i, precalc[i]);
        }
    }
    return 0;
}
