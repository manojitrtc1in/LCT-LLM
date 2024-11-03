#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Vert {
    int hoge[5];
} Vert;

int sign(Vert a, Vert b) {
    int hoge = 0;
    for (int q = 0; q < 5; q++) {
        hoge += a.hoge[q] * b.hoge[q];
    }
    return hoge <= 0;
}

void solve() {
    int n;
    scanf("%d", &n);
    Vert inputs[n];
    for (int i = 0; i < n; i++) {
        for (int q = 0; q < 5; q++) {
            scanf("%d", &inputs[i].hoge[q]);
        }
    }
    int ans[n];
    int ans_count = 0;
    for (int i = 0; i < n; i++) {
        int ok = 1;
        for (int q = 0; q < n; q++) {
            if (i == q) continue;
            for (int j = q + 1; j < n; j++) {
                if (i == j) continue;
                Vert A, B;
                for (int t = 0; t < 5; t++) {
                    A.hoge[t] = inputs[q].hoge[t] - inputs[i].hoge[t];
                    B.hoge[t] = inputs[j].hoge[t] - inputs[i].hoge[t];
                }
                if (sign(A, B) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 0) break;
        }
        if (ok == 1) {
            ans[ans_count] = i;
            ans_count++;
        }
    }
    printf("%d\n", ans_count);
    for (int i = 0; i < ans_count; i++) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}
