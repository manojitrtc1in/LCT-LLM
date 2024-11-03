#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000

typedef long long i64;
typedef long double ld;

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

const i64 Mod = 1000000007LL, INF = 1e9, LINF = 1e18;
const ld Pi = 3.141592653589793116, EPS = 1e-9, Gold = ((1+sqrt(5))/2);
i64 keymod[] = {1000000007LL, 1000000009LL, 1000000021LL, 1000000033LL};
i64 keyCount = sizeof(keymod) / sizeof(i64);

typedef struct {
    i64 s[MAX_SIZE];
    int top;
} Stack;

void init(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, i64 value) {
    stack->s[++stack->top] = value;
}

i64 pop(Stack *stack) {
    return stack->s[stack->top--];
}

i64 getbit(i64 s, int i) {
    return (s >> i) & 1;
}

i64 onbit(i64 s, int i) {
    return s | (1LL << i);
}

i64 offbit(i64 s, int i) {
    return s & (~(1LL << i));
}

int cntbit(i64 s) {
    int count = 0;
    while (s) {
        count += s & 1;
        s >>= 1;
    }
    return count;
}

void proceedVirus(i64 id1[][26], i64 nv, char *virus) {
    for (i64 i = 0; i < nv; i++) {
        for (i64 j = 0; j < 26; j++) {
            char pref2[MAX_SIZE];
            strncpy(pref2, virus, i);
            pref2[i] = 'A' + j;
            pref2[i+1] = '\0';
            for (i64 x = i + 1; x >= 0; x--) {
                if (strncmp(pref2 + i + 1 - x, virus, x) == 0) {
                    id1[i][j] = x;
                    break;
                }
            }
        }
    }
}

void input(char *s1, char *s2, char *virus, i64 *n1, i64 *n2, i64 *nv) {
    scanf("%s %s %s", s1, s2, virus);
    *n1 = strlen(s1);
    *n2 = strlen(s2);
    *nv = strlen(virus);
}

void solve(char *s1, char *s2, char *virus, i64 n1, i64 n2, i64 nv) {
    i64 id1[MAX_SIZE][26];
    proceedVirus(id1, nv, virus);
    
    i64 List1[26][MAX_SIZE], List2[26][MAX_SIZE];
    i64 List1Size[26] = {0}, List2Size[26] = {0};
    for (i64 i = 0; i < n1; i++) {
        List1[s1[i]-'A'][List1Size[s1[i]-'A']++] = i;
    }
    for (i64 i = 0; i < n2; i++) {
        List2[s2[i]-'A'][List2Size[s2[i]-'A']++] = i;
    }
    
    i64 dp[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {0};
    pii Default = {-1, -1};
    ppp Last[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE];
    for (i64 i = 0; i < n1; i++) {
        for (i64 j = 0; j < n2; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j][1][id1[0][s1[i]-'A']] = 1;
            } else {
                dp[i][j][0][0] = 1;
            }
        }
    }
    for (i64 x = 1; x < (n1 < n2 ? n1 : n2); x++) {
        for (i64 i = 0; i < n1 - 1; i++) {
            for (i64 j = 0; j < n2 - 1; j++) {
                for (i64 y = 0; y < nv; y++) {
                    if (!dp[i][j][x][y]) {
                        continue;
                    }
                    for (i64 z = 0; z < 26; z++) {
                        if (List1Size[z] == 0 || List2Size[z] == 0) {
                            continue;
                        }
                        i64 i1 = -1, j1 = -1;
                        for (i64 k = 0; k < List1Size[z]; k++) {
                            if (List1[z][k] > i) {
                                i1 = List1[z][k];
                                break;
                            }
                        }
                        for (i64 k = 0; k < List2Size[z]; k++) {
                            if (List2[z][k] > j) {
                                j1 = List2[z][k];
                                break;
                            }
                        }
                        if (i1 == -1 || j1 == -1) {
                            continue;
                        }
                        dp[i1][j1][x+1][id1[y][z]] = 1;
                        Last[i1][j1][x+1][id1[y][z]].first.first = i;
                        Last[i1][j1][x+1][id1[y][z]].first.second = j;
                        Last[i1][j1][x+1][id1[y][z]].second.first = x;
                        Last[i1][j1][x+1][id1[y][z]].second.second = y;
                    }
                }
            }
        }
    }
    for (i64 x = (n1 < n2 ? n1 : n2); x > 0; x--) {
        for (i64 y = 0; y < nv; y++) {
            for (i64 i = 0; i < n1; i++) {
                for (i64 j = 0; j < n2; j++) {
                    if (!dp[i][j][x][y]) {
                        continue;
                    }
                    i64 I = i, J = j, X = x, Y = y;
                    char s[MAX_SIZE];
                    int index = 0;
                    while (I != -1) {
                        s[index++] = s1[I];
                        ppp Token = Last[I][J][X][Y];
                        I = Token.first.first;
                        J = Token.first.second;
                        X = Token.second.first;
                        Y = Token.second.second;
                    }
                    s[index] = '\0';
                    printf("%s\n", s);
                    return;
                }
            }
        }
    }
    printf("0\n");
}

int main() {
    char s1[MAX_SIZE], s2[MAX_SIZE], virus[MAX_SIZE];
    i64 n1, n2, nv;
    input(s1, s2, virus, &n1, &n2, &nv);
    solve(s1, s2, virus, n1, n2, nv);
    return 0;
}
