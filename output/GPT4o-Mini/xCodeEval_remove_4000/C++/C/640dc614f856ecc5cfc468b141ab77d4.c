#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef long long i64;
typedef struct {
    i64 fi;
    i64 se;
} pii;

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 10000000021LL, 10000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

i64 x;
clock_t TimeStart, TimeEnd;

pii func(i64 m, i64 n, i64 s) {
    if (m == 0) return (pii){n, s};
    i64 k = cbrt(m);
    i64 xx = k * k * k, y = (k - 1) * (k - 1) * (k - 1);
    pii res1 = func(m - xx, n + 1, s + xx);
    pii res2 = func(xx - y - 1, n + 1, s + y);
    return (res1.fi > res2.fi) ? res1 : res2;
}

void Input() {
    scanf("%lld", &x);
}

void Solve() {
    pii Token = func(x, 0, 0);
    printf("%lld %lld\n", Token.fi, Token.se);
}

void TimerStart() {
    TimeStart = clock();
}

void TimerStop() {
    TimeEnd = clock();
    double ElapsedTime = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
    printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime);
}

void ControlIO(int argc, char* argv[]) {
    char* infile = "FILE.IN";
    char* outfile = "FILE.OUT";

    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Current time: %04d-%02d-%02d %02d:%02d:%02d\n\n",
           now->tm_year + 1900, now->tm_mon + 1, now->tm_mday,
           now->tm_hour, now->tm_min, now->tm_sec);

    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);

    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);
    Input(); TimerStart();
    Solve(); TimerStop();

    int T; scanf("%d", &T); TimerStart();
    while (T--) {
        Input(); Solve();
    }
    TimerStop();

    return 0;
}
