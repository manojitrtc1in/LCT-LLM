#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long i64;
typedef long double ld;

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

i64 m, h1, a1, x1, y1, h2, a2, x2, y2;
i64 vis1[1000000], vis2[1000000];

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
char id1[] = "FILE.IN";
char id3[] = "FILE.OUT";

struct timespec TimeStart, TimeEnd;

void Input() {
    scanf("%lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1);
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    memset(vis1, -1, sizeof(vis1));
    memset(vis2, -1, sizeof(vis2));
}

void Solve() {
    vis1[h1] = 0;
    i64 id4 = -1, id5 = -1;
    while (1) {
        i64 z = (h1 * x1 + y1) % m;
        if (vis1[z] != -1) {
            id4 = vis1[z];
            id5 = (vis1[h1] + 1) - vis1[z];
            break;
        } else {
            vis1[z] = vis1[h1] + 1;
        }
        h1 = z;
    }
    
    vis2[h2] = 0;
    i64 id0 = -1, id2 = -1;
    while (1) {
        i64 z = (h2 * x2 + y2) % m;
        if (vis2[z] != -1) {
            id0 = vis2[z];
            id2 = (vis2[h2] + 1) - vis2[z];
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
    
    if (vis1[a1] < id4 && vis2[a2] < id0) {
        if (vis1[a1] == vis2[a2]) printf("%lld", vis1[a1]);
        else printf("-1");
        return;
    }
    
    if (vis1[a1] >= id4 && vis2[a2] >= id0) {
        i64 ans = -1;
        for (i64 i = 0; i <= 1000000; i++) {
            i64 expected = vis1[a1] + id5 * i;
            if ((expected - vis2[a2]) % id2 == 0 && (expected - vis2[a2]) / id2 >= 0) {
                ans = expected;
                break;
            }
        }
        printf("%lld", ans);
        return;
    }
    
    if (vis1[a1] < id4 && vis2[a2] >= id0) {
        if ((vis1[a1] - vis2[a2]) % id2 == 0 && (vis1[a1] - vis2[a2]) / id2 >= 0) printf("%lld", vis1[a1]);
        else printf("-1");
        return;
    }
    
    if (vis1[a1] >= id4 && vis2[a2] < id0) {
        if ((vis2[a2] - vis1[a1]) % id5 == 0 && (vis2[a2] - vis1[a1]) / id5 >= 0) printf("%lld", vis2[a2]);
        else printf("-1");
        return;
    }
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

void ControlIO(int argc, char* argv[]) {
    char infile[100], outfile[100];
    strcpy(infile, id1);
    strcpy(outfile, id3);
    
    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Source code by \n");
    printf("Current time: %d-%02d-%02d | %02d:%02d:%02d\n\n",
           now->tm_year + 1900, now->tm_mon + 1, now->tm_mday,
           now->tm_hour, now->tm_min, now->tm_sec);
    
    printf("OI-Mode: ON\n");
    printf("Input file: %s\n", infile);
    printf("Output file: %s\n", outfile);
    printf("\n");
    
    printf("OI-Mode: OFF\n");
    printf("Input file: NULL\n");
    printf("Output file: NULL\n");
    printf("\n");
    
    printf("MultiTest-Mode: ON\n");
    printf("MultiTest-Mode: OFF\n");
    
    printf("Interactive-Mode: ON\n\n");
    printf("Interactive-Mode: OFF\n\n");
    
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
}

void TimerStart() {
    clock_gettime(CLOCK_MONOTONIC, &TimeStart);
}

void TimerStop() {
    clock_gettime(CLOCK_MONOTONIC, &TimeEnd);
    double elapsedTime = (TimeEnd.tv_sec - TimeStart.tv_sec) + 
                         (TimeEnd.tv_nsec - TimeStart.tv_nsec) / 1e9;
    printf("\n\nTime elapsed: %f seconds.\n", elapsedTime);
}

void Exit() {
    TimerStop(); exit(0);
}
