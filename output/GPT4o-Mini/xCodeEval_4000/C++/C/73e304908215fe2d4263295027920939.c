#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_M 1000000
#define INF 1000000000LL
#define LINF 1000000000000000000LL

long long m, h1, a1, x1, y1, h2, a2, x2, y2;
long long vis1[MAX_M], vis2[MAX_M];

void Input() {
    scanf("%lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1);
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    memset(vis1, -1, sizeof(vis1));
    memset(vis2, -1, sizeof(vis2));
}

void Solve() {
    vis1[h1] = 0;
    long long cycleStart1 = -1, cycleLen1 = -1;
    
    while (1) {
        long long z = (h1 * x1 + y1) % m;
        if (vis1[z] != -1) {
            cycleStart1 = vis1[z];
            cycleLen1 = (vis1[h1] + 1) - vis1[z];
            break;
        } else {
            vis1[z] = vis1[h1] + 1;
        }
        h1 = z;
    }
    
    vis2[h2] = 0;
    long long cycleStart2 = -1, cycleLen2 = -1;
    
    while (1) {
        long long z = (h2 * x2 + y2) % m;
        if (vis2[z] != -1) {
            cycleStart2 = vis2[z];
            cycleLen2 = (vis2[h2] + 1) - vis2[z];
            break;
        } else {
            vis2[z] = vis2[h2] + 1;
        }
        h2 = z;
    }
    
    if (vis1[a1] == -1 || vis2[a2] == -1) {
        printf("-1");
        return;
    }
    
    if (vis1[a1] < cycleStart1 && vis2[a2] < cycleStart2) {
        if (vis1[a1] == vis2[a2]) {
            printf("%lld", vis1[a1]);
        } else {
            printf("-1");
        }
        return;
    }
    
    if (vis1[a1] >= cycleStart1 && vis2[a2] >= cycleStart2) {
        long long ans = -1;
        for (long long i = 0; i <= 1000000; i++) {
            long long expected = vis1[a1] + cycleLen1 * i;
            if ((expected - vis2[a2]) % cycleLen2 == 0 && (expected - vis2[a2]) / cycleLen2 >= 0) {
                ans = expected;
                break;
            }
        }
        printf("%lld", ans);
        return;
    }
    
    if (vis1[a1] < cycleStart1 && vis2[a2] >= cycleStart2) {
        if ((vis1[a1] - vis2[a2]) % cycleLen2 == 0 && (vis1[a1] - vis2[a2]) / cycleLen2 >= 0) {
            printf("%lld", vis1[a1]);
        } else {
            printf("-1");
        }
        return;
    }
    
    if (vis1[a1] >= cycleStart1 && vis2[a2] < cycleStart2) {
        if ((vis2[a2] - vis1[a1]) % cycleLen1 == 0 && (vis2[a2] - vis1[a1]) / cycleLen1 >= 0) {
            printf("%lld", vis2[a2]);
        } else {
            printf("-1");
        }
        return;
    }
}

int main(int argc, char* argv[]) {
    Input();
    Solve();
    return 0;
}
