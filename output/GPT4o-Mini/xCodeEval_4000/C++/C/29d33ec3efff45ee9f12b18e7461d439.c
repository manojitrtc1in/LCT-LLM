#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <time.h>

#define MAX_N 1000
#define ALPHABET_SIZE 26
#define INF 1e9
#define LINF 1e18
#define MOD 1000000007LL

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    pii first;
    pii second;
} ppp;

char s1[MAX_N], s2[MAX_N], virus[MAX_N];
int n1, n2, nv;
int NextCommonPrefix[MAX_N][ALPHABET_SIZE];
int List1[ALPHABET_SIZE][MAX_N], List2[ALPHABET_SIZE][MAX_N];
int List1Size[ALPHABET_SIZE], List2Size[ALPHABET_SIZE];
bool dp[MAX_N][MAX_N][MAX_N][MAX_N];
ppp Last[MAX_N][MAX_N][MAX_N][MAX_N];

void ProceedVirus() {
    for (int i = 0; i < nv; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            char pref2[MAX_N];
            strncpy(pref2, virus, i);
            pref2[i] = 'A' + j;
            pref2[i + 1] = '\0';
            for (int x = i + 1; x >= 0; x--) {
                if (strncmp(pref2 + (i + 1 - x), virus, x) == 0) {
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
    for (int i = 0; i < n1; i++) {
        List1[s1[i] - 'A'][List1Size[s1[i] - 'A']++] = i;
    }
    for (int i = 0; i < n2; i++) {
        List2[s2[i] - 'A'][List2Size[s2[i] - 'A']++] = i;
    }
    ProceedVirus();
    ppp Default = {{-1, -1}, {-1, -1}};
    memset(dp, false, sizeof(dp));
    memset(Last, 0, sizeof(Last));

    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j][1][NextCommonPrefix[0][s1[i] - 'A']] = true;
            } else {
                dp[i][j][0][0] = true;
            }
        }
    }

    for (int x = 1; x < fmin(n1, n2); x++) {
        for (int i = 0; i < n1 - 1; i++) {
            for (int j = 0; j < n2 - 1; j++) {
                for (int y = 0; y < nv; y++) {
                    if (!dp[i][j][x][y]) continue;
                    for (int z = 0; z < ALPHABET_SIZE; z++) {
                        if (List1Size[z] == 0 || List1[z][List1Size[z] - 1] <= i) continue;
                        if (List2Size[z] == 0 || List2[z][List2Size[z] - 1] <= j) continue;
                        int i1 = List1[z][1 + (int)(upper_bound(List1[z], List1[z] + List1Size[z], i) - List1[z])];
                        int j1 = List2[z][1 + (int)(upper_bound(List2[z], List2[z] + List2Size[z], j) - List2[z])];
                        dp[i1][j1][x + 1][NextCommonPrefix[y][z]] = true;
                        Last[i1][j1][x + 1][NextCommonPrefix[y][z]] = (ppp){{i, j}, {x, y}};
                    }
                }
            }
        }
    }

    for (int x = fmin(n1, n2); x > 0; x--) {
        for (int y = 0; y < nv; y++) {
            for (int i = 0; i < n1; i++) {
                for (int j = 0; j < n2; j++) {
                    if (!dp[i][j][x][y]) continue;
                    int I = i, J = j, X = x, Y = y;
                    char result[MAX_N] = "";
                    int len = 0;
                    while (I != -1) {
                        result[len++] = s1[I];
                        ppp Token = Last[I][J][X][Y];
                        I = Token.first.first; J = Token.first.second;
                        X = Token.second.first; Y = Token.second.second;
                    }
                    for (int k = len - 1; k >= 0; k--) {
                        putchar(result[k]);
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
    Input();
    Solve();
    return 0;
}
