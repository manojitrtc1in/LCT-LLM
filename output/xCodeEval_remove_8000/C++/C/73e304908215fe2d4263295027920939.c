#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define i64 long long
#define ld long double

#define MAX_SIZE 1000000

i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);

typedef struct {
    i64 first;
    i64 second;
} pii;

typedef struct {
    pii first;
    i64 second;
} ppi;

typedef struct {
    i64 first;
    pii second;
} pip;

typedef struct {
    i64* arr;
    int size;
} vi;

typedef struct {
    ld* arr;
    int size;
} vd;

typedef struct {
    char** arr;
    int size;
} vs;

typedef struct {
    char* arr;
    int size;
} vc;

typedef struct {
    bool* arr;
    int size;
} vb;

i64 getbit(i64 s, int i) { return (s >> i) & 1; }

i64 onbit(i64 s, int i) { return s | (1LL << i); }

i64 offbit(i64 s, int i) { return s & (~(1LL << i)); }

int cntbit(i64 s) { return __builtin_popcountll(s); }

clock_t TimeStart;
clock_t TimeEnd;

void TimerStart() {
    TimeStart = clock();
}

void TimerStop() {
    TimeEnd = clock();
    double ElapsedTime = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
    printf("\n\nTime elapsed: %f seconds.\n", ElapsedTime);
}

void Exit() {
    TimerStop();
    exit(0);
}

i64 m, h1, a1, x1, y1, h2, a2, x2, y2;
vi vis1, vis2;

void Input() {
    scanf("%lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1);
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    vis1.size = m;
    vis1.arr = (i64*)malloc(vis1.size * sizeof(i64));
    memset(vis1.arr, -1, vis1.size * sizeof(i64));
    vis2.size = m;
    vis2.arr = (i64*)malloc(vis2.size * sizeof(i64));
    memset(vis2.arr, -1, vis2.size * sizeof(i64));
}

void Solve() {
    vis1.arr[h1] = 0;
    i64 id4 = -1, id5 = -1;
    while (true) {
        i64 z = (h1 * x1 + y1) % m;
        if (vis1.arr[z] != -1) {
            id4 = vis1.arr[z];
            id5 = (vis1.arr[h1] + 1) - vis1.arr[z];
            break;
        }
        else vis1.arr[z] = vis1.arr[h1] + 1;
        h1 = z;
    }
    vis2.arr[h2] = 0;
    i64 id0 = -1, id2 = -1;
    while (true) {
        i64 z = (h2 * x2 + y2) % m;
        if (vis2.arr[z] != -1) {
            id0 = vis2.arr[z];
            id2 = (vis2.arr[h2] + 1) - vis2.arr[z];
            break;
        }
        else vis2.arr[z] = vis2.arr[h2] + 1;
        h2 = z;
    }
    if (vis1.arr[a1] == -1 || vis2.arr[a2] == -1) {
        printf("-1");
        return;
    }
    if (vis1.arr[a1] < id4 && vis2.arr[a2] < id0) {
        if (vis1.arr[a1] == vis2.arr[a2]) printf("%lld", vis1.arr[a1]);
        else printf("-1");
        return;
    }
    if (vis1.arr[a1] >= id4 && vis2.arr[a2] >= id0) {
        i64 ans = -1;
        for (i64 i = 0; i <= MAX_SIZE; i++) {
            i64 expected = vis1.arr[a1] + id5 * i;
            if ((expected - vis2.arr[a2]) % id2 == 0 && (expected - vis2.arr[a2]) / id2 >= 0) {
                ans = expected;
                break;
            }
        }
        printf("%lld", ans);
        return;
    }
    if (vis1.arr[a1] < id4 && vis2.arr[a2] >= id0) {
        if ((vis1.arr[a1] - vis2.arr[a2]) % id2 == 0 && (vis1.arr[a1] - vis2.arr[a2]) / id2 >= 0) printf("%lld", vis1.arr[a1]);
        else printf("-1");
        return;
    }
    if (vis1.arr[a1] >= id4 && vis2.arr[a2] < id0) {
        if ((vis2.arr[a2] - vis1.arr[a1]) % id5 == 0 && (vis2.arr[a2] - vis1.arr[a1]) / id5 >= 0) printf("%lld", vis2.arr[a2]);
        else printf("-1");
        return;
    }
}

int main() {
    Input();
    TimerStart();
    Solve();
    TimerStop();
    return 0;
}
