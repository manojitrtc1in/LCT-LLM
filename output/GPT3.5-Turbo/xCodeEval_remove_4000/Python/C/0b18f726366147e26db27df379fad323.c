#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* RL(int (*type)(char*), int* length) {
    char input[1000];
    fgets(input, sizeof(input), stdin);
    char* token = strtok(input, " \n");
    int* result = (int*)malloc(sizeof(int) * (*length));
    int i = 0;
    while (token != NULL) {
        result[i++] = type(token);
        token = strtok(NULL, " \n");
    }
    return result;
}

int from_base(char* X) {
    char* base = "0123456789`~!@";
    int l = strlen(base);
    int r = 0;
    int e = 1;
    for (int i = strlen(X) - 1; i >= 0; i--) {
        int index = 0;
        while (base[index] != X[i]) {
            index++;
        }
        r += index * e;
        e *= l;
    }
    return r;
}

void solve() {
    int* RL_result;
    int RL_length = 2;
    RL_result = RL(atoi, &RL_length);
    int N = RL_result[0];
    int mod = RL_result[1];
    free(RL_result);
    printf("%d\n", from_base(A[N]) % mod);
}

int main() {
    int T = 1;
    for (int t = 0; t < T; t++) {
        solve();
    }
    return 0;
}
