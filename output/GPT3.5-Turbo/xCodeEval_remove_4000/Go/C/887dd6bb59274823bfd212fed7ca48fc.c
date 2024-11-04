#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007

int readInt() {
    char buffer[20];
    scanf("%s", buffer);
    return atoi(buffer);
}

void printInt(int value) {
    printf("%d", value);
}

void printLine() {
    printf("\n");
}

void solve() {
    int a = readInt();
    int b = readInt();
    
    long long r = 0;
    for (int i = 1; i <= b - 1; i++) {
        r += i;
        if (r >= MOD) {
            r -= MOD;
        }
    }

    long long res = (long long)a * r % MOD;

    long long k = 0;
    for (int i = 1; i <= a; i++) {
        k += (long long)i * r % MOD;
        if (k >= MOD) {
            k -= MOD;
        }
    }

    res += (long long)b * k % MOD;
    if (res >= MOD) {
        res -= MOD;
    }

    printInt(res);
    printLine();
}

int main() {
    solve();
    return 0;
}
