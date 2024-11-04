#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int readInt() {
    char input[100];
    scanf("%s", input);
    return atoi(input);
}

void printInt64(long long int value) {
    printf("%lld", value);
}

void printLine() {
    printf("\n");
}

void solve() {
    int a = readInt();
    int b = readInt();
    
    long long int r = 0;
    for (int i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    long long int res = (long long int)a * r % MOD;

    long long int k = 0;
    for (int i = 1; i <= a; i++) {
        k += (long long int)i * r % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += (long long int)b * k % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    printInt64(res);
    printLine();
}

int main() {
    solve();
    return 0;
}
