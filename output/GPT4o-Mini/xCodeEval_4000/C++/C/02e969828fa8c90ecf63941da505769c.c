#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define EPS 1e-9

typedef long long i64;

i64 n, m;

i64 modPow(i64 a, i64 b, i64 M) {
    if (b == 0) return 1;
    i64 tmp = modPow(a, b / 2, M);
    if (b % 2 == 0) return (tmp * tmp) % M;
    return (((tmp * tmp) % M) * a) % M;
}

void Input() {
    scanf("%lld %lld", &n, &m);
}

void Solve() {
    i64 A = (modPow(3, n, m) + m - 1) % m;
    printf("%lld", A);
}

void ControlIO(int argc, char* argv[]) {
    if (argc > 1) {
        freopen(argv[1], "r", stdin);
    }
    if (argc > 2) {
        freopen(argv[2], "w", stdout);
    }
}

void TimerStart(struct timespec *start) {
    clock_gettime(CLOCK_MONOTONIC, start);
}

void TimerStop(struct timespec *start) {
    struct timespec end;
    clock_gettime(CLOCK_MONOTONIC, &end);
    double elapsed = (end.tv_sec - start->tv_sec) + 
                    (end.tv_nsec - start->tv_nsec) / 1e9;
    printf("\n\nTime elapsed: %f seconds.\n", elapsed);
}

int main(int argc, char* argv[]) {
    struct timespec TimeStart;
    ControlIO(argc, argv);
    TimerStart(&TimeStart);
    
    Input();
    Solve();
    
    TimerStop(&TimeStart);
    return 0;
}
