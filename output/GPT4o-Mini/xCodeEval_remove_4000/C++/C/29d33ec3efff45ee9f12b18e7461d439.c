#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>

typedef long long i64;
typedef long double ld;
typedef struct {
    i64 first;
    i64 second;
} pii;
typedef struct {
    pii first;
    pii second;
} ppp;

#define MAX_N 1000
#define MAX_V 1000
#define ALPHABET_SIZE 26

const long long Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const long double Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1 + sqrt(5)) / 2);
long long keymod[] = {1000000007LL, 1000000009LL, 10000000021LL, 10000000033LL};
long long keyCount = sizeof(keymod) / sizeof(long long);

char id0[] = "FILE.IN";
char id2[] = "FILE.OUT";
char s1[MAX_N], s2[MAX_N], virus[MAX_N];
i64 n1, n2, nv;
i64 id1[MAX_V][ALPHABET_SIZE];

void ControlIO(int argc, char* argv[]);
void TimerStart();
void TimerStop();
void Exit();
void ProceedVirus();
void Input();
void Solve();

clock_t TimeStart, TimeEnd;

void ProceedVirus() {
    for (i64 i = 0; i < nv; i++) {
        for (i64 j = 0; j < ALPHABET_SIZE; j++) {
            char pref2[MAX_N];
            strncpy(pref2, virus, i);
            pref2[i] = (char)(65 + j);
            pref2[i + 1] = '\0';
            for (i64 x = i + 1; x >= 0; x--) {
                if (strncmp(pref2 + (i + 1 - x), virus, x) == 0) {
                    id1[i][j] = x; 
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
    i64 List1[ALPHABET_SIZE][MAX_N] = {0};
    i64 List2[ALPHABET_SIZE][MAX_N] = {0};
    i64 List1Count[ALPHABET_SIZE] = {0};
    i64 List2Count[ALPHABET_SIZE] = {0};

    for (i64 i = 0; i < n1; i++) List1[s1[i] - 'A'][List1Count[s1[i] - 'A']++] = i;
    for (i64 i = 0; i < n2; i++) List2[s2[i] - 'A'][List2Count[s2[i] - 'A']++] = i;

    ProceedVirus();
    ppp Default = {{-1, -1}, {-1, -1}};
    bool dp[MAX_N][MAX_N][MAX_N][nv + 1] = {false};
    ppp Last[MAX_N][MAX_N][MAX_N][nv + 1];

    for (i64 i = 0; i < n1; i++) {
        for (i64 j = 0; j < n2; j++) {
            if (s1[i] == s2[j]) dp[i][j][1][id1[0][s1[i] - 'A']] = true;
            else dp[i][j][0][0] = true;
        }
    }

    for (i64 x = 1; x < fmin(n1, n2); x++) {
        for (i64 i = 0; i < n1 - 1; i++) {
            for (i64 j = 0; j < n2 - 1; j++) {
                for (i64 y = 0; y < nv; y++) {
                    if (!dp[i][j][x][y]) continue;
                    for (i64 z = 0; z < ALPHABET_SIZE; z++) {
                        if (List1Count[z] == 0 || List2Count[z] == 0) continue;
                        i64 i1 = List1[z][1];
                        i64 j1 = List2[z][1];
                        dp[i1][j1][x + 1][id1[y][z]] = true;
                        Last[i1][j1][x + 1][id1[y][z]] = (ppp){{i, j}, {x, y}};
                    }
                }
            }
        }
    }

    for (i64 x = fmin(n1, n2); x > 0; x--) {
        for (i64 y = 0; y < nv; y++) {
            for (i64 i = 0; i < n1; i++) {
                for (i64 j = 0; j < n2; j++) {
                    if (!dp[i][j][x][y]) continue;
                    i64 I = i, J = j, X = x, Y = y;
                    char s[MAX_N] = "";
                    while (I != -1) {
                        strncat(s, (char[]){s1[I], '\0'}, 1);
                        ppp Token = Last[I][J][X][Y];
                        I = Token.first.first; J = Token.first.second;
                        X = Token.second.first; Y = Token.second.second;
                    }
                    for (i64 k = strlen(s) - 1; k >= 0; k--) {
                        putchar(s[k]);
                    }
                    putchar('\n');
                    return;
                }
            }
        }
    }
    printf("0\n");
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
    if (argc > 1) freopen(argv[1], "r", stdin);
    if (argc > 2) freopen(argv[2], "w", stdout);
    freopen(id0, "r", stdin);
    freopen(id2, "w", stdout);
}

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
