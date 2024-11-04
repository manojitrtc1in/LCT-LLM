#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Input();
void Solve();
void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();

char* cppstr_infile = "FILE.IN";
char* cppstr_outfile = "FILE.OUT";

char s[1000000];
map<char, i64> Map;
i64 q = 0;

void Input() {
    scanf("%s", s);
}

void Solve() {
    i64 baseAnswer = 1;
    for (int i = 0; i < strlen(s); i++) {
        char x = s[i];
        if (x >= '0' && x <= '9') continue;
        if (x == '?') {q++; continue;} Map[x]++;
    }
    for (i64 i=10; i>10-Map.size(); i--) baseAnswer *= i;
    if (s[0] >= 'A' && s[0] <= 'J') {baseAnswer /= 10; baseAnswer *= 9;}
    if (s[0] == '?') {baseAnswer *= 9; q--;}
    printf("%lld", baseAnswer);
    for (i64 i=0; i<q; i++) printf("0");
}

int main(int argc, char* argv[]) {
    ControlIO(argc, argv);

    Input();
    TimerStart();
    Solve();
    TimerStop();

    return 0;
}

void ControlIO(int argc, char* argv[]) {
    char* infile = (char*)malloc(strlen(cppstr_infile)+1);
    char* outfile = (char*)malloc(strlen(cppstr_outfile)+1);
    strcpy(infile, cppstr_infile);
    strcpy(outfile, cppstr_outfile);
    #ifdef Akikaze
        time_t t = time(0);
        tm* now = localtime(&t);
        printf("Source code by #Team4T-Akikaze.\n");
        printf("Current time: ");
        printf("%d-%s%d-%s%d | %s%d:%s%d:%s%d\n\n",
            (now->tm_year + 1900),
            ((now->tm_mon < 9) ? "0" : ""),
            (now->tm_mon + 1),
            ((now->tm_mday < 10) ? "0" : ""),
            now->tm_mday,
            ((now->tm_hour < 10) ? "0" : ""),
            now->tm_hour,
            ((now->tm_min < 10) ? "0" : ""),
            now->tm_min,
            ((now->tm_sec < 10) ? "0" : ""),
            now->tm_sec
        );
        
        #ifdef OImode
            printf("OI-Mode: ON\n");
            printf("Input file: %s\n", infile);
            printf("Output file: %s\n\n", outfile);
        #else
            printf("OI-Mode: OFF\n");
            printf("Input file: NULL\n");
            printf("Output file: NULL\n\n");
        #endif
        
        #ifdef MultiTest
            printf("MultiTest-Mode: ON\n");
        #else
            printf("MultiTest-Mode: OFF\n");
        #endif
        
        #ifdef Interactive
            printf("Interactive-Mode: ON\n\n");
        #else
            printf("Interactive-Mode: OFF\n\n");
        #endif
        
        if (argc > 1) freopen(argv[1], "r", stdin);
        if (argc > 2) freopen(argv[2], "w", stdout);
    #elif OImode
        freopen(infile, "r", stdin);
        freopen(outfile, "w", stdout);
    #endif
}

void TimerStart() {
    #ifdef Akikaze
        TimeStart = chrono::steady_clock::now();
    #endif
}

void TimerStop() {
    #ifdef Akikaze
        TimeEnd = chrono::steady_clock::now();
        auto ElapsedTime = TimeEnd - TimeStart;
        printf("\n\nTime elapsed: %lf seconds.\n", chrono::duration<double>(ElapsedTime).count());
    #endif
}

void Exit() {
    TimerStop();
    exit(0);
}
