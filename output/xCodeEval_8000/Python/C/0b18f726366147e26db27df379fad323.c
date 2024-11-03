#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* RL(int (*type)(char*), int* size) {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " ");
    int* result = malloc(sizeof(int) * (*size));
    int i = 0;
    while (token != NULL) {
        result[i++] = type(token);
        token = strtok(NULL, " ");
    }
    *size = i;
    return result;
}

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
    int size = 2;
    int* input = RL(atoi, &size);
    N = input[0];
    mod = input[1];
    free(input);
    printf("%d\n", from_base(A[N]) % mod);
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
