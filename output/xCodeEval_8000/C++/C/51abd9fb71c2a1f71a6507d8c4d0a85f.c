#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define i64 long long
#define pii struct pair
#define mp make_pair

typedef struct pair {
    i64 first;
    i64 second;
} pii;

i64 Min = 1e18, Max = -1e18;
i64 n;
pii A[100];

i64 Pow(i64 a, i64 b) {
    if (b == 0) return 1;
    i64 tmp = Pow(a, b/2);
    if (b % 2 == 0) return (tmp * tmp);
    return (tmp * tmp * a);
}

void Try(i64 id, i64 x1, i64 x2, i64 x3) {
    if (id == n) {
        Min = (x1+1)*(x2+2)*(x3+2) < Min ? (x1+1)*(x2+2)*(x3+2) : Min;
        Min = (x1+2)*(x2+1)*(x3+2) < Min ? (x1+2)*(x2+1)*(x3+2) : Min;
        Min = (x1+2)*(x2+2)*(x3+1) < Min ? (x1+2)*(x2+2)*(x3+1) : Min;
        Max = (x1+1)*(x2+2)*(x3+2) > Max ? (x1+1)*(x2+2)*(x3+2) : Max;
        Max = (x1+2)*(x2+1)*(x3+2) > Max ? (x1+2)*(x2+1)*(x3+2) : Max;
        Max = (x1+2)*(x2+2)*(x3+1) > Max ? (x1+2)*(x2+2)*(x3+1) : Max;
        return;
    }
    i64 key = A[id].first, v = A[id].second;
    for (i64 i=0; i<=v; i++) {
        for (i64 j=0; j<=v; j++) {
            for (i64 k=0; k<=v; k++) {
                if (i + j + k != v) continue;
                Try(id+1, x1 * Pow(key, i), x2 * Pow(key, j), x3 * Pow(key, k));
            }
        }
    }
}

void Input() {
    scanf("%lld", &n);
}

void Solve() {
    i64 Map[100] = {0};
    i64 N = n;
    for (i64 i=2; i<=sqrt(n); i++) {
        while (n % i == 0) {
            Map[i]++;
            n /= i;
        }
    }
    if (n > 1) Map[n]++;
    i64 idx = 0;
    for (i64 i=2; i<100; i++) {
        if (Map[i] > 0) {
            A[idx].first = i;
            A[idx].second = Map[i];
            idx++;
        }
    }
    n = idx;
    Try(0, 1, 1, 1);
    printf("%lld %lld", Min - N, Max - N);
}

int main() {
    Input();
    Solve();
    return 0;
}
