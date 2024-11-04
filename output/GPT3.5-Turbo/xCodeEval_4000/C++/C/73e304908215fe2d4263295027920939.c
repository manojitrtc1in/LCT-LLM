#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define i64 long long
#define vi i64*
#define vd double*
#define vs char**
#define vc char*
#define vb bool*
#define pii struct { i64 first; i64 second; }
#define pip struct { i64 first; pii second; }
#define ppi struct { pii first; i64 second; }

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

int getbit(i64 s, int i) { return (s >> i) & 1; }
i64 onbit(i64 s, int i) { return s | (1LL << i); }
i64 offbit(i64 s, int i) { return s & (~(1LL << i)); }
int cntbit(i64 s) { return __builtin_popcountll(s); }

i64 m, h1, a1, x1, y1, h2, a2, x2, y2;
vi vis1, vis2;

void Input() {
    scanf("%lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1);
    scanf("%lld %lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    vis1 = (vi)malloc(m * sizeof(i64));
    vis2 = (vi)malloc(m * sizeof(i64));
    for (int i = 0; i < m; i++) {
        vis1[i] = -1;
        vis2[i] = -1;
    }
}

void Solve() {
    vis1[h1] = 0;
    i64 cycleStart1 = -1, cycleLen1 = -1;
    while (true) {
        i64 z = (h1 * x1 + y1) % m;
        if (vis1[z] != -1) {
            cycleStart1 = vis1[z];
            cycleLen1 = (vis1[h1] + 1) - vis1[z];
            break;
        }
        else vis1[z] = vis1[h1] + 1;
        h1 = z;
    }
    vis2[h2] = 0;
    i64 cycleStart2 = -1, cycleLen2 = -1;
    while (true) {
        i64 z = (h2 * x2 + y2) % m;
        if (vis2[z] != -1) {
            cycleStart2 = vis2[z];
            cycleLen2 = (vis2[h2] + 1) - vis2[z];
            break;
        }
        else vis2[z] = vis2[h2] + 1;
        h2 = z;
    }
    if (vis1[a1] == -1 || vis2[a2] == -1) {printf("-1"); return;}
    if (vis1[a1] < cycleStart1 && vis2[a2] < cycleStart2) {
        if (vis1[a1] == vis2[a2]) printf("%lld", vis1[a1]);
        else printf("-1"); return;
    }
    if (vis1[a1] >= cycleStart1 && vis2[a2] >= cycleStart2) {
        i64 ans = -1;
        for (i64 i=0; i<=1000000; i++) {
            i64 expected = vis1[a1] + cycleLen1 * i;
            if ((expected - vis2[a2]) % cycleLen2 == 0 && (expected - vis2[a2]) / cycleLen2 >= 0) {
                ans = expected; break;
            }
        }
        printf("%lld", ans); return;
    }
    if (vis1[a1] < cycleStart1 && vis2[a2] >= cycleStart2) {
        if ((vis1[a1] - vis2[a2]) % cycleLen2 == 0 && (vis1[a1] - vis2[a2]) / cycleLen2 >= 0) printf("%lld", vis1[a1]);
        else printf("-1"); return;
    }
    if (vis1[a1] >= cycleStart1 && vis2[a2] < cycleStart2) {
        if ((vis2[a2] - vis1[a1]) % cycleLen1 == 0 && (vis2[a2] - vis1[a1]) / cycleLen1 >= 0) printf("%lld", vis2[a2]);
        else printf("-1"); return;
    }
}

int main() {
    Input();
    Solve();
    return 0;
}
