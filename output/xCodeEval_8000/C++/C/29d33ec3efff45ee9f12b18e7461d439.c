#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef char i64;
typedef long double ld;
typedef char* vs;
typedef char* vc;
typedef int bool;
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

typedef struct {
    int argc;
    char** argv;
} ControlIOArgs;

void ControlIO(ControlIOArgs args);
void TimerStart();
void TimerStop();
void Exit();
char* cppstr_infile = "FILE.IN";
char* cppstr_outfile = "FILE.OUT";

typedef struct {
    pii first;
    pii second;
} ppp;
char s1[MAX_SIZE], s2[MAX_SIZE], virus[MAX_SIZE];
i64 n1, n2, nv;
int NextCommonPrefix[MAX_SIZE][26];

void ProceedVirus() {
    for (i64 i=0; i<nv; i++) {
        for (i64 j=0; j<26; j++) {
            char pref2[MAX_SIZE];
            strncpy(pref2, virus, i);
            pref2[i] = (char)(65 + j);
            pref2[i+1] = '\0';
            for (i64 x=i+1; x>=0; x--) {
                if (strncmp(pref2+(i+1-x), virus, x) == 0) {
                    NextCommonPrefix[i][j] = x;
                    break;
                }
            }
        }
    }
}

void Input() {
    scanf("%s %s %s", s1, s2, virus);
    nv = strlen(virus);
    n1 = strlen(s1);
    n2 = strlen(s2);
}

void Solve() {
    int List1[26][MAX_SIZE], List2[26][MAX_SIZE];
    for (i64 i=0; i<n1; i++) {
        List1[s1[i]-'A'][i] = i;
    }
    for (i64 i=0; i<n2; i++) {
        List2[s2[i]-'A'][i] = i;
    }
    ProceedVirus();
    ppp Default = { {-1, -1}, {-1, -1} };
    bool dp[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
    ppp Last[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
    for (i64 i=0; i<n1; i++) {
        for (i64 j=0; j<n2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j][1][NextCommonPrefix[0][s1[i]-'A']] = 1;
            } else {
                dp[i][j][0][0] = 1;
            }
        }
    }
    for (i64 x=1; x<MIN(n1, n2); x++) {
        for (i64 i=0; i<n1-1; i++) {
            for (i64 j=0; j<n2-1; j++) {
                for (i64 y=0; y<nv; y++) {
                    if (!dp[i][j][x][y]) continue;
                    for (i64 z=0; z<26; z++) {
                        if (List1[z][i] == -1) continue;
                        if (List2[z][j] == -1) continue;
                        i64 i1 = List1[z][i];
                        i64 j1 = List2[z][j];
                        dp[i1][j1][x+1][NextCommonPrefix[y][z]] = 1;
                        Last[i1][j1][x+1][NextCommonPrefix[y][z]] = (ppp) { {i, j}, {x, y} };
                    }
                }
            }
        }
    }
    for (i64 x=MIN(n1, n2); x>0; x--) {
        for (i64 y=0; y<nv; y++) {
            for (i64 i=0; i<n1; i++) {
                for (i64 j=0; j<n2; j++) {
                    if (!dp[i][j][x][y]) continue;
                    i64 I = i, J = j, X = x, Y = y;
                    char s[MAX_SIZE];
                    i64 idx = 0;
                    while (I != -1) {
                        s[idx++] = s1[I];
                        ppp Token = Last[I][J][X][Y];
                        I = Token.first.first;
                        J = Token.first.second;
                        X = Token.second.first;
                        Y = Token.second.second;
                    }
                    s[idx] = '\0';
                    printf("%s\n", s);
                    return;
                }
            }
        }
    }
    printf("0\n");
}

int main(int argc, char* argv[]) {
    ControlIO((ControlIOArgs) {argc, argv});
    
    Input();
    TimerStart();
    Solve();
    TimerStop();
    
    return 0;
}

void ControlIO(ControlIOArgs args) {
    char* infile = (char*)malloc(strlen(cppstr_infile)+1);
    char* outfile = (char*)malloc(strlen(cppstr_outfile)+1);
    strcpy(infile, cppstr_infile);
    strcpy(outfile, cppstr_outfile);
    #ifdef Akikaze
    time_t t = time(0);
    struct tm* now = localtime(&t);
    printf("Source code by #Team4T-Akikaze.\n");
    printf("Current time: ");
    printf("%d-%s%d-%s%d | %s%d:%s%d:%s%d\n\n", (now->tm_year + 1900),
        ((now->tm_mon < 9) ? "0" : ""), (now->tm_mon + 1),
        ((now->tm_mday < 10) ? "0" : ""), now->tm_mday,
        ((now->tm_hour < 10) ? "0" : ""), now->tm_hour,
        ((now->tm_min < 10) ? "0" : ""), now->tm_min,
        ((now->tm_sec < 10) ? "0" : ""), now->tm_sec);
    
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
    
    if (args.argc > 1) freopen(args.argv[1], "r", stdin);
    if (args.argc > 2) freopen(args.argv[2], "w", stdout);
    #elif OImode
    freopen(infile, "r", stdin);
    freopen(outfile, "w", stdout);
    #endif
}

void TimerStart() {
    #ifdef Akikaze
    TimeStart = clock();
    #endif
}

void TimerStop() {
    #ifdef Akikaze
    TimeEnd = clock();
    double ElapsedTime = (double)(TimeEnd - TimeStart) / CLOCKS_PER_SEC;
    printf("\n\nTime elapsed: %lf seconds.\n", ElapsedTime);
    #endif
}

void Exit() {
    TimerStop();
    exit(0);
}
