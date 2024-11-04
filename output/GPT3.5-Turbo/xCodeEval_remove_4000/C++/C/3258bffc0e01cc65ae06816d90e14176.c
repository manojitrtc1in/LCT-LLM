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

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

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
char id0[] = "FILE.IN";
char id1[] = "FILE.OUT";

char s[1000005];
int q = 0;
int Map[256];

void Input() {
    scanf("%s", s);
}

void Solve() {
    i64 baseAnswer = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        char x = s[i];
        if (x >= '0' && x <= '9') continue;
        if (x == '?') {q++; continue;} Map[x]++;
    }
    for (i64 i = 10; i > 10 - Map.size(); i--) baseAnswer *= i;
    if (s[0] >= 'A' && s[0] <= 'J') {baseAnswer /= 10; baseAnswer *= 9;}
    if (s[0] == '?') {baseAnswer *= 9; q--;}
    printf("%lld", baseAnswer);
    for (i64 i = 0; i < q; i++) printf("0");
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);

    Input(); TimerStart();
    Solve(); TimerStop();

    int T; scanf("%d", &T); TimerStart();
    while(T--) {Input(); Solve();}
    TimerStop();

    return 0;
}

void ControlIO(int argc, char* argv[]) {
    char* infile = (char*)malloc(sizeof(char) * (strlen(id0) + 1));
    char* outfile = (char*)malloc(sizeof(char) * (strlen(id1) + 1));
    strcpy(infile, id0);
    strcpy(outfile, id1);

    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Source code by\n");
    printf("Current time: ");
    printf("%d-", (now->tm_year + 1900));
    printf("%s%d-", (now->tm_mon < 9) ? "0" : "", (now->tm_mon + 1));
    printf("%s%d | ", (now->tm_mday < 10) ? "0" : "", now->tm_mday);
    printf("%s%d:", (now->tm_hour < 10) ? "0" : "", now->tm_hour);
    printf("%s%d:", (now->tm_min < 10) ? "0" : "", now->tm_min);
    printf("%s%d", (now->tm_sec < 10) ? "0" : "", now->tm_sec);
    printf("\n\n");

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
    TimeStart = clock();
}

void TimerStop() {
    TimeEnd = clock();
    double ElapsedTime = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
    printf("\n\nTime elapsed: %lf seconds.\n", ElapsedTime);
}

void Exit() {
    TimerStop(); exit(0);
}