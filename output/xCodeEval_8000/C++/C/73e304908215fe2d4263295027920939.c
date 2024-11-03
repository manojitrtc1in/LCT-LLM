#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define i64 long long
#define ld long double
#define rsz resize
#define pub push_back
#define mp make_pair
#define fi first
#define se second
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
typedef struct {
    i64 first;
    i64 second;
} pii;
typedef struct {
    i64 first;
    pii second;
} pip;
typedef struct {
    pii first;
    i64 second;
} ppi;
const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

int getbit(i64 s, int i) { return (s >> i) & 1; }
i64 onbit(i64 s, int i) { return s | (i64(1) << i); }
i64 offbit(i64 s, int i) { return s & (~(i64(1) << i)); }
int cntbit(i64 s) { return __builtin_popcountll(s); }

i64 m, h1, a1, x1, y1, h2, a2, x2, y2;
vi vis1, vis2;

void Input() {
    scanf("%lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1);
    scanf("%lld %lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    vis1.size = m;
    vis1.arr = (i64*)malloc(m * sizeof(i64));
    memset(vis1.arr, -1, m * sizeof(i64));
    vis2.size = m;
    vis2.arr = (i64*)malloc(m * sizeof(i64));
    memset(vis2.arr, -1, m * sizeof(i64));
}

void Solve() {
    vis1.arr[h1] = 0;
    i64 cycleStart1 = -1, cycleLen1 = -1;
    while (true) {
        i64 z = (h1 * x1 + y1) % m;
        if (vis1.arr[z] != -1) {
            cycleStart1 = vis1.arr[z];
            cycleLen1 = (vis1.arr[h1] + 1) - vis1.arr[z];
            break;
        }
        else vis1.arr[z] = vis1.arr[h1] + 1;
        h1 = z;
    }
    vis2.arr[h2] = 0;
    i64 cycleStart2 = -1, cycleLen2 = -1;
    while (true) {
        i64 z = (h2 * x2 + y2) % m;
        if (vis2.arr[z] != -1) {
            cycleStart2 = vis2.arr[z];
            cycleLen2 = (vis2.arr[h2] + 1) - vis2.arr[z];
            break;
        }
        else vis2.arr[z] = vis2.arr[h2] + 1;
        h2 = z;
    }
    if (vis1.arr[a1] == -1 || vis2.arr[a2] == -1) {printf("-1"); return;}
    if (vis1.arr[a1] < cycleStart1 && vis2.arr[a2] < cycleStart2) {
        if (vis1.arr[a1] == vis2.arr[a2]) printf("%lld", vis1.arr[a1]);
        else printf("-1"); return;
    }
    if (vis1.arr[a1] >= cycleStart1 && vis2.arr[a2] >= cycleStart2) {
        i64 ans = -1;
        for (i64 i=0; i<=1000000; i++) {
            i64 expected = vis1.arr[a1] + cycleLen1 * i;
            if ((expected - vis2.arr[a2]) % cycleLen2 == 0 && (expected - vis2.arr[a2]) / cycleLen2 >= 0) {
                ans = expected; break;
            }
        }
        printf("%lld", ans); return;
    }
    if (vis1.arr[a1] < cycleStart1 && vis2.arr[a2] >= cycleStart2) {
        if ((vis1.arr[a1] - vis2.arr[a2]) % cycleLen2 == 0 && (vis1.arr[a1] - vis2.arr[a2]) / cycleLen2 >= 0) printf("%lld", vis1.arr[a1]);
        else printf("-1"); return;
    }
    if (vis1.arr[a1] >= cycleStart1 && vis2.arr[a2] < cycleStart2) {
        if ((vis2.arr[a2] - vis1.arr[a1]) % cycleLen1 == 0 && (vis2.arr[a2] - vis1.arr[a1]) / cycleLen1 >= 0) printf("%lld", vis2.arr[a2]);
        else printf("-1"); return;
    }
}

int main() {
    Input();
    Solve();
    return 0;
}
