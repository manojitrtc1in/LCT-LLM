#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

typedef long long i64;
typedef long double ld;
typedef struct {
    char key;
    i64 value;
} pair;

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

char s[100];
pair Map[256];
i64 q = 0;

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();

void Input() {
    scanf("%s", s);
}

void Solve() {
    i64 baseAnswer = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        char x = s[i];
        if (x >= '0' && x <= '9') continue;
        if (x == '?') { q++; continue; }
        Map[x].key = x;
        Map[x].value++;
    }
    for (i64 i = 10; i > 10 - keyCount; i--) baseAnswer *= i;
    if (s[0] >= 'A' && s[0] <= 'J') { baseAnswer /= 10; baseAnswer *= 9; }
    if (s[0] == '?') { baseAnswer *= 9; q--; }
    printf("%lld", baseAnswer);
    for (i64 i = 0; i < q; i++) printf("0");
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);
    Input(); TimerStart();
    Solve(); TimerStop();

    int T; scanf("%d", &T); TimerStart();
    while (T--) { Input(); Solve(); }
    TimerStop();

    return 0;
}

void ControlIO(int argc, char* argv[]) {
    char infile[] = "FILE.IN";
    char outfile[] = "FILE.OUT";

    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Source code by \n");
    printf("Current time: ");
    printf("%d-%02d-%02d | %02d:%02d:%02d\n\n",
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
    // Timer start logic can be added here if needed
}

void TimerStop() {
    // Timer stop logic can be added here if needed
}

void Exit() {
    TimerStop(); exit(0);
}
