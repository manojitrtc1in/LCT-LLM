#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

char* A[] = {"0", "1", "2", "6", "(", "D", "E3", "_&", "/51", "n`6", "n4>", "!rR2", "E+a*", "j61h1", "!3ab!", "q`t6"};

long long from_base(const char* X) {
    const char* base = "0123456789`~!@";
    int l = strlen(base);
    long long r = 0;
    long long e = 1;

    for (int i = 0; X[i] != '\0'; i++) {
        char* pos = strchr(base, X[i]);
        if (pos) {
            r += (pos - base) * e;
            e *= l;
        }
    }
    return r;
}

void solve() {
    int N, mod;
    scanf("%d %d", &N, &mod);
    printf("%lld\n", from_base(A[N]) % mod);
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
