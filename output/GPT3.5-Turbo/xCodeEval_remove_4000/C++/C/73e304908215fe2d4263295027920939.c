#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define i64 long long
#define ld long double

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

#define MOD 1000000007LL
#define INF 1000000000
#define LINF 1000000000000000000
#define PI 3.141592653589793116
#define EPS 1e-9
#define GOLD ((1+sqrt(5))/2)

i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);

int getbit(i64 s, int i) { return (s >> i) & 1; }
i64 onbit(i64 s, int i) { return s | (1LL << i); }
i64 offbit(i64 s, int i) { return s & (~(1LL << i)); }
int cntbit(i64 s) { return __builtin_popcountll(s); }

clock_t TimeStart;
clock_t TimeEnd;

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
char id1[] = "FILE.IN";
char id3[] = "FILE.OUT";

i64 m, h1, a1, x1, y1, h2, a2, x2, y2;
i64 *vis1, *vis2;

void Input() {
    scanf("%lld %lld %lld %lld %lld", &m, &h1, &a1, &x1, &y1);
    scanf("%lld %lld %lld %lld", &h2, &a2, &x2, &y2);
    vis1 = (i64*)malloc(m * sizeof(i64));
    vis2 = (i64*)malloc(m * sizeof(i64));
    for (int i = 0; i < m; i++) {
        vis1[i] = -1;
        vis2[i] = -1;
    }
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
        }
        else vis1[z] = vis1[h1] + 1;
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
        }
        else vis2[z] = vis2[h2] + 1;
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

    Input();
    TimerStart();
    Solve();
    TimerStop();

    int T;
    scanf("%d", &T);
    TimerStart();
    while (T--) {
        Input();
        Solve();
    }
    TimerStop();

    return 0;
}

void ControlIO(int argc, char* argv[]) {
    char* infile = (char*)malloc((strlen(id1) + 1) * sizeof(char));
    char* outfile = (char*)malloc((strlen(id3) + 1) * sizeof(char));
    strcpy(infile, id1);
    strcpy(outfile, id3);

    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Source code by\n");
    printf("Current time: ");
    printf("%d-%s%d-%s%d | %s%d:%s%d:%s%d\n\n", now->tm_year + 1900,
        (now->tm_mon < 9) ? "0" : "", now->tm_mon + 1,
        (now->tm_mday < 10) ? "0" : "", now->tm_mday,
        (now->tm_hour < 10) ? "0" : "", now->tm_hour,
        (now->tm_min < 10) ? "0" : "", now->tm_min,
        (now->tm_sec < 10) ? "0" : "", now->tm_sec);

    printf("OI-Mode: ON\n");
    printf("Input file: %s\n", infile);
    printf("Output file: %s\n\n", outfile);

    printf("OI-Mode: OFF\n");
    printf("Input file: NULL\n");
    printf("Output file: NULL\n\n");

    printf("MultiTest-Mode: ON\n\n");

    printf("MultiTest-Mode: OFF\n\n");

    printf("Interactive-Mode: ON\n\n");

    printf("Interactive-Mode: OFF\n\n");

    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);

    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
}

void TimerStart() {
    TimeStart = clock();
}

void TimerStop() {
    TimeEnd = clock();
    double ElapsedTime = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
    printf("\n\nTime elapsed: %lf seconds.\n", ElapsedTime);
}

void Exit() {
    TimerStop();
    exit(0);
}
