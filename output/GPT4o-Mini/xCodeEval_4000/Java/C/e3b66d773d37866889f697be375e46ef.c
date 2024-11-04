#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_N 1000
#define INF 1e16

int n, k, m;
long mod;
int a[MAX_N];
int notmemo[MAX_N][2];
long fib[MAX_N];
int isComposite[MAX_N + 1];
int primes[MAX_N];
int primeCount = 0;

typedef struct {
    int x;
    int y;
} Pair;

typedef struct {
    int idx;
    long score;
} Book;

typedef struct {
    int numofbooks;
    int signup;
    int shiprate;
    int idx;
} Library;

typedef struct {
    int node;
    long cost;
} Edge;

typedef struct {
    long x, y;
} Point;

void sieve(int N) {
    memset(isComposite, 0, sizeof(isComposite));
    isComposite[0] = isComposite[1] = 1;

    for (int i = 2; i <= N; ++i) {
        if (isComposite[i] == 0) {
            primes[primeCount++] = i;
            if (1L * i * i <= N) {
                for (int j = i * i; j <= N; j += i) {
                    isComposite[j] = 1;
                }
            }
        }
    }
}

int dp(int idx, int state) {
    if (idx == n) {
        return 0;
    }
    if (notmemo[idx][state] != -1) {
        return notmemo[idx][state];
    }
    int take = 0, leave = 0, leaveall = 0;
    if (a[idx] == 1 && (state == 1 || state == 0)) {
        take = 1 + dp(idx + 1, 1);
    }
    if (a[idx] == 0 && state == 0) {
        leave = 1 + dp(idx + 1, state);
    }
    leaveall = dp(idx + 1, state);
    return notmemo[idx][state] = (take > leave ? (take > leaveall ? take : leaveall) : (leave > leaveall ? leave : leaveall));
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    memset(notmemo, -1, sizeof(notmemo));
    printf("%d\n", dp(0, 0));
    return 0;
}
