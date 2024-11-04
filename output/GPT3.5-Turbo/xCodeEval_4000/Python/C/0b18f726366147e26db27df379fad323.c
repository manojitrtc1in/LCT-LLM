#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int from_base(char* X) {
    char* base = "0123456789`~!@";
    int l = strlen(base);
    int r = 0;
    int e = 1;
    for (int i = strlen(X) - 1; i >= 0; i--) {
        char c = X[i];
        int index = 0;
        for (int j = 0; j < l; j++) {
            if (base[j] == c) {
                index = j;
                break;
            }
        }
        r += index * e;
        e *= l;
    }
    return r;
}

void solve() {
    int N, mod;
    scanf("%d %d", &N, &mod);
    char** A = (char**)malloc(N * sizeof(char*));
    for (int i = 0; i < N; i++) {
        A[i] = (char*)malloc(20 * sizeof(char));
        scanf("%s", A[i]);
    }
    printf("%d\n", from_base(A[N]) % mod);
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
