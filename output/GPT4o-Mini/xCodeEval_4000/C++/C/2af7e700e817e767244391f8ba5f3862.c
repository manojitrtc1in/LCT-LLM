#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_N 100010
#define EPS 1e-8
#define REP(a,b) for(long long (a) = 0; (a) < (b); ++(a))

typedef struct {
    int hoge[5];
} Vert;

bool sign(Vert a, Vert b) {
    int hoge = 0;
    REP(q, 5) {
        hoge += a.hoge[q] * b.hoge[q];
    }
    return hoge <= 0;
}

void solve() {
    int n;
    scanf("%d", &n);
    Vert inputs[MAX_N];
    REP(i, n) {
        REP(q, 5) {
            scanf("%d", &inputs[i].hoge[q]);
        }
    }
    int ans[MAX_N];
    int ans_size = 0;
    REP(i, n) {
        int ok = 1;
        REP(q, n) {
            if (i == q) continue;
            for (int j = q + 1; j < n; ++j) {
                if (i == j) continue;
                Vert A, B;
                REP(t, 5) {
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
            ans[ans_size++] = i;
        }
    }
    printf("%d\n", ans_size);
    REP(i, ans_size) {
        printf("%d ", ans[i] + 1);
    }
    printf("\n");
}

int main() {
    solve();
    return 0;
}
